#include<iostream>
using namespace std;
int power(int a, int n){
    int ans = 1;
    while (n > 0) {
        int last_bit = (n & 1);
        
        //if its is not zero means we need multiplication to get result
        if (last_bit) {
            ans = ans * a;
        }
        //multiply with same number so it will reach to answer
        a = a * a;
        // Right shift
        n = n >> 1;//decreasing the value by 1
    }
    return ans;
}

int main(){
    int a,n;
    cout<<"Enter A: ";
    cin>>a;
    cout<<"Enter n: ";
    cin>>n;
    cout<<power(a,n)<<endl;
    return 0;
}