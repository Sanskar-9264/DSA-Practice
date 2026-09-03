class Solution {
public:

    bool issafe(vector<string> &board ,int col, int row ,int n){
        for(int i = 0 ; i<n;i++){//horizontal
            if(board[row][i] =='Q'){
                return false;
            }
        }
        for(int i = 0 ; i<n;i++){//vertical
            if(board[i][col] =='Q'){
                return false;
            }
        }
        for(int i = row ,j =col ; i>=0 && j>=0 ;i--,j--){//left daigonal
            if(board[i][j] =='Q'){
                return false;
            }
        }
        for(int i = row,j =col ; i>=0 && j<n ;i--,j++){//right daigonal
            if(board[i][j] =='Q'){
                return false;
            }
        }

        return true;
    }
    void nqueen(vector<string> &board ,vector<vector<string>>&ans, int row ,int n){
        if(row == n){
            ans.push_back({board});
            return;
        }
        for(int j = 0 ; j<n;j++){
            if (issafe(board,j,row,n)){
                board[row][j] = 'Q';
                nqueen(board,ans,row+1,n);
                board[row][j] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n,string(n,'.'));
        nqueen(board,ans,0,n);
        return ans;
    }
};