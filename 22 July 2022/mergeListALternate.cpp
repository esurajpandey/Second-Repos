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
Node* mergeWithoutExtraSpace(Node *head1,Node *head2){
    bool flag = false;
    Node *ptmp = head1;
    Node *qtmp = head2;
    if (head1 == NULL){
        return head1;
    }  
    if (head2 == NULL){
        return head2;
    }
    Node *p,*q;
    while(ptmp && qtmp){
        p = ptmp->next;
        q = qtmp->next;

        qtmp->next = p;
        ptmp->next = qtmp;

        ptmp = p;
        qtmp = q;
    }
    return ptmp;
}
Node* mergerAlternate(Node *head1,Node *head2){
    Node *l1 = head1,*l2 = head2;
    Node *res =  NULL;
    bool t1= false;
    res = append(res,l1->data);
    t1 = true;
    l1 = l1->next;

    while(l1 != NULL && l2 != NULL){
        if(!t1){
            res = append(res,l1->data);
            l1 = l1->next;
            t1 = true;
        }else{
            res = append(res,l2->data);
            l2 = l2->next;
            t1 = false;
        }
    }

    //if any list has extra data left
    while(l1 != NULL || l2 != NULL){
        if(l1!= NULL){
            res = append(res,l1->data);
            l1 = l1->next;
        }

        if(l2){
            res = append(res,l2->data);
            l2 = l2->next;
        }
    }
    return res;
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
    Node *l1= NULL,*l2= NULL;
    int data;
    cout<<"[TO STOP ENTER NEGATIVE NUMBER]\nEnter data/s for list1:";
    do{
        cin>>data;
        if(data <0){
            break;
        }
        l1 = append(l1,data);
    }while(data>=0);   
    show(l1);
    cout<<"[TO STOP ENTER NEGATIVE NUMBER]\nEnter data/s for list2:";
    do{
        cin>>data;
        if(data <0){
            break;
        }
        l2 = append(l2,data);
    }while(data>=0); 
    show(l2);
    cout<<"After merging the list:--- \n\n";
    Node *res = mergerAlternate(l1,l2);
    show(res);
    cout<<"\n\n";
}