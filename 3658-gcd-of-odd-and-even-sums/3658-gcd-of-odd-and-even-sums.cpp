class Solution {
public:

    int gcd(int a, int b){
        while(b != 0){
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        if(n < 0) return 0;
        int sumOdd = n*n;
        int sumEven = n*(n+1);

        return gcd(sumOdd, sumEven);
    }
};