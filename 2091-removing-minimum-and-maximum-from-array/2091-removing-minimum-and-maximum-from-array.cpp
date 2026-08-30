class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int n = A.size();

        int mini = min_element(A.begin(), A.end()) - A.begin();
        int maxi = max_element(A.begin(), A.end()) - A.begin();

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        int case1 = right + 1;
        int case2 = n - left;
        int case3 = (left + 1) + (n - right);

        return min({case1, case2, case3});
    }
};