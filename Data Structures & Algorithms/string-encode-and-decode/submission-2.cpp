class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i<strs.size(); i++){
            ans += "#" + to_string(strs[i].size()) + "," + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        string val = "";
        vector<string> ans;
        for(int i = 0; i<=s.size(); i++){
            int length = 0;
            if((s[i] == '#' && 
                i < s.size() - 1 && 
                s[i + 1] >= 48 && 
                s[i + 1] <= 57
            )){
                i++;
                while(s[i] != ','){
                    length = length*10 + (s[i] - '0');
                    i++;
                }
                string substr = s.substr(i + 1, length);
                ans.push_back(substr);
            }
        }
        return ans;
    }
};
