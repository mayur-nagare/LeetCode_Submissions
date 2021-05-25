class Solution {
public:
    
    void getSubset(vector<int> &nums, vector<int> &temp, set<vector<int>> &ans, int start){

        ans.insert(temp);
        for(int i = start; i< nums.size(); i++){
            temp.push_back(nums[i]);
            getSubset(nums, temp, ans, i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        getSubset(nums, temp, ans, 0);
        
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;

    
    }
};