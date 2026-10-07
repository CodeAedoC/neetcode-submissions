class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> countS1;
        unordered_map<char, int> countS2;
        int count = 0;
        int maxCount = 0;
        for(char c: s1){
            countS1[c]++;
        }
        for(int i = 0; i<s2.size(); i++){
            if(countS1.contains(s2[i]) && countS2[s2[i]] < countS1[s2[i]]){
                countS2[s2[i]]++;
                count++;
                maxCount = max(count, maxCount);
            }else{
                countS2 = {};
                if(countS1.contains(s2[i])){
                    i = i - count;
                }
                count = 0;
            }
        }
        return maxCount == s1.size();
    }
};
