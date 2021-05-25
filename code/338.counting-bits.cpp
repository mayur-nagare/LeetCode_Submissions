class Solution {
public:
    unsigned int countSetBitsUtil(unsigned int x)
    {
        if (x <= 0)
            return 0;
        return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
    }
    
    
    vector<int> countBits(int num) {
        vector<int> ans;
        
        int bitCount = 0; // initialize the result
 
        for (int i = 0; i <= num; i++)
            ans.push_back(countSetBitsUtil(i));
        
        return ans;
    }
};