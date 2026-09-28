class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> positions;
        for(int i = 0; i<nums.size(); i++){
            if(positions.contains(target - nums[i])){
                vector<int> ans;
                ans.push_back(min(positions[target-nums[i]], i));
                ans.push_back(max(positions[target-nums[i]], i));
                return ans;
            }
            positions[nums[i]] = i;
        }
    }
};
