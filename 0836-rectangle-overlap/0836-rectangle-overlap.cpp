class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 coordinates
        int x1A = rec1[0];
        int y1A = rec1[1];
        int x2A = rec1[2];
        int y2A = rec1[3];

        // rec2 coordinates
        int x1B = rec2[0];
        int y1B = rec2[1];
        int x2B = rec2[2];
        int y2B = rec2[3];
        // Horizontally
        if (x1A >= x2B || x1B >= x2A) {
            return false;
        }
        // Vertically
        if (y1A >= y2B || y1B >= y2A) {
            return false;
        }
        // Overlapped
        return true;
    }
};