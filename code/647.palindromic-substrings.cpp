class Solution {
public:
    int countSubstrings(string s) {
        int cnt=s.length(),j,n=s.length();
    for(int i=1;i<s.length();i++){
        if(s[i-1]==s[i]){
            j=0;
            while(((i+j)<n && (i-1-j)>=0) && (s[i-1-j]==s[i+j])){
                cnt++;j++;
            }
        }
        if((i<(n-1)) && (s[i-1]==s[i+1])){
            j=1;
            while(((i-j)>=0 && (i+j)<n) && (s[i-j]==s[i+j])){
                cnt++;j++;
            }
        }
    }
    return cnt;
    }
};