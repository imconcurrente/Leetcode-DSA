class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int evenMoves = (start[0]+start[1])%2; // same color
        int oddMoves = (target[0]+target[1])%2; // opp color
        if(evenMoves == oddMoves) return true;
        else return false;
    }
};