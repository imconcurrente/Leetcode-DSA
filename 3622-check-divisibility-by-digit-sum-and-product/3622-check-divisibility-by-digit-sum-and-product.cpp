class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp = n;
        while (temp > 0) {
            int rem = temp % 10;
            sum += rem;
            prod *= rem;
            temp /= 10;
        }
        return (n % (sum + prod) == 0);
    }
};