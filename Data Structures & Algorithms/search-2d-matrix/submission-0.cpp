class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int iCol = 0;
        int iRow = 0;
        int jCol = mat[0].size() - 1;
        int jRow = mat.size() - 1;
        int col = mat[0].size() - 1;
        int row = mat.size();
        while(iCol <= jCol && iRow <= jRow){
            int midRow = iRow + (jRow - iRow)/2;
            int midCol = iCol + (jCol - jCol)/2;
            if(target == mat[midRow][midCol]){
                return true;
            }else if(target < mat[midRow][midCol]){
                if(midCol != 0){
                    jCol--;
                }else{
                    jCol = mat[0].size() - 1;
                    jRow--;
                }
            }else{
                if(midCol != mat[0].size() - 1){
                    iCol++;
                }else{
                    iCol = 0;
                    iRow++;
                }
            }
        }
        return false;
    }
};
