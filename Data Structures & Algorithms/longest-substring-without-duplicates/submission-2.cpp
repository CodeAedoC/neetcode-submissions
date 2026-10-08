class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        unordered_map<char, int> check;
        for(int r = 0; r<s.size(); r++){
            if(check.contains(s[r])){
                l = max(l, check[s[r]] + 1);
            }
            check[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
