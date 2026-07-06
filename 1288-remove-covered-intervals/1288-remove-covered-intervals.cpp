class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        for(int i=0; i<intervals.size(); i++){
            bool isCovered = false;
            for(int j=0; j<intervals.size(); j++){
                if(i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]){
                    isCovered = true;
                    break;
                }
            }
            if(!isCovered){
                count++;
            }
        }
        return count;
    }
};