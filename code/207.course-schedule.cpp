class Solution {
public:
    int n; // number of vertices
    vector<vector<int>> edges; // adjacency list of graph
    vector<bool> isVisited;
    vector<bool> isCurrentlyVisited;
    vector<int> sortedNodes;
        
    bool topologicalSort(int node) {
        isVisited[node] = true;
        isCurrentlyVisited[node] = true;
        for(int next_node : edges[node]){
            if(isCurrentlyVisited[next_node]){
                return false;
            }
            if(!isVisited[next_node] && !topologicalSort(next_node))
                return false;
        }
        sortedNodes.push_back(node);
        isCurrentlyVisited[node] = false;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        edges = vector<vector<int>>(numCourses, vector<int>());
        isVisited = vector<bool>(numCourses, false);
        isCurrentlyVisited = vector<bool>(numCourses, false);
        
        for(auto i : pre){
            edges[i[0]].push_back(i[1]);
        }
        for(int i=0; i< numCourses; i++){
            if(!isVisited[i]){
                if(topologicalSort(i) == false)
                    return false;
            }
        }
        return true;
    }
};