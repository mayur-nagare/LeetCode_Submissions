class Solution {
public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size())
//             return false;
        
//         int count1[26] = {0}, count2[26] = {0};
//         for(int i=0; i<s.size(); i++){
//             count1[s[i] - 'a']++;
//             count2[t[i] - 'a']++;
//         }
        
//         for(int i = 0; i < 26; i++)
//             if(count1[i] != count2[i])
//                 return false;
//         return true;
//     }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         if (strs.size() == 0)
//             return ans;
        
//         for (int i=0; i<strs.size(); i++){
//             vector<string> temp;
//             temp.push_back(strs[i]);
            
//             for(int j=i+1; j<strs.size(); j++)
//                 if(isAnagram(temp[i], strs[j])){
//                     temp.push_back(strs[j]);
//                     sort(temp.begin(), temp.end());
//                     strs.erase(strs.begin() + j);
//                 }
              
//             ans.push_back(temp);
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
        
        unordered_map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            vector<string> temp;
            for(int j=0; j<i->second.size(); j++){
                temp.push_back(i->second[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};