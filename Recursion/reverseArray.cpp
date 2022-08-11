#include<iostream>
using namespace std;

void reverse(int arr[],int l,int r){
    if(l>r) return;
    int t = arr[l];
    arr[l] = arr[r];
    arr[r] = t;
    reverse(arr,l+1,r-1);
}

void rev(int i,int arr[],int n){
    if(i<n/2){
        int t =  arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = arr[i];
        rev(i+1,arr,n);
    }
}
int main(){
    int arr[] = {4,5,3,15,8};
    for(int i: arr)
        cout<<i<<" ";
    rev(0,arr,5);
    cout<<endl;
    for(int i: arr)
        cout<<i<<" ";
}