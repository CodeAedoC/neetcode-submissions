class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int i = 1;
        int j = x/2;
        while(i <= j){
            int mid = (i + j)/2;
            if((x/mid)/mid >= 1){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return i - 1;
    }
};