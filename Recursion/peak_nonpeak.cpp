#include<bits/stdc++.h>
using namespace std;
void printF(int idx,int arr[],int n,vector<int> &sub){
    if(idx == n){
        for(auto it:sub){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    
    sub.push_back(arr[idx]);
    printF(idx+1,arr,n,sub);
    sub.pop_back();
    printF(idx+1,arr,n,sub);
}
int main(){
    int n = 3;
    int arr[] = {3,1,2};
    vector<int>sub;
    printF(0,arr,n,sub);
}