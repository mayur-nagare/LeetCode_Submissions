class Solution {
public:
    
    void getSubset(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int start){
        
        ans.push_back(temp);
        for(int i = start; i< nums.size(); i++){
            temp.push_back(nums[i]);
            getSubset(nums, temp, ans, i+1);
            temp.pop_back();
        }
        //return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        getSubset(nums, temp, ans, 0);
        
        return ans;
    }
};