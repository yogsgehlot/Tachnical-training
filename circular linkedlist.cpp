#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};
void circularInsert(int data,node *&head)
{
    node* newnode=new node();
    newnode->data=data;
    node*ptr = head;
    if(ptr==NULL)
    {
        head=newnode;
    }
    else{
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    }
    newnode->next=head;
}
void display(node* head)
{
    node* ptr=head;
    if(ptr!=NULL)
    {
      cout<<ptr->data<<endl;
      ptr=ptr->next;
    }
    while(ptr!=head)
    {
       cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int main() {
    node *head = NULL;
    while(1){

        system("CLS");
        cout<<"1. circularInsert "<<endl;
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter Data : ";
                int data;
                cin>>data;
                circularInsert(data,head);
                display(head);
                break;
            default:
                break;


        }
        system("PAUSE");

    }
}
