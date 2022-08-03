/*
input :- CNEEATRWBOSRLK
Rows  :- 3

Output:- CABLENETWORKERS
*/
#include<bits/stdc++.h>
using namespace std;
void solve(string str,int n){
    if(n==1){
        cout<<str;
        return;
    }
    string res[n];
    int down = 0; //0--going down  1--going up
    int row = 0;
    for(int i=0;i<str.length();i++){
        res[row] += str[i];

        if(row == n-1){// if last rows then go up
            down = 1;
        }
        if(row == 0){//if row is first then go down
            down = 0;
        }

        if(down == 0){
            row ++;
        }else{
            row--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[i];
    }
}
int main(){
    string str;
    cout<<"String : ";
    cin>>str;
    int row;
    cout<<"Rows:";
    cin>>row;
    solve(str,row);
}