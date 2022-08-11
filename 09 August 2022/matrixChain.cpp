#include<iostream>
#include<vector>
using namespace std;
int mcm(int i,int j,int arr[],vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int min = 1e9;
    for(int k=i;k<j;k++){
        int mult = arr[i-1] * arr[k] * arr[j] + mcm(i,k,arr,dp) + mcm(k+1,j,arr,dp);
        if(min > mult){
            min = mult;
        }
    }
    return dp[i][j]=min;
}
int main(){
    int arr[]= {10,20,30,40,50};
    int N = 5;
    vector<vector<int>>dp(N,vector<int>(N,-1));
    cout<<mcm(1,N-1,arr,dp);
    return 0;
}