#include <bits/stdc++.h>
using namespace std;
 
int greyConverter(int n) {
    int res = n ^ (n >> 1);
    return res; 
}

int main(){
    int n;
    cout<<"\nEnter number: ";
    cin>>n;
    cout<<"Decimal value of grey Code: "<<greyConverter(n)<<endl; 
    return 0;
}
