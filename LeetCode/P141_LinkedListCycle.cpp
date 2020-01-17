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
    bool hasCycle(ListNode *head) {
        ListNode *jump = head;
        ListNode *move = head; 
        
        if (head == nullptr) return false;
        
        while(jump->next != nullptr && jump->next->next != nullptr &&move->next != nullptr){
            jump = jump->next->next;
            move = move->next;
            
            if (jump == move) return true;
        }
        return false;
    }
};