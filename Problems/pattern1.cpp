#include<iostream>
using namespace std;
int main(){
    int n,i,j,k;
    cout<<"Enter value of n:";
    cin>>n;

    for(i=1;i<=n;i++){
        for(int s=1;s<=n-i;s++){//space
            cout<<" ";
        }
        for(j=1;j<=i;j++){
            cout<<j;
        }
        for(k=i-1;k>=1;k--){
            cout<<k;
        }
        cout<<endl;
    }
    //for last 3
    for(i=1;i<=n-1;i++){
        //space
        for(int s=1;s<=i;s++){
            cout<<" ";
        }
        for(j=1;j<n-i;j++){
            cout<<(j*j)-1;
        }
        for(k=j;k>=1;k--)
            cout<<(k*k)-1;
        cout<<endl;
    }
}