#include<bits/stdc++.h>
using namespace std;

template <class U> class BST{
    public:
    class Node{
        public:
        U   data;
        Node *left;
        Node *right;
        Node(U data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    public:
    Node *root = NULL;
    void preOrder(Node *root){
        if (root == NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(Node *root){
        if (root == NULL){
            return;
        } 
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void postOrder(Node *root){
        if (root == NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
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

    Node* insert(Node *root,U data){
        Node *newNode = new Node(data);
        if(root==NULL){
            root = newNode;
        }
        else if(data >  root->data){
            root->right = insert(root->right,data);
        }else if(data< root->data){
            root->left = insert(root->left,data);
        }else{
            cout<<"Duplicate values are not allowed";
        }
        return root;
    }
    Node* nearestCommonAncestor(Node *root,int n1,int n2){
        if(root == NULL){
            return root;
        }
        if(root->data == n1 || root->data == n2){
            return root;
        }

        Node *leftLCA = nearestCommonAncestor(root->left,n1,n2);
        Node *rightLCA = nearestCommonAncestor(root->right,n1,n2);

        if(leftLCA != NULL && rightLCA != NULL){
            return root;//the real answer
        }
        //return 
        return leftLCA != NULL ? leftLCA : rightLCA;
    }
};

int main(){
    BST<int> b;
    int ch;
    int data;
    int n1,n2;
    do{
        cout<<"\n\n1. Insert\n2. Find height\n--------DFS--------\n3. In-Order Traversal\n4. Pre-Order Traversal\n5. Post-Order Traversal\n--------BFS--------\n6. Level Order Traversal\n\n7. Nearest Common Ancestor of two node\n8. Vertical Order traversal\n9. Exit\nYour Choice: ";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Insert values [STOP by -ve value]";
                do{
                    cin>>data;
                    if(data<0){//if data is less than zero the insertion will be stop
                        break;
                    }
                    b.root = b.insert(b.root,data);
                }while(data>0);
                break;
            case 2: cout<<"\nHeight of tree : "<<b.height(b.root);
                    break;
            case 3: cout<<"\nIn-Order\n";
                    b.inOrder(b.root);
                    break;
            case 4: cout<<"\nPre-Order\n";
                    b.preOrder(b.root);
                    break;
            case 5: cout<<"\nPost-Order\n";
                    b.postOrder(b.root);
                    break;
            case 6: cout<<"\nLevel Order Traversal :\n";
                    b.levelOrder(b.root);
                    break;
            case 7: cout<<"Enter the first Node:";
                    cin>>n1;
                    cout<<"Enter the second Node:";
                    cin>>n2;
                    if(b.nearestCommonAncestor(b.root,n1,n2) == NULL){
                        cout<<"There is no common Ancestor for given node.";
                    }else{
                        cout<<"Common Ancestor :"<<b.nearestCommonAncestor(b.root,n1,n2)->data;
                    }
                    break;
            case 8:
                cout<<"Work is in progress....";
                break;
            case 9: break;
        }
    }while(ch != 9);
    cout<<"\n\n";
}