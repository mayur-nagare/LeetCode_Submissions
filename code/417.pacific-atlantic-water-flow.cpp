class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int rows = heights.size(), cols = heights[0].size();
        if( rows == 0 || cols == 0)
            return ans;
        
        vector<vector<bool>>pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>>atlantic(rows,vector<bool>(cols,false));
        
        //DFS
        for(int i=0; i< cols; i++){
            dfs(heights, 0, i, INT_MIN, pacific);
            dfs(heights, rows - 1, i, INT_MIN, atlantic);
        }
        
        for(int i=0; i< rows; i++){
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, cols -1, INT_MIN, atlantic);
        }
        
        //preparing result
        for(int i=0; i< rows; i++){
            for(int j=0; j< cols; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }    
        } 
        return ans;
    }
    
    
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean){
            if(i < 0 || i>= ocean.size() || j < 0 || j>= ocean[0].size()) 
                return;
            if(heights[i][j] < prev || ocean[i][j])
                return;
            ocean[i][j] = true;
            for(auto d : dir){
                dfs(heights, i+d[0], j+d[1], heights[i][j], ocean);
            }  
        }
};