class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        set <int> srow;
        set <int> scol;
        for(int i=0; i< row; i++){
            for(int j=0; j< col; j++){
                if(matrix[i][j] == 0){
                    srow.insert(i);
                    scol.insert(j);
                }
            }
        }
        set<int>::iterator iter;
        for(iter = srow.begin(); iter != srow.end(); iter++)
        {
            for(int i=0; i < col; i++)
                matrix[*iter][i] = 0;
        }
        for(iter = scol.begin(); iter != scol.end(); iter++)
        {
            for(int i=0; i < row; i++)
                matrix[i][*iter] = 0;
        }
    }
};