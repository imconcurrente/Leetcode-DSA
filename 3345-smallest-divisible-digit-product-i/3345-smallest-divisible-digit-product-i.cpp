class Solution {
public:
    int product(int n){
        int prod = 1;
        while(n > 0){
            int remain = n % 10;
            prod *= remain;
            n /= 10; 
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int ans = n; ans <= 100; ans++){
            int prod = product(ans);
            if(prod % t == 0){
                return ans;
            }
        }
        return 0;
    }
};