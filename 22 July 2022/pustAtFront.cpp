#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node *prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node* appendLeft(Node *head,int data){
    if(head == NULL){
        head = new Node(data);
    }else{
        Node *nd = new Node(data);
        nd->next = head;
        head->prev = nd;
        head = nd;
    }
    return head;
}
Node* append(Node *l,int data){
    Node *tmp = l;
    Node *nd = new Node(data);
    if(l == NULL){
        l = nd;
    }else{
        while (tmp->next){
            tmp = tmp->next;
        }
        nd->prev = tmp->next;
        tmp->next = nd;
    }   
    return l; 
}
Node* pushAtFront(Node *head,int value){
    Node *ptr = head;
    Node *tmp;//for storing the previous one
    Node *node = NULL;//for node to insert ate first

    if(head->data == value){//if value is already at first;
        return head;
    }
    while(ptr != NULL){
        if(ptr->data == value){
            node = ptr;
            tmp->next = ptr->next;
            break;
        }
        tmp = ptr;
        ptr = ptr->next;
    }
    if(node != NULL && node->data == value){
        head = appendLeft(head,value);
        delete(node);
    }else{
        cout<<"Value is not found in list";
    }
    return head;
}
void show(Node *head){
    Node *tmp = head;
    cout<<"[ ";
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<"]"<<endl;
}
int main(){
    Node *l1= NULL;
    int data;
    int ch;
    do{
        cout<<"1. Insert item in list \n2. Push at front \n3. Exit\nYour choice : ";
        cin>>ch;
        switch(ch){
            case 1: 
                cout<<"\n[TO STOP ENTER NEGATIVE NUMBER]\nEnter data/s for list1:";
                do{
                    cin>>data;
                    if(data <0){
                        break;
                    }
                    l1 = append(l1,data);
                }while(data>=0);   
                cout<<"List : ";show(l1);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>data;
                l1 = pushAtFront(l1,data);
                cout<<"After pushing at front: ";
                show(l1);
                break;
            case 3:
                break;
        }
    }while(ch != 3);    
    cout<<"\n\n";
}