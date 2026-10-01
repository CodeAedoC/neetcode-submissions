class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        int max_sequence = 0;
        for(int num:numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int length = 1;
                while(numSet.find(num + length) != numSet.end()){
                    length++;
                }
                max_sequence = max(max_sequence, length);
            }
        }
        return max_sequence;
    }
};
