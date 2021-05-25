class Solution {
public:
    void dfs(int src, vector<vector<int>>& vec, vector<bool>& vis){
        if(vis[src]) return;
        
        vis[src] = true;
        for(auto i : vec[src])
            dfs(i, vec, vis);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size())
            return -1;
        
        vector<vector<int>> vec(n);
        
        int src, dest;
        for(int i=0; i<connections.size(); i++){
            src = connections[i][0];
            dest = connections[i][1];
            
            vec[src].push_back(dest);
            vec[dest].push_back(src);
        }
        int cnt = 0;
        
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vec, vis);
            }
        }
        
        return cnt -1;
        
    }
};