class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j = s.length();
        
        while(i< j){
            while(!isalnum(s[i]) && i < j) i++;
            while(!isalnum(s[j]) && i < j) j--;
            
            if(tolower(s[i]) != tolower(s[j])) return false;
            i += 1;
            j -=1;
        }
        
        return true;
    }
};