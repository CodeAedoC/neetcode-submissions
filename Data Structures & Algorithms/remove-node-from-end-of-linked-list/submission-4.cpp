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
        ListNode* slow = head;
        ListNode* fast = head;
        int k = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            k+=2;
        }
        if(fast) k++;
        ListNode* pointer = head;
        for(int i = 0; i<k - n - 1; i++){
            pointer = pointer->next;
        }
        if(k == 1) return nullptr;
        else if(k == 2){
            if(n == 1){
                pointer->next = nullptr;
                return pointer;
            }else{
                return pointer->next;
            }
        }else{
            if(k - n == 0){
                head = head->next;
                return head;
            }else if(n == 1){
                while(pointer->next){
                    if(!pointer->next->next){
                        pointer->next = nullptr;
                        break;
                    }
                    pointer = pointer->next;
                }
            }else{
                pointer->next = pointer->next->next;
            }
        }
        return head;
    }
};
