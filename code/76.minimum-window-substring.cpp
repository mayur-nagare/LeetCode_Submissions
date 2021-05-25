class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t)
            return s;
        if(s.length() == 1 && s!=t)
            return "";
        
        unordered_map<char, int> m;
        for(int x=0; x<t.size(); x++) m[t[x]]++;
        
        int left=0, right=0, ansLeft=0, ansRight=0;
        string ans="";
        bool flag=false;
        int len = s.size(), tLen = t.size();
        
        while(right< s.size()){
            char c = s[right];
            if(m.find(c) != m.end()){
                if(m[c] > 0) tLen -= 1;
                m[c]--;
            }
            
            while(tLen == 0 && left <= right){
                if( right - left + 1 <= len){
                    len = right - left + 1;
                    flag = true;
                    ansLeft = left;
                    ansRight = right;                    
                }
                
                if(left == right)
                    break;
                
                c = s[left];
                
                if(m.find(c) != m.end()){
                    m[c]++;
                    if(m[c] > 0) tLen += 1;
                }
                left += 1;
            }
            right += 1;
        }
        
        if(flag == false) return ans;
        else
            for(int i= ansLeft; i<= ansRight; i++)
                ans += s[i];
            
        return ans;
    }
};