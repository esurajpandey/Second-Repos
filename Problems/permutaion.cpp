#include<bits/stdc++.h>
using namespace std;
string swap(string s,int l,int r){
    char ch[s.length()+1];
    strcpy(ch,s.c_str());
    char c = ch[l];
    ch[l] = ch[r];
    ch[r] = c;
    string str(ch);
    return str;
}
void permute(string s,int l,int r){
   if(l==r){
    cout<<s<<" ";
    return;
   }
   for(int i=l;i<=r;i++){
        s = swap(s,l,i);
        permute(s,l+1,r);
        s = swap(s,l,i);
   }
}

int main(){
    permute("abcd",0,3);
    return 0;
}