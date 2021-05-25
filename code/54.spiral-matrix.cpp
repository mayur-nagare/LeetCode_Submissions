class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLeft = 0;
        int rowRight = matrix[0].size() -1;
        int colUp = 0;
        int colBot = matrix.size() -1;
        int dir = 0, i;
        
        vector<int> ans;
        while(rowLeft <= rowRight && colUp <= colBot){
            //left to right top
            if(dir == 0){
                for(i= rowLeft; i <= rowRight; i++){
                    ans.push_back(matrix[colUp][i]);
                }
                colUp += 1;
            }
            else if(dir == 1){
                //top to bottom on rightmost
                for(i=colUp ; i <= colBot; i++){
                    ans.push_back(matrix[i][rowRight]);
                }
                rowRight -= 1;
            }
            else if(dir == 2){
                //right to left bottom
                for(i=rowRight; i>= rowLeft; i--){
                    ans.push_back(matrix[colBot][i]);
                }
                colBot -= 1;
            }
            else if(dir == 3){
                for(i= colBot; i>= colUp; i--){
                    ans.push_back(matrix[i][rowLeft]);
                }
                rowLeft += 1;
            }
            dir = (dir+1)%4;
                        
        }    
        return ans;
    }
};