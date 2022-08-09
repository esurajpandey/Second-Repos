#include<iostream>
using namespace std;
int MSB(int a){
    if(a==0)
      return 0;
    int c=1;
    while(a>0){
        a=a>>1;
        c=c*2;
    }
    return c/2;
}

int LSB(int a){
    int ans=0;
    int lsb=a&1;
    if(lsb>0)
    {
     ans=1;
    }
    return lsb;
}

int main()
{
    int a;
    cout<<"\nEnter number: ";
    cin>>a;
    cout<<"MSB value in Decimal: "<<LSB(a);
    cout<<"\nMSB value in Decimal: " <<MSB(a)<<endl;
}