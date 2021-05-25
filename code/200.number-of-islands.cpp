class Solution {
public:
    void dfs(vector<vector<char>>& mat, int x, int y, int row, int col){
        
        if(x < 0 || x >= row || y < 0 || y >= col || mat[x][y] != '1')
            return;
        
        mat[x][y] = '2';
        
        dfs(mat, x-1, y, row, col); //left
        dfs(mat, x+1, y, row, col); //right
        dfs(mat, x, y-1, row, col); //Top
        dfs(mat, x, y+1, row, col); // down
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int no_of_islands = 0;
        int row = grid.size(), col = grid[0].size();
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, row, col);
                    no_of_islands += 1;
                }
            }
        }
        
        
        return no_of_islands;
    }
};