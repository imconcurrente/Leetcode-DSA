class Solution {
public:
    bool covered(int lStart, int lEnd, int rStart, int rEnd) {
        return rStart <= lStart && lEnd <= rEnd;
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int coveredCnt = 0;

        for (int i = 0; i < intervals.size(); i++) {
            for (int j = 0; j < intervals.size(); j++) {
                if (i == j)
                    continue;

                if (covered(intervals[i][0], intervals[i][1], intervals[j][0],
                            intervals[j][1])) {
                    coveredCnt++;
                    break;
                }
            }
        }

        return intervals.size() - coveredCnt;
    }
};