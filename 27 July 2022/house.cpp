#include<iostream>
#include<math.h>
using namespace std;
int index(int arr[],int val){
    int k;
    for(int i=0;i<3;i++){
        if(arr[i]==val){
            k = i;
            break;
        }
    }
    return k;
}
int smallExcept(int arr[],int k){
    
    int val = arr[0];
    if(k==0) val = arr[1];
    else if(k==1) val = arr[0];
    else if(k==2) val = arr[1];

    for(int i=0;i<3;i++){
        if(i != k && arr[i]<val){
            val = arr[i];
        }
    }
    return val;
}
int main(){
    int arr[3][3] ;//= {{5,3,4},{4,9,3},{6,1,6}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum = 0;
    int sm = (arr[0][0]<arr[0][1] && arr[0][0] <arr[0][2]) ? arr[0][0] :( arr[0][1]<arr[0][2])?arr[0][1]:arr[0][2];

    int id = index(arr[0],sm);
    sum = sm;
    for(int i=1;i<3;i++){
        sm = smallExcept(arr[i],id);
        id = index(arr[i],sm);
        sum = sum + sm;
    }
    cout<<sum<<"\n\n";
}