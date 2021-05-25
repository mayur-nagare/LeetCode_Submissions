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
    void solve(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return ;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* front = st.top();
            st.pop();
            
            if(front -> left)
                solve(front -> left, res);
            
            res.push_back(front -> val);
            
            if(front -> right)
                solve(front -> right, res);
            
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        solve(root,res);
        int n = res.size();
        int l = 0;
        int r = n-1;
        
        while(l < r){
            if(res[l]+ res[r] == k) return true;
            
            else if(res[l]+ res[r] < k) l++;
            else if(res[l]+ res[r] > k) r--;
        }
        return false;
    }
};