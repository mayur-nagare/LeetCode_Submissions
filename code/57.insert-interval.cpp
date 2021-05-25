class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0, n = intervals.size();
        vector<int> temp = newInterval;
        
        while(i < n && intervals[i][1] < newInterval[0]) answer.push_back(intervals[i++]);
        
        while(i < n && intervals[i][0] <= newInterval[1]){
            
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i++][1]);
        }
        answer.push_back(temp);
        
        while(i < n) answer.push_back(intervals[i++]);
        
        return answer;
    }
};