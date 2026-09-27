class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> valCount;
        for(int num: nums){
            if(!valCount.contains(num)){
                valCount[num] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};