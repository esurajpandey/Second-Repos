#include<bits/stdc++.h>
using namespace std;
//flip
//one by one bit changing

//   10110
// ->01001
int complement(int num) {
    for(int i=1;i<=num;i*=2){
        num = num^i;
    }
    return num;
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"Complement: "<<complement(n)<<endl;
    return 0;
}