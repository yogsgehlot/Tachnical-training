#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
void prepend(int data, node* &head){
    node *newNode = new node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;

}
void append(int data,node *&head)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    node*ptr = head;
    if(ptr==NULL)
    {
        head=newnode;
    }
    else{
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    }
}
void display(node* head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
       cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main() {
    node *head = NULL;
    while(1){

        system("CLS");
        cout<<"1. Append "<<endl;
        cout<<"2. Prepend "<<endl;
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        switch(option)

        {

    case 1:
            cout<<"Enter Data : ";
            int data;
            cin>>data;
            append(data,head);
            display(head);
            break;
    case 2:
            cout<<"Enter Data : ";
            cin>>data;
            prepend(data,head);
            display(head);
            break;
        default:
            break;
        }
        system("PAUSE");
    }
}
