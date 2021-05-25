/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> u_map;
        queue<Node*> q;
        
        if(!node)
            return u_map[node];
        
        q.push(node);
        Node* new_node = new Node();
        
        new_node -> val = node -> val;
        u_map[node] = new_node;
        
        while(!q.empty()){
            
            Node* front = q.front();
            q.pop();
            
            vector<Node*> v = front -> neighbors;
            int n = v.size();
            for(int i=0; i< n; i++){
                if(u_map[v[i]] == NULL){
                    new_node = new Node();
                    new_node -> val = v[i] -> val;
                    u_map[v[i]] = new_node;
                    q.push(v[i]);
                    
                }
                u_map[front] -> neighbors.push_back(u_map[v[i]]);
            }
        }
        return u_map[node];
    }
};