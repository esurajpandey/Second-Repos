#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &mat,int i,int j,int m,int n){
    if(i<0 || j<0 || i>= m || j>=n || mat[i][j] != '0') {
        return;
    }
    mat[i][j] = '#';
    dfs(mat,i+1,j,m,n);//down
    dfs(mat,i-1,j,m,n);//up
    dfs(mat,i,j+1,m,n);//right
    dfs(mat,i,j-1,m,n);//left

}
void flip(vector<vector<char>> &mat,int r,int c){
    //first and last row
    for(int i=0;i<c;i++){
        if(mat[0][i] == '0') dfs(mat,0,i,r,c);
        if(mat[r-1][i] == '0') dfs(mat,r-1,i,r,c);
    }
    //first column and last
    for(int i=0;i<r;i++){
        if(mat[i][0] == '0') dfs(mat,i,0,r,c);
        if(mat[i][c-1] == '0') dfs(mat,i,c-1,r,c);
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == '0'){
                mat[i][j] = 'x';
            }
            if(mat[i][j]=='#'){
                mat[i][j] = '0';
            }
        }
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

    flip(mat,r,c);

    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        cout<<mat[i][j]<<" ";
      } 
      cout<<endl;
    }
}

