class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> countS1;
        unordered_map<char, int> countS2;
        int matches = 0;
        for(int i = 0; i<s1.size(); i++){
            countS1[s1[i]]++;
            countS2[s2[i]]++;
        }
        for(int i = 0; i<26; i++){
            char c = 'a' + i;
            if(countS2[c] == countS1[c]) matches++;
        }
        for(int i = s1.size(); i<s2.size(); i++){
            if(matches == 26){
                return true;
            }
            countS2[s2[i]]++;
            if(countS1[s2[i]] == countS2[s2[i]]){
                matches++;
            }else if(countS1[s2[i]] + 1 == countS2[s2[i]]){
                matches--;
            }
            countS2[s2[i - s1.size()]]--;
            if(countS1[s2[i - s1.size()]] == countS2[s2[i - s1.size()]]){
                matches++;
            }else if(countS1[s2[i - s1.size()]] - 1 == countS2[s2[i - s1.size()]]){
                matches--;
            }
        }
        return matches == 26;
    }
};
