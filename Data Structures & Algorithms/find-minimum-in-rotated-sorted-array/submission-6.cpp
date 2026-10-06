class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if((mid == 0 && nums[nums.size() - 1] >= nums[0]) 
            || (mid != 0 && nums[mid - 1] > nums[mid])){
                return nums[mid];
            }
            if(mid != 0 && nums[mid] < nums[right] && nums[mid] < nums[left]){
                right = mid - 1;
            }else if(nums[right] > nums[left]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return 0;
    }
};
