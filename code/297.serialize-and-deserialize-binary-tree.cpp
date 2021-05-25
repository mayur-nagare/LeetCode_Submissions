/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "x";
        return to_string(root -> val) + " " + serialize(root -> left) + " " + serialize(root -> right);
        
    }
    
    TreeNode* splitString(stringstream &ss){
        string word;
        if(!(ss >> word))
            return NULL;
        
        if(word == "x")
            return NULL;
        
        TreeNode* node = new TreeNode(stoi(word));
        node -> left = splitString(ss);
        node -> right = splitString(ss);
        
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return splitString(ss);
            
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));