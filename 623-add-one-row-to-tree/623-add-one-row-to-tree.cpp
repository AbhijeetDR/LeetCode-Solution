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
    void f(TreeNode* root, int val, int depth){
        if(root == nullptr) return;
        if(depth-1 == 0){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            TreeNode* tempL = root->left;
            TreeNode* tempR = root->right;
            root->left = newLeft;
            root->right = newRight;
            newLeft->left = tempL;
            newRight->right = tempR;
            return;
        }
        f(root->left, val, depth-1);
        f(root->right, val, depth-1);
        
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        f(root, val, depth-1);
        return root;
    }
};