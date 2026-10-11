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
    void reorderList(ListNode* head) {
        ListNode* last = head;
        ListNode* slow = head;
        ListNode* fast = head;  
        int n = 0;
        while(fast && fast->next){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
            n+=2;
        }
        if(fast) n++;
        if(n > 1){
            last->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* start = head;
        ListNode* end = prev;
        for(int i = 0; i<n; i++){
            ListNode* temp;
                if(!end || !start) break;
                if(i%2 == 0){
                    temp = start->next;
                    start->next = end;
                    start = temp;
                }else{
                    temp = end->next;
                    end->next = start;
                    end = temp;
                }
            }
        }
    }
};
