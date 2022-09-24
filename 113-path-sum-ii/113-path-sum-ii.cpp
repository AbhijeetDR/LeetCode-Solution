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
    void trav(TreeNode* root, int cur, int tar, vector<vector<int>>&ans, vector<int>tmp){
        if(root->left == nullptr && root->right == nullptr){
            if(tar == cur + root->val){
                tmp.push_back(root->val);
                ans.push_back(tmp);
            }
            return;
        }
        
        tmp.push_back(root->val);
        if(root->left!=nullptr)trav(root->left, cur+root->val,tar, ans, tmp);
        if(root->right!=nullptr)trav(root->right,cur+root->val,tar, ans, tmp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        trav(root, 0,targetSum, ans, tmp);
        return ans;
        
    }
};