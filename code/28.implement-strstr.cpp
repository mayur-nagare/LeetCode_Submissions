class Solution {
public:
    int strStr(string haystack, string needle) {
        
//     if(haystack.length() == 0 || needle.length() > haystack.length())
//             return -1;
        
//        if(needle.length() == 0)
//             return 0;
        
//         for(int i=0; i< haystack.length() - needle.length(); i++){
//             int j;
//             for(j=0; j< needle.length(); j++)
//                 if(needle[j] != haystack[i + j])
//                     break;
            
//             if(j == needle.length())
//                 return i;
//         }
//         return -1;
        
        if(needle.length()==0)
            return 0;
        else if(needle.length() > haystack.length())
            return -1;
        int pos = haystack.find(needle);
        return pos;
    }
};


