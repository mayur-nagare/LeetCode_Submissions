class Solution {
public:
    int characterReplacement(string s, int k) {
//         if(s.size() == 0)
//             return 0;
        
//         int left=0, right=0, len=0;
//         while(right < s.size()){
            
//         }
        
        int maxCount = 0;
      int ans = 0;
      int n = s.size();
      vector <int> cnt(26);
      int j = 0;
      for(int i = 0; i < n; i++){
         cnt[s[i] - 'A']++;
         maxCount = max(maxCount, cnt[s[i] - 'A']);
         while(j <= i && i - j + 1 - maxCount > k){
            --cnt[s[j] - 'A'];
            j++;
         }
         ans = max(ans, i - j + 1);
      }
      return ans;
    }
};