/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int c =0;
        
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int count = q.size();
            c++;
            for(int i=1; i<= count; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node -> val);               
            
                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node -> right != NULL){
                    q.push(node -> right);
                }   
            }
            if(c%2 == 0)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
    
};