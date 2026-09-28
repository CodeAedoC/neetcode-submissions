class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> positions;
        for(int i = 0; i<nums.size(); i++){
            int find_num = target - nums[i];
            if(positions.contains(find_num)){
                vector<int> ans;
                ans.push_back(min(positions[find_num], i));
                ans.push_back(max(positions[find_num], i));
                return ans;
            }
            positions[nums[i]] = i;
        }
    }
};
