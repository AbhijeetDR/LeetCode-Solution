/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void swap(queue<Node*>& q1, queue<Node*> & q2){
        queue<Node*> tmp = q1;
        q1 = q2;
        q2 = tmp;
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        vector<int> so;
        if(root==nullptr) return ans;
        so.push_back(root->val);
        ans.push_back(so);
        so.clear();
        
        queue<Node*> q1, q2;
        q1.push(root);
        
        while(q1.size() != 0){
            Node* front = q1.front();
            q1.pop();
            
            for(int i =0 ; i < (front->children).size(); i++){
                Node* child = (front->children)[i];
                
                if(child != nullptr)q2.push(child);
                
                if(child!=nullptr) so.push_back(child->val);  
            }
            
            if(q1.size() == 0){
                if(so.size() != 0)ans.push_back(so);
                so.clear();
                q1 = q2;
                
                queue<Node*> q3;
                this->swap(q2, q3);
                
            }   
        }
        
        return ans;
        
        
    }
};