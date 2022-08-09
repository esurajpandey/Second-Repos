#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
}

int main(){
    vector<int> res =  {2,4,1};
    int k = 2;
    cout<<maxProfit(k,res);
}
