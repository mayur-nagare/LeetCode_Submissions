class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        for(int i=0; i< row; i++){
            for(int j=0; j< floor(row/2); j++){
                swap(matrix[j][i], matrix[row-1-j][i]);
            }  
        }
        for(int i=0; i< row; i++){
            for(int j= i+1; j< row; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};