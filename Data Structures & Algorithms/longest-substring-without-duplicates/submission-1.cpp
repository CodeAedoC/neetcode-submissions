class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        unordered_set<char> check;
        for(int r = 0; r<s.size(); r++){
            int length = r - l + 1;
            if(!check.contains(s[r])){
                maxLength = max(length, maxLength);
                check.insert(s[r]);
            }else{
                check.erase(s[l]);
                r--;
                l++;
            }
        }
        return maxLength;
    }
};
