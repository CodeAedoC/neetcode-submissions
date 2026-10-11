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
        vector<ListNode*> elements;
        while(head){
            elements.push_back(head);
            head = head->next;
        }
        int n = elements.size();
        int start = 1;
        int end = n - 1;
        ListNode* prev = elements[0];
        for(int i = 1; i<n; i++){
            if(i % 2 == 0){
                prev->next = elements[start];
                start++;
            }else{
                prev->next = elements[end];
                end--;
            }
            prev = prev->next;
            if(i == n - 1){
                prev->next = nullptr;
            }
        }
        
    }
};
