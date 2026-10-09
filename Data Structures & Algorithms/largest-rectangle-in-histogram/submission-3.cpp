class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;
        for(int i = 0; i<heights.size(); i++){
            if(st.empty()) st.push({heights[i], i});
            if(heights[i] > st.top().first){
                st.push({heights[i], i});
            }else if(heights[i] < st.top().first){
                int idx = i;
                while(!(st.empty()) && heights[i] < st.top().first){
                    idx = st.top().second;
                    int area = st.top().first * (i - st.top().second);
                    maxArea = max(maxArea, area);
                    st.pop();
                }
                st.push({heights[i], idx});
            }
        }
        while(!st.empty()){
            int area = st.top().first * (heights.size() - st.top().second);
            maxArea = max(maxArea, area);
            cout << st.top().first << endl;
            st.pop();
        }
        return maxArea;
    }
};
