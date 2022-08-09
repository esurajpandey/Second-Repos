#include<bits/stdc++.h>
using namespace std;
static int ct = 0;
int fabonacci(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    // if(dp[n] != -1){
    //     return dp[n];
    // }
    ct++;
    // return dp[n] = fabonacci(n-1,dp) + fabonacci(n-2,dp);
    return fabonacci(n-1,dp) + fabonacci(n-2,dp);
}

int main(){
    vector<int>dp(6,-1);
    cout<<fabonacci(5,dp);
    cout<<"\nTotal Time: "<<ct;
}