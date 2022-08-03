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

class Queue{
    private: 
    Node *front = NULL;
    Node *rear = NULL;
    public:
    void enqueue(int data){
        Node *nd = new Node(data);
        if(rear == NULL){
            rear = nd;
            front = nd;
        }else{
            rear->next = nd;
            rear = rear->next;
        }
    }
    int dequeue(){
        int data;
        if(front == NULL){
            cout<<"Queue is empty";
            return -1;
        }else{
            data = front->data;
            front = front->next;
        }
        return data;
    }
    int peek(){
        if(front == NULL){
            cout<<"No data exist";
            return -1;
        }else{
            return front->data;
        }
    }
    void show(){
        Node *tmp =  front;
        cout<<"\n[ ";
        while(tmp){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"]"<<endl;
    }
};
int main(){
    Queue q;
    int ch;
    int data;
    do{
        cout<<"\n1. Enqueue\n2. Dequeue \n3. Front Value\n4. Show all\n5. Exit\nYour Choice: ";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"[TO STOP ENTER NEGATIVE NUMBER]\nEnter data/s :";
                do{
                    cin>>data;
                    if(data <0){
                        cout<<"Negative number found!";
                        break;
                    }
                    q.enqueue(data);
                }while(data>=0);
                q.show();
                break;
            case 2:
                data = q.dequeue();
                if(data != -1)
                    cout<<"Deleted data: "<<data;
                break;
            case 3: 
                data = q.peek();
                if(data != -1)
                    cout<<"Front data: "<<data;
                break;
            case 4:
                q.show();
                break;
            case 5:
                break;
        }

    }while(ch != 5);
    
}