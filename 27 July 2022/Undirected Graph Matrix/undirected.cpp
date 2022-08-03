#include<bits/stdc++.h>>
using namespace std;


int main{
    int v,e;
    cin>>v>>e;
    int graph[v+1][e+1];
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}