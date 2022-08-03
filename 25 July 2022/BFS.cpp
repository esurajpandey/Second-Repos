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

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

void levelOrder(Node *root){
    queue<Node*> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        } 
        if(curr->right!= NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    int data;
    int ch;
    do{
        cout<<"\n1. Insert\n2. Height\n3. Level Order Traversal\n4. Exit\nYour Choice: ";
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
            case 2: cout<<"\nHeight of tree : "<<height(root);
                    break;
            case 3: cout<<"\nLevel Order Traversal :\n";
                    levelOrder(root);
                    break;
        }
    }while(ch!=4);
    cout<<"\n\n";
}
