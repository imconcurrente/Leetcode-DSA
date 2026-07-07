class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        long long mult = 1;
        while(n != 0)
        {
            long long digit = n%10;
            if(digit != 0)
            {ans = ans + (digit*mult);
            mult *= 10;}

            sum += digit;
            
            n /= 10;
        }
        return ans*sum;
    }
};