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
    void addLeft(int data){
        if(head == NULL){
            head = new Node(data);
        }else{
            Node *nd = new Node(data);
            nd->next = this->head;
            this->head->prev = nd;
            this->head = nd;
        }
    }
    void addRight(int data){
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

    void insertAtX(int data,int i){
        Node *nd = new Node(data);
        if(head == NULL){
            head = nd;
        }else if(i == 1){
            return addLeft(data);
        }else{
            int n =0;
            Node *tmp = head,*tmp2;
            while(tmp){
                
                if(n==i){
                    tmp2->next = nd;
                    nd->prev = tmp2;
                    nd->next = tmp;
                    tmp->prev = nd;
                }
                n++;
                tmp2 = tmp;
                tmp = tmp->next;
            }
        }
    }
    bool delLeft(){
        if(head == NULL){
            return false;
        }else if(head->next == NULL){//if there is only one element
            head = NULL;
            return true;
        }else{
            Node *tmp = head;
            head = head->next;
            head->prev = NULL;
            delete(tmp);
            return true;
        }
    }
    
    bool delRight(){
        Node *tmp = head;
        if(head == NULL){
            return false;
        }else if(head->next == NULL){//if there is only one element
            head = NULL;
            return true;
        }else{
            while (tmp->next->next){
                tmp = tmp->next;
            }
            tmp->next = NULL; 
            return true;           
        } 
    }

    bool delAtX(int i){
        if(head == NULL){
            return false;
        }else if(i == 1){
            return delLeft();
        }else{
            int n =0;
            Node *tmp = head,*tmp2;
            while(tmp){
                n++;
                if(n==i){
                    tmp2->next = tmp->next;
                    //if last index
                    if(tmp->next != NULL){
                        tmp->next->prev = tmp2;
                    }   
                }
                tmp2 = tmp;
                tmp = tmp->next;
            }

        }
        return false;
    }
    void show(){
        Node *tmp =  this->head;
        cout<<"[ ";
        while(tmp){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"]"<<endl;
    }
};
int main(){
    LinkedList l;
    l.addRight(25);
    l.addRight(36);
    l.addRight(35);
    l.show();
    cout<<"at X\n";
    l.insertAtX(55,3);
    l.show();
}
