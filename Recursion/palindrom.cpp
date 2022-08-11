#include<iostream>
using namespace std;
bool isPalindrome(string ch,int idx){
    if(idx < ch.length()/2){
        int n = ch.length();
        if(ch[idx] != ch[n-idx-1]){
            return false;
        }
        isPalindrome(ch,idx+1);
        return true;
    }
}
int main(){
    cout<<isPalindrome("SUDAM",0)<<endl;
}