class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(i < 1000){
                cnt = 0; // no comma 
            }else if(i >= 1000 && i <= 100000){
                cnt += 1; // one comma 
            }
        }
        return cnt;
    }
};