/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr) return nullptr;
        ListNode* init = head;
        ListNode* cur = head;
        ListNode* end = head;
        while(end->next != nullptr){
                end = end->next;
        }
        
        while(head->next != nullptr){
            while(cur->next != nullptr){
                cur = cur->next;
            }
            while(head->next != cur){
                head=head->next;    
            }
            cur->next = head;
            head->next = nullptr;
            cur = init;
            head = init;
        }
        return end;
    }
};
