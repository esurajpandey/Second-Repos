#include<bits/stdc++.h>
using namespace std;
void flip(int n){
    int bits = (int)log2(n)+1;
    cout<<(((1 << bits) - 1) ^ n)<<endl;
}

// void print(int *arr,int n){
//     for(int i=0;i<n;i++){
//         cout<<" "<<arr[i];
//     }
//     cout<<endl;
// }

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
    for(int i=len-1;i>=0;i--){
        int p = pow(2,exp++);
        dec = dec + bin[i]*p;
    }
    return dec;
}

int toSwapBit(int n){
    int bin[100];
    int len = toBinary(bin,n);
    int j=0;
    int a[100];
    
    print(bin,len);
    cout<<endl;
    for(int i= len-1;i>=0;i--){
        a[j++] = bin[i];
    }

    for(int i=0;i<len-1;i=i+2){
        int t = a[i];
        a[i] = a[i+1];
        a[i+1]= t;
    }
    print(a,len);
    return toDecimal(a,len);
}

int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    
    cout<<"After flip: "<<toSwapBit(n);
    return 0;
}