#include<iostream>
#include<stack>
using namespace std;
template<class U>class List{
    class Node{
        public:
        U data;
        Node *next;
        Node *prev;
        Node(U data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };
    Node *head = NULL;
    public:
    //appending at the last
    void append(U data){
        Node *newNode = new Node(data);
        if(head== NULL){
            head= newNode;
        }else{
            Node *tmp = head;
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next = newNode;
            newNode->prev = tmp;
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

    bool isPalindrome(){
        stack<char> st;
        Node *slow= head;
        if(slow== NULL){return false;}
        while(slow){
            st.push(slow->data);
            slow = slow->next;
        }
        Node *tmp = head;
        while(tmp){
            if(tmp->data != st.top()){
                return false;
            }
            st.pop();
            tmp = tmp->next;
        }
        return true;
    }

    List<U> reverse(){
        List<U> l2;
        stack<U> st;
        Node *curr = head;
        while(curr){
            st.push(curr->data);
            curr = curr->next;
        }
        while(!st.empty()){
            char c = st.top();
            l2.append(c);
            st.pop();
        }
        return l2;
    }
};
int main(){
    int ch;
    char data;
    List<char> l;
    do{
        cout<<"\n1.Insert item \n2.Check palindrome\n3.Reverse\n4.Exit\nYour choice: ";
        cin>>ch;
        switch(ch){
            case 1: 
                cout<<"[To stop enter -ve number or [*]]Enter item/s : ";
                do{
                    cin>>data;
                    if(data <0 || data == '*'){break;}
                    l.append(data);
                }while(data>=0);
                l.print();
                break;
            case 2:
                if(l.isPalindrome()){
                    cout<<"\nList is palindrome."<<endl;
                }else{
                    cout<<"\nList is not palindrome.\n"<<endl;
                }
            case 3:
                l.print();
                l = l.reverse();
                l.print();
                break;
        }
    }while(ch!=4);
}