#include<bits/stdc++.h>
using namespace  std;

int solve(int idx,int W,int wt[],int val[]){
    if(idx == 0){
        if(wt[idx] < W){
            return val[idx];
        }
        return 0;
    }
    
    int notTake = 0 + solve(idx-1,W,wt,val);
    
    int take = INT_MIN;
    if(wt[idx] < W){
        take = val[idx] +  solve(idx-1,W-wt[idx],wt,val);
    }
    
    return max(take,notTake);
}
int main() {
    int W  = 3;
    int wt[] = { 4,5,6};
    int val[] =  {1,2,3};
    int n = 3;
    cout<<solve(n-1,W,wt,val);
}
