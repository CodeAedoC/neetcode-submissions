class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for(char letter: s){
            if(countS.count(letter)){
                countS[letter]++;
            }else{
                countS[letter] = 1;
            }
        }
        for(char letter: t){
            if(countT.count(letter)){
                countT[letter]++;
            }else{
                countT[letter] = 1;
            }
        }
        for(const auto& [letter, letterCount] : countS){
            if(letterCount != countT[letter]) return false;
        }
        return true;
    }
};
