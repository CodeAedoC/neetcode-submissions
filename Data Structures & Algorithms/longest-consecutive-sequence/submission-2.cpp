class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        map<int, int> ordered_nums;
        for(int i = 0; i<nums.size(); i++){
            ordered_nums[nums[i]] = i;
        }
        int max_sequence = 1;
        int current_count = 1;
        for(const auto& [key, value]: ordered_nums){
            if(ordered_nums.contains(key + 1)){
                current_count++;
            }else{
                current_count = 1;
            }
            if(current_count > max_sequence) max_sequence = current_count;
        }
        return max_sequence;
    }
};
