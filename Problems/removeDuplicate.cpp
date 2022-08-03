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
class LinkedList{
    public: Node *head = NULL;
    void append(int data){
        Node *tmp = head;
        Node *nd = new Node(data);
        if(head == NULL){
            head = nd;
        }else{
            while (tmp->next){
                tmp = tmp->next;
            }
            nd->prev = tmp->next;
            tmp->next = nd;
        }    
    }
    void show(){
        Node *tmp =  this->head;
        cout<<"\n[ ";
        while(tmp){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"]\n";
    }
    void removeDuplicate(){
        Node *tmp1,*tmp2,*d;
        tmp1 = head;
        while(tmp1->next!= NULL && tmp1!= NULL){
            tmp2 = tmp1->next;
            while(tmp2 != NULL){
                if(tmp1->data == tmp2->data){
                    d = tmp2;

                }else{
                    
                }
            }
        }
    } 
};
int main(){
    LinkedList l;
    int data;
    cout<<"[TO STOP ENTER NEGATIVE NUMBER]\nEnter data/s :";
    do{
        cin>>data;
        if(data <0){
            break;
        }
        l.append(data);
    }while(data>=0);
    cout<<"List Items : ";
    l.show();
    l.removeDuplicate();
    l.show();
}