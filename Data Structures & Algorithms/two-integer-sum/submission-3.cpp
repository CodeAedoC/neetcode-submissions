class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> positions;
        for(int i = 0; i<nums.size(); i++){
            int find_num = target - nums[i];
            if(positions.contains(find_num)){
                return {positions[find_num], i};
            }
            positions[nums[i]] = i;
        }
        return {};
    }
};
