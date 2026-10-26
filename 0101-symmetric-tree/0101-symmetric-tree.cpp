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
bool ismirror(TreeNode* left , TreeNode*right){
    if(left == nullptr && right == nullptr)return true;
    if(left == nullptr || right == nullptr)return false;
    if(left -> val != right -> val)return false;
    return ismirror(left -> left , right -> right)&&
           ismirror(left -> right , right -> left );
           
}
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)return true;
      return ismirror(root->left,root->right);
        
    }
};