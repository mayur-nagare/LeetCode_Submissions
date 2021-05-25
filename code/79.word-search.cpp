class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int i, int j) {
        
        if(word.length() == 0)
            return true;
        
        board[i][j] -= 65;
        
        if(j>0 && board[i][j-1] == word[0] && search(board, word.substr(1), i, j-1))
            return true;
        
        if(j<board[0].size()-1 && board[i][j+1] == word[0] && search(board, word.substr(1), i, j+1))
            return true;
        
        if(i>0 && board[i-1][j] == word[0] && search(board, word.substr(1), i-1, j))
            return true;
        
        if(i<board.size()-1 && board[i+1][j] == word[0] && search(board, word.substr(1), i+1, j))
            return true;
        
        board[i][j] += 65;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        
        for(int i=0; i< row; i++)
            for(int j=0; j< col; j++)
                if(board[i][j] == word[0] && search(board, word.substr(1), i, j))
                    return true;
        
        return false;
        
    }
};