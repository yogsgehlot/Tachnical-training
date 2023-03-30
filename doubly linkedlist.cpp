#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;
};

void prependdoublylinkedlist (int data , node* &head)
{
    node* newnode= new node();
    newnode->data=data;
    newnode->next=head;
    newnode->prev=NULL;
    node* ptr= head;
    if(ptr==NULL)
    {
        head=newnode;
    }
    else
    {
        ptr->prev=newnode;
        head=newnode;
    }
}
void appenddoublylinkedlist(int data,node *&head)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    node*ptr = head;
    if(ptr==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        newnode->prev=ptr;
        ptr->next=newnode;
    }
}
 void deletenode(int position,node *&head) {
      if(position < 1) {
        cout<<"\nposition should be >= 1.";
      } else if (position == 1 && head != NULL) {
        node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
        if(head != NULL)
          head->prev = NULL;
      } else {
        node* temp = head;
        for(int i = 1; i < position-1; i++) {
          if(temp != NULL) {
            temp = temp->next;
          }
        }
        if(temp != NULL && temp->next != NULL) {
          node* nodeToDelete = temp->next;
          temp->next = temp->next->next;
          if(temp->next->next != NULL)
            temp->next->next->prev = temp->next;
          free(nodeToDelete);
        } else {
          cout<<"\nThe node is already null.";
        }
      }
    }

void specpos(node *&head,int data, int pos) {
      node* newnode = new node();
      newnode->data = data;
      newnode->next = NULL;
      newnode->prev = NULL;
      if(pos < 1) {
        cout<<"\nposition should be >= 1.";
      } else if (pos == 1) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
      } else {
        node* temp = head;
        for(int i = 1; i < pos-1; i++) {
          if(temp != NULL) {
            temp = temp->next;
          }
        }
        if(temp != NULL) {
          newnode->next = temp->next;
          newnode->prev = temp;
          temp->next = newnode;
          if(newnode->next != NULL)
            newnode->next->prev = newnode;
        } else {
          cout<<"\nThe previous node is null.";
        }
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
int main()
{
    node *head = NULL;
    while(1){

        system("CLS");
        cout<<"1. prepend doubly linkedlist: "<<endl;
        cout<<"2. append doubly linkedlist: "<<endl;
        cout<<"3. delete doubly linkedlist: "<<endl;
        cout<<"4. specific position doubly linkedlist: "<<endl;
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        switch(option)

        {


   case 1:

            cout<<"Enter Data : ";
            int data;
            cin>>data;
            prependdoublylinkedlist(data,head);
            display(head);
            break;
    case 2:
            cout<<"Enter Data : ";
            cin>>data;
            appenddoublylinkedlist(data,head);
            display(head);
            break;
    case 3:
            cout<<"Enter postion : ";
            int position;
            cin>>position;
            deletenode(position,head);
            display(head);
            break;
    case 4:
            cout<<"Enter postion : ";
            int pos;
            cin>>pos;
            cout<<"Enter data : ";
            cin>>data;
            specpos(head,data,pos);
            display(head);
            break;
        default:
            break;
        }
        system("PAUSE");
    }


}

