class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] <= nums[right]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        int min = left;
        if(target <= nums[nums.size() - 1]){
            right = nums.size() - 1;
        }else{
            left = 0;
            right = min - 1;
        }
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
