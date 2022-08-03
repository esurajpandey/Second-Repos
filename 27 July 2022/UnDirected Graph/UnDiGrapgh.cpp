#include<bits/stdc++.h>
using namespace std;
//undirected and with weight.
class Undirected_graph{
    map<int,list<int>> l;
    public:
    void addEdge(int v,int e){
        l[v].push_back(v);
        l[e].push_back(v);
    }
    void display(){
        for(int x:l){
            for(int y:)
        }
    }
}