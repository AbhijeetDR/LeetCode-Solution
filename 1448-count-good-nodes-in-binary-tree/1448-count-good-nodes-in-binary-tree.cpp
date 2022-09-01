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
private:
    int bfs(TreeNode* root, int maxi){
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, maxi});
        while(q.size()){
            pair<TreeNode*, int> front = q.front();
            q.pop();
            if((front.first) -> val >= front.second){
                ans++;
            }
            
            TreeNode* l = (front.first)-> left;
            TreeNode* r = (front.first)->right;
            if(l!=nullptr){
                q.push({l, max(front.first -> val, front.second)});
            }
            
            if(r!=nullptr){
                q.push({r, max(front.first -> val, front.second)});
            }
        }
        return ans;
    }
    
    
public:
    int goodNodes(TreeNode* root) {
        int ans = bfs(root, -1e4-1);
        return ans;
    }
};