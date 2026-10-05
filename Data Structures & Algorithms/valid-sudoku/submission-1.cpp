class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                for(int k = 0; k<9; k++){
                    if((board[i][j] != '.' && ((j != k && board[i][j] == board[i][k]) || 
                    (i != k && board[i][j] == board[k][j]))) ){
                        return false;
                    }
                }
                int row = i%3;
                int column = j%3;
                int count = 0;
                for(int a = 0; a<3; a++){
                    for(int b = 0; b<3; b++){
                        if(board[i][j] != '.' && board[i + a - row][j + b - column] == board[i][j]){
                            count++;
                        }
                    }
                }
                if(count > 1) return false;
            }
        }
        return true;
    }
};
