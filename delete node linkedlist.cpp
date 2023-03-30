#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

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
void deletenode(node*&head, int data)

{
    if(head==NULL)
    {
        return;
    }
    node* ptr=head;
    if(data==ptr->data)
    {
        head=ptr->next;
        delete ptr;
    }
    else
    {
        node* prev=NULL;
        while(ptr->data!=data)
        {
            prev=ptr;
            ptr=ptr->next;

        }
        prev->next=ptr->next;
        delete ptr;
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
        cout<<"2. delete "<<endl;
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
                deletenode(head,data);
                display(head);
                break;
            default:
                break;

        }
        system("PAUSE");
    }
}
