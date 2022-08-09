#include<bits/stdc++.h>
using namespace std;

int ways(int idx,vector<int> &coins,int T,vector<vector<int>> &dp){
    if(idx == 0){
        if(T % coins[0] == 0)
            return  T/coins[0];
        return 1e9;
    }
    if(dp[idx][T] != -1){
        return dp[idx][T];
    }
    
    int notTake =  0 + ways(idx-1,coins,T,dp);
    int take =  INT_MAX;
    if(coins[idx] <= T)
        take =  1 + ways(idx,coins,T - coins[idx],dp);
    return dp[idx][T] = max(take,notTake);
}

int main(){
    vector<int> coins = {1,2,3};
    int T = 7;
    vector<vector<int>>dp(coins.size(),vector<int>(T+1,-1));
    int ans = ways(coins.size()-1,coins,T,dp);
    if(ans >= 1e9){
        cout<<-1;
    }else{
        cout<<ans;
    }
}