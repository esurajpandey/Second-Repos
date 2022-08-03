#include<bits/stdc++.h>
using namespace std;
class undirected{
    int V;
    //array of list
    list<int> *l;
    public:
    undirected(int V){
        this->V = V;
        //creating list of V size
        l = new list<int>[V];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<"vertex"<<i<<"->";
            for(int nbr:l[i]){
                cout<<nbr<<",";
            }
        }
    }
};
int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    undirected g(n);
    int v,e;
    for(int i=0;i<n;i++){
       cout<<"Enter the vertex: ";
       cin>>v;
       cout<<"Enter the edges of vertex["<<v<<"]:";
       do{
        cin>>e;
        if(e<0){
            break;
        }
        g.addEdge(v,e);//adding the given edges.
       }while(e >= 0);
    }
    g.print();
}