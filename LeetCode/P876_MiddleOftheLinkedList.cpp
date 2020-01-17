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
    ListNode* middleNode(ListNode* head) {
        ListNode* counter = head;
        ListNode* mid = head;
        int cnt = 0;
        
        while(counter){
            counter = counter->next;
            cnt++;
        }
        
        cnt = (cnt /= 2);
        
        while(cnt--){
            mid = mid->next;
        }
        return mid;
    }
};