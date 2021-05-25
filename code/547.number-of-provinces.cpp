class Solution {
public:
    int count;
    vector<int> parent;
    int findCircleNum(vector<vector<int>>& isConnected) {
                
        int n = isConnected.size();
        count = n;
        parent.resize(n);
        
        for(int i=0; i<n; ++i){
            parent[i] = i;
        }
        
        int parI =0, parJ= 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(isConnected[i][j] == 1)
                    unions(i, j);
                
            }
        }
        return count;
    }
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unions(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            parent[rootx] = rooty;
            count -= 1;
        }
    }
};