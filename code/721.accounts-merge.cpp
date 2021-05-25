class Solution {
public:
    void dfs(unordered_map<string, set<string>>& graph, set<string>& visited, string s, vector<string>& ans){
        ans.push_back(s);
        visited.insert(s);
        
        for(string str: graph[s]){
            if(visited.find(str) == visited.end()){
                dfs(graph, visited, str, ans);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, set<string>> graph;
        vector<vector<string>> result;
        
        for(auto acc : accounts){
            for(int i= 1; i < acc.size(); i++){
                graph[acc[i]].insert(acc[1]);
                graph[acc[1]].insert(acc[i]);   
            }
        }
        
        set<string> visited;
        for(auto ls : accounts){
            if(visited.find(ls[1]) == visited.end()){
                vector<string> ans;
                dfs(graph, visited, ls[1], ans);
                sort(ans.begin(), ans.end());
                ans.insert(ans.begin(),ls[0]);
                result.push_back(ans);
            }
        }
        return result;
    }
};