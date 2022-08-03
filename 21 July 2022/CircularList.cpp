#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class CircularList{
    Node *head =  NULL;
    Node *last = NULL;
    public:
    void append(int data){
        Node * nd = new Node(data);
        if(head == NULL){
            head = nd;
            last = nd;
            nd->next = head;
        }else{
            last->next = nd;
            last = nd;
            last->next = head;
        }
    }
    void appendLeft(int data){
        Node *tmp = head;
        Node *nd = new Node(data);
        if(head == NULL){
            head = nd;
            last = nd;
            last->next = head;
        }else{
            nd->next = head;
            head = nd;
            last->next = head;
        }
    }
    int delRight(){
        Node *tmp = head;
        int data;
        if(head== NULL){
            cout<<"No data in list";
            return -1;
        }else if(head == last){//for single data
            data = head->data;
            head = NULL;
            last = NULL;
        }else{
            while(tmp->next != last){
                tmp = tmp->next;
            }
            data = last->data;
            tmp->next = NULL;
            last = tmp;
            last->next = head;
        }
        return data;
    }
    int delLeft(){
        Node *tmp = head;
        int data;
        if(head== NULL){
            cout<<"No data in list";
            return -1;
        }else if(head == last){//for single data
            data = head->data;
            head = NULL;
            last = NULL;
        }else{
            data = head->data;
            head = head->next;
            tmp->next = NULL;
            last->next = head;
        }
        return data;
    }
    void show(){
        Node* tmp = head;
        if(head != NULL){
            cout<<"\n[ ";
            while(tmp != last){
                cout<< tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<last->data<<"]";
        }
    }
    void printFromLast(){
        if(last!=NULL){
            Node* tmp = last;
            cout<<"[ ";
            do{
                cout<< tmp->data<<" ";
                tmp = tmp->next;
            }while(tmp != last);
            cout<<"]";
        }
    }
};
int main(){
    CircularList cq;
    int ch,data;
    do{
        cout<<"\n1. Append\n2. Append Left\n3. Delete Left\n4. Delete Right\n5. Show \n6. Show from last\n7. Exit\n Your choice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter data: ";
                    cin>>data;
                    cq.append(data);
                    cq.show();
                    break;
            case 2: cout<<"Enter data: ";
                    cin>>data;
                    cq.appendLeft(data);
                    cq.show();
                    break;
            case 3: data = cq.delLeft();
                    if(data !=-1){
                        cout<<"Deleted  Data: "<<data;
                        cq.show();
                    }
                    break;
            case 4: data = cq.delRight();
                    if(data !=-1){
                        cout<<"Deleted Data: "<<data;
                        cq.show();
                    }
                    break;
            case 5: cq.show();
                    break;
            case 6: cq.printFromLast();
                    break;
            case 7: break;
        }
    }while (ch!=7);
    
}