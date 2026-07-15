class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n < 0) return 0;
        int sumOdd = n*n;
        int sumEven = n*(n+1);

        return __gcd(sumOdd, sumEven);
    }
};