class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        map<int, int> mpp;
        int rank = 1;

        for(int i = 0; i < temp.size(); i++){
            if(mpp.find(temp[i]) == mpp.end()){
                mpp[temp[i]] = rank;
                rank++;
            }
        }

        for(int i = 0; i <  arr.size(); i++){
            temp[i] = mpp[arr[i]];
        }
        return temp;
    }
};