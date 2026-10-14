/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* first = head;
        unordered_map<Node*, Node*> copyMap;
        while(head){
            copyMap[head] = new Node(head->val);
            head = head->next;
        }
        for(const auto& [original, copy]: copyMap){
            copy->next = original->next ? copyMap[original->next] : nullptr;
            copy->random = original->random ? copyMap[original->random] : nullptr;
        }
        return copyMap[first];
    }
};
