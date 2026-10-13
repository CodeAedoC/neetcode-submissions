class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];
        for(int i = 1; i<n; i++){
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
            maxRight[n - i - 1] = max(maxRight[n - i], height[n - i - 1]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int val = min(maxLeft[i], maxRight[i]) - height[i];
            if(val > 0) ans += val;
        }
        return ans;
    }
};
