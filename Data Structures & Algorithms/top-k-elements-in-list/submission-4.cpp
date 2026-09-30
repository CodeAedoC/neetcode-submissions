class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> numCount;
        vector<vector<int>> bucket(n + 1);
        vector<int> ans;
        for(int num: nums){
            numCount[num]++;
        }
        for(const auto& [key, value]: numCount){
            bucket[value].push_back(key);
        }
        int x = 0;
        for(int i = n; i > 0; i--){
            bool brk = false;
            for(int j = 0; j < bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                x++;
                if(x == k){
                    brk = true;
                }
            }
            if(brk) break;  
        }
        return ans;
    }
};
