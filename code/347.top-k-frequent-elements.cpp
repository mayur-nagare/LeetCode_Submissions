class Solution {
public:
    
    struct compare{
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            if(p1.second == p2.second)
                return p1.first < p1. first;
            
            return p1.second < p2.second;
        }
    };   
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        unordered_map<int, int> umap;
        for(int i=0; i< nums.size(); i++)
            umap[nums[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(umap.begin(), umap.end());
        
        vector<int> ans;
        
        for(int i= 1; i <= k; i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};