class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<nums.size(); i++){
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = nums.size() - 1;
            int target = -(nums[i]);
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]);
                    ans.push_back(triplet);
                    left++;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                }else if(sum > target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return ans;
    }
};
