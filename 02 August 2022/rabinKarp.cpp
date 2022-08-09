#include<bits/stdc++.h>
#define ll long long int
#define prime 3
using namespace std;

ll hashValue(string str,int n){
    ll res = 0;
    for(int i=0;i<n;i++){
        res += (ll)(str[i] * (ll)pow(prime,i));
    }
    return res;
}

ll reHash(string str,int oldIdx,int newIdx,ll oldHash,int patLength){

    ll res = oldHash - str[oldIdx];
    res /= prime;
    res += str[newIdx] * pow(prime,patLength-1);
    return res;
}

bool compare(string str1,string str2,int start1,int end1,int start2,int end2){
    if(end1-start1  != end2-start2){
        return false;
    }

    while(start1<= end1 && start2<=end2){
        if(str1[start1] != str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main(){
    string  str = "aabaacaabbaad";
    string pat = "aad";

    ll patHash = hashValue(pat,pat.length());
    ll strHash = hashValue(str,pat.length());

    for(int i=0;i<=str.length()-pat.length();i++){
        if(patHash == strHash && compare(str,pat,i,i+pat.length()-1,0,pat.length()-1)){
            cout<<i;
            return 0;
        }

        if(i< str.length()-pat.length()){
            strHash = reHash(str,i,i+pat.length(),strHash,pat.length());
        }
    }
    return 0;
}