class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        if (k == 1)
            return n;

        int ans = 0;
        int oddPre = -1, evenPre = -1;

        for (int i = 0; i < n; i++) {

            bool oddCheck = checkOddPalin(s, i, k, oddPre);
            bool evenCheck = checkEvenPalin(s, i, k, evenPre);

            if (oddCheck && evenCheck) {
                int end = min(oddPre, evenPre);

                i = end;
                oddPre = end;
                evenPre = end;

                ans++;
            } else if (oddCheck) {
                i = oddPre;
                evenPre = oddPre;

                ans++;
            } else if (evenCheck) {
                i = evenPre;
                oddPre = evenPre;

                ans++;
            }
        }

        return ans;
    }

    bool checkOddPalin(string& s, int i, int k, int& pre) {
        int l = i, r = i;
        int n = s.size();

        while (l > pre && l >= 0 && r < n && s[l] == s[r]) {

            if (r - l + 1 >= k) {
                pre = r;
                return true;
            }

            l--;
            r++;
        }

        return false;
    }

    bool checkEvenPalin(string& s, int i, int k, int& pre) {
        int n = s.size();

        if (i + 1 >= n)
            return false;

        int l = i, r = i + 1;

        while (l > pre && l >= 0 && r < n && s[l] == s[r]) {

            if (r - l + 1 >= k) {
                pre = r;
                return true;
            }

            l--;
            r++;
        }

        return false;
    }
};