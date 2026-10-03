class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token: tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                st.push(stoi(token));
            }else{
                int i = st.top();
                st.pop();
                int j = st.top();
                st.pop();

                if(token == "+"){
                    i = i + j;
                }else if(token == "-"){
                    i = j - i;
                }else if(token == "*"){
                    i = i * j;
                }else if(token == "/"){
                    i = j / i;
                }
                st.push(i);
            }
        }
        return st.top();
    }
};
