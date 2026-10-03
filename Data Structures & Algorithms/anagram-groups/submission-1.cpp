class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> sorted_strings;
        for(string s: strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            sorted_strings[sortedS].push_back(s);
        }
        for(pair sorted_string: sorted_strings){
            ans.push_back(sorted_string.second);
        }
        return ans;
    }
};
