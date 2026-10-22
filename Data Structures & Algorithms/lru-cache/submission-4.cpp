class LRUCache {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v, ListNode* n = nullptr, ListNode* p = nullptr) : val(v), next(n), prev(p) {}
    };

    int space;
    ListNode* left;
    ListNode* right;
    unordered_map<int, int> key_values;
public:
    LRUCache(int capacity) {
        space = capacity;
        left = new ListNode(-1, nullptr, nullptr);
        right = new ListNode(-1, nullptr, left);
        left->next = right;
    }
    
    int get(int key) {
        if(key_values.contains(key)){
            ListNode* temp = left;
            while(temp->val != key){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            left->next->prev = temp;
            temp->next = left->next;
            left->next = temp;
            temp->prev = left;
            return key_values[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        ListNode* temp = left;
        while(temp->val != key && temp != right){
            temp = temp->next;
        }
        if(temp == right){
            ListNode* cur = new ListNode(key, left->next, left);
            if(space == 0){
                key_values.erase(right->prev->val);
                right->prev->prev->next = right;
                right->prev = right->prev->prev;
                space++;
            }
            left->next->prev = cur;
            left->next = cur;
            space--;
        }else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            left->next->prev = temp;
            temp->next = left->next;
            left->next = temp;
            temp->prev = left;
        }
        key_values[key] = value;
    }
};
