class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long min_k = 1000000000;
        int max_val = 0;
        for(int n: piles){
            max_val = max(max_val, n);
        }
        int left = 1;
        int right = max_val;
        while(left <= right){
            long long mid = left + (right - left)/2;
            long long k = 0;
            for(int pile: piles){
                k += pile/mid;
                if(pile%mid > 0) k++;
            }
            if(k <= h){
                min_k = min(min_k, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return min_k;
    }
};
