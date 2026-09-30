class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productWithNoZero = 1;
        int zeroCount = 0;
        for(int n:nums){
            if(n != 0){
                productWithNoZero *= n;
            }else{
                zeroCount++;
            }
        }
        if(zeroCount > 1){
            vector<int> zeroVec(nums.size(), 0);
            return zeroVec;
        }
        for(int i = 0; i<nums.size(); i++){
            if(zeroCount == 0){
                nums[i] = productWithNoZero/nums[i];
            }else{
                if(nums[i] != 0){
                    nums[i] = 0;
                }else{
                    nums[i] = productWithNoZero;
                }
            }
        }
        return nums;
    }
};
