#include<iostream>
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

void inOrder(Node *root){
    if(root!= nullptr){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void preOrder(Node *node){
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node){
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main(){
    int data;
    int ch;
    do{
        cout<<"\n1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Exit\nYour Choice: ";
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
            case 2: cout<<"\nIn-Order\n";
                    inOrder(root);
                    break;
            case 3: cout<<"\nPre-Order\n";
                    preOrder(root);
                    break;
            case 4: cout<<"\nPost-Order\n";
                    postOrder(root);
                    break;
        }
        
    }while(ch!=5);
    cout<<"\n\n";
}