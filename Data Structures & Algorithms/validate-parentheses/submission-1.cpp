class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {{'[',']'},{'{','}'},{'(',')'}};
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(!st.empty() && brackets[st.top()] == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
