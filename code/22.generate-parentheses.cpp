class Solution {
public:
    void backtrack(int open, int close, vector<string>& ans, string result){
        if(open <= 0 && close <= 0){
            ans.push_back(result);
            return ;
        }
        if(open > 0){
            backtrack(open - 1, close, ans, result + "(");
        }
        if(close > 0 && close > open)
            backtrack(open, close - 1, ans, result + ")");
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string result;
        
        if(n == 0)
            return ans;
        
        int open = n, close = n;
        
        backtrack(open, close, ans, result);
        
        return ans;
    }
};