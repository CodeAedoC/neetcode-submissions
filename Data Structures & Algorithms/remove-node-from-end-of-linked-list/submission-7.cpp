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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int k = 0;
        while (fast && fast->next) {
            fast = fast->next->next;
            k += 2;
        }
        if (fast) k++;
        if (k - n == 0) {
            return head->next;
        } 
        ListNode* pointer = head;
        for (int i = 0; i < k - 1; i++) {
            if((i + 1) == (k - n)){
                pointer->next = pointer->next->next;
            }
            pointer = pointer->next;
        }
        return head;
    }
};
