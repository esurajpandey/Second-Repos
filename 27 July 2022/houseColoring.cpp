#include<bits/stdc++.h>
using namespace std;
int small(int arr[]){
    return arr[0]<arr[1] && arr[0] <arr[2] ? arr[0] : arr[1]<arr[2]?arr[1]:arr[2];
}
int index(int arr[],int val){
    int k;
    for(int i=0;i<3;i++){
        if(arr[i]==val){
            k = i;
        }
    }
    return k;
}


int main(){
    int arr[][3] = {{17,2,17},{16,3,5},{5,1,2}};
    int sum =0;

    int sm = small(arr[0])
    int ind = index(arr[0],sm);

    sum = sm;
    for(int i=1;i<3;i++){
        if(ind == index(arr[i],small(arr[i]))){
            sum += small(arr[i]);
        }else{
            for(j=0;j<3;j++){
                if(j != ind ){
                    
                    sum = sum + 
                }
            }
        }
    }
}