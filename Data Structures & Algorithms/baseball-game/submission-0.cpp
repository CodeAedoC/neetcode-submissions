class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int total = 0;
        for(string operation: operations){
            if(operation == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
                total+=(a+b);
            }else if(operation == "C"){
                total -= st.top();
                st.pop();
            }else if(operation == "D"){
                total += 2*st.top();
                st.push(2*st.top());
            }else{
                total += stoi(operation);
                st.push(stoi(operation));
            }
        }
        return total;
    }
};