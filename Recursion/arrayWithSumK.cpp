#include<bits/stdc++.h>
using namespace std;
void printF(int idx,int arr[],int sum,int n,int s,vector<int> &sub){
    if(idx == n){
        if(s == sum){
            for(auto it:sub){
                cout<<it<<" ";
            }
            cout<<endl;
        }  
        return;
    } 
    sub.push_back(arr[idx]);
    s = s+ arr[idx];
//non peak
    printF(idx+1,arr,sum,n,s,sub);
    sub.pop_back();
    s-=arr[idx];//remove from sum
    printF(idx+1,arr,sum,n,s,sub);
}
int main(){
    int n = 5;
    int arr[] = {1,2,3,5,10};
    int sum = 15;
    vector<int>sub;
    int s = 0;//finds the sum in each iteration
    printF(0,arr,sum,n,s,sub);
}