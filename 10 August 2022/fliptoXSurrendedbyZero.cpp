#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i<0 or j<0 or i>=m or j>=n or board[i][j] != 'O') return;
        
        board[i][j] = '#';
        DFS(board, i-1, j, m, n);
        DFS(board, i+1, j, m, n);
        DFS(board, i, j-1, m, n);
        DFS(board, i, j+1, m, n);
    }
    
    
    void solve(vector<vector<char>>& mat) {
        int row = mat.size();
        if(row == 0) 
            return; 
        
        int col = mat[0].size();
        
        //Moving over firts and last column   
        for(int i=0; i<row; i++) {
             if(mat[i][0] == 'O')
                 DFS(mat, i, 0, row, col);
                 
             if(mat[i][col-1] == 'O')
                 DFS(mat, i, col-1, row, col);
        }
        
        //for first row and last row
        for(int j=0; j<col; j++) {
            if(mat[0][j] == 'O')
                DFS(mat, 0, j, row, col);
            if(mat[col-1][j] == 'O')
                DFS(mat, row-1, j, row, col);
        }
        
        //then just change
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(mat[i][j] == 'O')
                     mat[i][j] = 'X';
                if(mat[i][j] == '#')
                     mat[i][j] = 'O';
            }
    }
int main(){
    int r,c;
    cout<<"Enter row: ";
    cin>>r>>c;

    vector<vector<char>> mat(r,vector<char>(c,'0'));
    
    cout<<"\nEnter values: ";
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        cin>>mat[i][j];
      } 
    }

    solve(mat);
    cout<<endl;
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        cout<<mat[i][j];
      } 
      cout<<endl;
    }


}