#include<bits/stdc++.h>
using namespace std;
int toBinary(int *bin,int n){
    int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    return i;
}
int toDecimal(int *bin,int len){
    int  dec=0;
    int exp = 0;
    for(int i=0;i<len;i++){
        int p = pow(2,exp++);
        dec = dec + bin[i]*p;
    }
    return dec;
}
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main(){
    int arr[100];
    int n;
    cout<<"Enter number: ";
    cin>>n;
    int len = toBinary(arr,n);
    int k=0;
    int grey[len];

    for(int i=0;i<len-1;i++){
        grey[i] = arr[i] ^ arr[i+1];
    }
    grey[len-1] = arr[len-1];

    // print(grey,len);
    cout<<toDecimal(grey,len)<<endl;
}


