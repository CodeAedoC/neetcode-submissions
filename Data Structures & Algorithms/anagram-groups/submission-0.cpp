class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string, string>> sorted_pairs;
        for(string str: strs){
            string alt_str = str;
            sort(alt_str.begin(), alt_str.end());
            pair<string, string> sorted_pair = {alt_str, str};
            sorted_pairs.push_back(sorted_pair);
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());
        for(int i = 0; i<sorted_pairs.size(); i++){
            if(i == 0 || sorted_pairs[i].first != sorted_pairs[i - 1].first){
                vector<string> group;
                group.push_back(sorted_pairs[i].second);
                ans.push_back(group);
            }else{
                int n = ans.size() - 1;
                ans[n].push_back(sorted_pairs[i].second);
            }
        }
        return ans;
    }
};
