class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numCount;
        vector<int> ans;
        for(int num: nums){
            numCount[num]++;
        }
        vector<pair<int, int>> sortedNums(numCount.begin(), numCount.end());
        sort(sortedNums.begin(), sortedNums.end(), [](const auto& a, const auto&b){
            return a.second > b.second;
        });
        for(int i = 0; i<k; i++){
            ans.push_back(sortedNums[i].first);
        }
        return ans;
    }
};
