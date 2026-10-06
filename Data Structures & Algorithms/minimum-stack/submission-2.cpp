class MinStack {
public:
    stack<int> st;
    stack<int> small;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(small.empty() || (!small.empty() && small.top() >= val)){
            small.push(val);
        }
    }
    
    void pop() {
        if(small.top() == st.top()){
            small.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return small.top();
    }
};
