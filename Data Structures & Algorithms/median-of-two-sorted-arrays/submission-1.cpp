class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> small = nums2;
        vector<int> big = nums1;
        if(nums1.size() < nums2.size()){
            small = nums1;
            big = nums2;
        }
        int total = nums1.size() + nums2.size();
        int half = (total + 1)/2;
        int l = 0;
        int r = small.size();

        while(l <= r){
            int i = (l + r)/2;
            int j = half - i;
            int smallLeft = i > 0 ? small[i - 1] : INT_MIN;
            int smallRight = i < small.size() ? small[i] : INT_MAX;
            int bigLeft = j > 0 ? big[j - 1] : INT_MIN;
            int bigRight = j < big.size()  ? big[j] : INT_MAX;
            if(smallLeft <= bigRight && bigLeft <= smallRight){
                if(total%2 == 0){
                    return (max(smallLeft, bigLeft) + min(smallRight, bigRight)) / 2.0;
                }else{
                    return max(smallLeft, bigLeft);
                }
            }else if(smallLeft > bigRight){
                r = i - 1;
            }else{
                l = i + 1;
            }
        }
        return -1;
    }
};
