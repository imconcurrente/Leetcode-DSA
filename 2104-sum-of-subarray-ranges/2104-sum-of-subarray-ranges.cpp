class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int largest = arr[i], smallest = arr[i];
            for(int j = i+1; j < n; j++){
                largest = max(largest, arr[j]);
                smallest = min(smallest, arr[j]);

                sum += (long long)largest - smallest;
            }
        }
        return sum;
    }
};