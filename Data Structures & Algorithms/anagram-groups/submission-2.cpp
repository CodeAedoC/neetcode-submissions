class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> sorted_strings;
        for(string s: strs){
            vector<int> count(26, 0);
            string sorted;
            for(char c: s){
                count[c - 'a']++;
            }
            sorted += to_string(count[0]);
            for(int i = 1; i<26; i++){
                sorted += "," + to_string(count[i]);
            }
            sorted_strings[sorted].push_back(s);
        }
        for(pair p: sorted_strings){
            ans.push_back(p.second);
        }
        return ans;
    }
};
