#include<iostream>
#include<math.h>
using namespace std;
#define S 50

//stored in reversed order
int toBinary(int *bin,int n){
    int binaryNum[16];
    int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    return i;
}

int toDecimal(int bin[],int len){
    int  dec=0;
    int exp = 0;
    for(int i=len-1;i>=0;i--){
        int p = pow(2,exp++);
        dec = dec + bin[i]*p;
    }
    return dec;
}

int toGreyCode(int bin[],int len){
    int k = 0; //index of grey code
    int grey[len];
    for(int i= 0;i<len;i++){
        int a = bin[i];      //taking last element in a
        int b = bin[i+1];      //taking second last element in b

        if((a && !b) || (!a && b)){
            grey[k++] = 1;
        }else{
            grey[k++] = 0;
        }
    }
    for(int i=0;i<k;i++){
        cout<<grey[i];
    }

    return toDecimal(grey,k);
}
int main(){
    int bin[8];
    int n =  toBinary(bin,14);
    // for(int i=n-1;i>=0;i--){
    //     cout<<bin[i];
    // }
    int br[]={1,1,0,1,0,1};
    //cout<<endl<<toDecimal(br,6);
    toGreyCode(br,5);
    cout<<endl;
}