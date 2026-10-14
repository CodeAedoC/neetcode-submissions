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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = 1;
        ListNode* start = head;
        ListNode* prev = nullptr;
        while(n != left){
            prev = start;
            start = start->next;
            n++;
        }
        ListNode* meh = prev;
        ListNode* first = start;
        while(n != right + 1){
            ListNode* temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
            n++;
        }
        first->next = start;
        if(left == 1) return prev;
        else{
            meh->next = prev;
            return head;
        }
    }
};