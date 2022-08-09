#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
void dfs(vector<vector<int>> &mat, int i, int j, int pre,vector<int>arr,vector<vector<int>>visited) {
    if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || visited[i][j] == 1 ||  pre >= mat[i][j])
    {
        if(arr.size()>ans.size()){
            ans.clear();
            ans.assign(arr.begin(), arr.end()); 
        }
        return;
    }

    visited[i][j] = 1;
    arr.push_back(mat[i][j]);
    dfs(mat, i, j - 1, mat[i][j], arr,visited);
    dfs(mat, i, j + 1, mat[i][j],arr,visited);
    dfs(mat, i - 1, j, mat[i][j],arr,visited);
    dfs(mat, i + 1, j, mat[i][j],arr,visited);

    arr.pop_back();
    visited[i][j] = 0;
}

void longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxVal = 0;
    vector<int> row(matrix[0].size(), 0);
	vector<vector<int>> visited(matrix.size(), row) ;

    vector<int> arr;
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
        {
            dfs(matrix, i, j, -1, arr, visited);
        }
    cout<<"result:";
    for(auto i:ans){
        cout<<" " <<i;
    }
    cout<<endl;

}
int main(){
    vector<int> res;
    int r,c;
    cout<<"Enter row: ";
    cin>>r;
    cout<<"Enter column: ";
    cin>>c;

    vector<int>row(c,0);
    vector<vector<int>> arr(r, row) ;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    longestIncreasingPath(arr);
}