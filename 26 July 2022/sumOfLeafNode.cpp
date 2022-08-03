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

int s = 0;
void summation(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        s +=root->data;
    }
    summation(root->left);
    summation(root->right);
}

void sumOfLeaf(Node *root,int& sum){
    if(root==NULL){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        sum +=root->data;
    }
    sumOfLeaf(root->left,sum);
    sumOfLeaf(root->right,sum);
}

void sumOfRootHavingOneChild(Node *root,int& sum){
    if(root==NULL){
        return;
    }
    if(root->left != nullptr && root->right == nullptr){
        sum +=root->data;
    }else if(root->left == nullptr && root->right != nullptr){
        sum +=root->data;
    }
    sumOfRootHavingOneChild(root->left,sum);
    sumOfRootHavingOneChild(root->right,sum);
}

int main(){
    int data;
    int ch;
    int n1,n2;
    int sum=0;//for storing the sum of leaf and root having one child
    do{
        cout<<"\n1. Insert\n2. Sum of Leaves Node\n3. Sum of root having one child\n4.Exit\nYour Choice: ";
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
                sumOfLeaf(root,sum);
                cout<<"Sum of leaves node: "<<sum;
                break;

            case 3:
                sum = 0; 
                sumOfRootHavingOneChild(root,sum);
                cout<<"Sum of root node having one child: "<<sum;
                break; 
        }
    }while(ch!=4);
    cout<<"\n\n";
}
