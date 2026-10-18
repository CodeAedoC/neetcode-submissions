class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> numsIndices;
      for(int i = 0; i<nums.size(); i++){
        if(numsIndices.contains(nums[i])){
            if(abs(i - numsIndices[nums[i]]) <= k){
                return true;
            }else{
                numsIndices[nums[i]] = i;
            }
        }else{
            numsIndices[nums[i]] = i;
        }
      }
      return false;
    }
};