class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> u_map;
        
        for(int i=0; i< graph.size(); i++){
            if(u_map.find(i) != u_map.end() || graph[i].empty())
                continue;
            
            u_map[i] = 0;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int vertex = q.front();
                q.pop();
                for(auto adj_vert : graph[vertex]){
                    if(u_map.find(adj_vert) != u_map.end()){
                        if(u_map[vertex] == u_map[adj_vert])
                            return false;
                    }else{
                        u_map[adj_vert] = !u_map[vertex];
                        q.push(adj_vert);
                    }
                    
                }
            }
        }
        return true;
    }
};