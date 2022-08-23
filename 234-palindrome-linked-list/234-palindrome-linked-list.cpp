/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* newhead = nullptr;
        ListNode* tmp = head;
        while(tmp != nullptr){
            ListNode* newNode = new ListNode(tmp->val);
            if(newhead == nullptr){
                newhead=newNode;
                
            }
            else{
                newNode->next = newhead;
                newhead =newNode;
            }
            tmp = tmp->next;
        }
        
        ListNode* tmp1 = head, *tmp2 = newhead;
        while(tmp1 != nullptr){
            if(tmp1->val != tmp2->val){
                return false;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return true;
        
    }
};