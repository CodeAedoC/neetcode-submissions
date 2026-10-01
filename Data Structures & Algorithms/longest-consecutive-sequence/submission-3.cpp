class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        set<int> ordered_nums(nums.begin(), nums.end());
        int max_sequence = 1;
        int current_count = 1;
        for(int key: ordered_nums){
            if(ordered_nums.find(key + 1) != ordered_nums.end()){
                current_count++;
            }else{ current_count = 1; }
            if(current_count > max_sequence) max_sequence = current_count;
        }
        return max_sequence;
    }
};
