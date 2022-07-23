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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = nullptr, * t = nullptr;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
           
            ListNode* newNode = new ListNode(sum%10);
            if(h == nullptr){
                h = newNode;
                t = h;
            }
            else{
                t->next = newNode;
                t = newNode;
            }
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            // cout << sum << " " << carry << "\n";
            
        }
        
        while(l1!= nullptr){
            int sum = l1->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            if(h == nullptr){
                h = newNode;
                t = h;
            }
            else{
                t->next = newNode;
                t = newNode;
            }
            l1 = l1->next;
            carry = sum/10;
        }
        
        while(l2!= nullptr){
            int sum = l2->val + carry;
            ListNode* newNode = new ListNode(sum%10);
            if(h == nullptr){
                h = newNode;
                t = h;
            }
            else{
                t->next = newNode;
                t = newNode;
            }
            l2 = l2->next;
            carry = sum/10;
        }
        
        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            t->next = newNode;
            t = newNode;
        }
        return h;
    }
};