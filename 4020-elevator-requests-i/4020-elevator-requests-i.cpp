class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0, elev = 0;
        for(int i = 0; i < requests.size(); i++){
            while(elev != requests[i]){
                if(elev < requests[i]){
                    elev++;
                    ans++;
                }else if(elev > requests[i]){
                    elev--;
                    ans++;
                }
            }
        }
        return ans;
    }
};