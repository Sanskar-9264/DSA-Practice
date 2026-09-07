class Solution {
public:
    bool issafe(vector<vector<char>>& board , int row , int col, int dig){
        //horizontal checking 
        for(int j = 0 ; j<9 ; j++){
            if(board[row][j] == dig){
                return false;
            }
        }

        //vertical checinkg
        for(int i = 0 ;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }

        //grid checking
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i =sr ; i <= sr+2 ;i++){
            for (int j = sc ; j<= sc+2 ;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }

        return true;
    }
    bool sudoku(vector<vector<char>>& board , int row , int col){

        int nextrow = row , nextcol = col+1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        //base case
        if(row == 9){
            return true;
        }
        //skip if already occupied
        if(board[row][col] != '.'){
            return sudoku(board , nextrow,nextcol);
        }

        //place the digit
        for(char dig = '1';dig<='9';dig++){
            if(issafe(board,row,col,dig)){
                board[row][col] = dig;
                if(sudoku(board , nextrow , nextcol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};