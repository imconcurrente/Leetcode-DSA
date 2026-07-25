class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0;
        int maxi2 = 0;
        while(n != 0)
        {
            int rem = n%10;
            if(rem >= maxi1)
            {
                maxi2 = maxi1;
                maxi1 = rem;
            }
            else maxi2 = max(maxi2, rem);
            n /= 10;
        }
        return maxi1 * maxi2;
    }
};