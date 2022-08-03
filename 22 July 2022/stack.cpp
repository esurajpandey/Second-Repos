#include<iostream>
using namespace std;
template <class U> class stack{
    class Node{
        public:
        U data;
        Node *next;
        Node(U data){
            this->data = data;
            this->next = NULL;
        }
    };
    Node *head = NULL;
    public:
    void push(U data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    U pop(){
        U data;
        if(head==NULL){
            return -1;
        }else{
            data = head->data;
            head = head->next;
        }
        return data;
    }
    U top(){
        if(head == NULL){
            return -1;
        }else{
            return head->data;
        }
    }
    void print(){
        cout<<"\n[ ";
        Node *tmp = head;
        while (tmp) {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"]\n"; 
    }
};

int main(){
    stack<int> s;
    s.push(25);
    s.push(45);
    s.push(65);
    s.print();
}