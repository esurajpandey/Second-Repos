//Nearest common ancestor
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

Node *root;
Node* insert(Node* root, int data){
    if (root == nullptr) {
        return new Node(data);
    }else if (data < root->data) {
        root->left = insert(root->left, data);
    }else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* LCA(Node *root,Node *n1,Node* n2){
    if(root==NULL){
        return root;
    }
    if(root->data==n1->data || root->data == n2->data){
        return root;
    }

    Node *llca = LCA(root->left,n1,n2);
    Node *rlca = LCA(root->right,n1,n2);
    if(llca != NULL && rlca != NULL){
        return root;
    }
    return llca!=NULL?llca:rlca;
}
int main(){
    int data;
    int ch;
    int n1,n2;
    do{
        cout<<"\n1. Insert\n2. Nearest common Ancestor \n3. Exit\nYour Choice: ";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Insert values [STOP by -ve value]";
                do{
                    cin>>data;
                    if(data<0){//if data is less than zero the insertion will be stop
                        break;
                    }
                    root = insert(root,data);
                }while(data>0);
                break;
            case 2: 
                cout<<"Enter the first Node:";
                cin>>n1;
                cout<<"Enter the second Node:";
                cin>>n2;
                Node *res = LCA(root,new Node(n1),new Node(n2));
                if(res == NULL){
                    cout<<"There is no common Ancestor for given node.";
                }else{
                    cout<<"Common Ancestor :"<<res->data;
                }
                break;
        }
    }while(ch!=3);
    cout<<"\n\n";
}
