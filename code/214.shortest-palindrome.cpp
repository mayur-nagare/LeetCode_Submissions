class Solution {
public:
    string shortestPalindrome(string s) {
        string ans = s;
        reverse(ans.begin(), ans.end());
        int len = 0;
        while( ans != s){
            s.insert(len, 1, ans[len]);
            ans.insert(ans.size()-len, 1, ans[len]);
            len++;
        }
        
        return ans;
    }
};

