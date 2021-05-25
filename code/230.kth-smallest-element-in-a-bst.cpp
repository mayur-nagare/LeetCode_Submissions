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
    void inord(TreeNode* root, int& val, int& k){
        if(!root)
            return ;
        else{
            
            inord(root -> left, val, k);
            --k;
            if (k == 0) {
                val = root->val;
                return;
            }
            inord(root -> right, val, k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int val = 0;
        inord(root, val, k);
        
        return val;
                
    }
};