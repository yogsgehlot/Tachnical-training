#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* next;
};
void prepend(int data, node* &head1)
{
  node * newnod = new node();
  newnod -> data = data;
  newnod -> next = head1;
  head1 = newnod;
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
void join(node * &head , node* &head1)
{

   node* merg = head1;
  while(merg->next!=NULL)
    {
      merg=merg->next;
    }
  merg->next = head;
}
void display(node*head1)
{
  node*ptr =head1;
  while(ptr!=NULL)
    {
      cout<<ptr->data<<endl;
      ptr = ptr->next;
    }
}

int main()
{
  node*head1=NULL;
  node*head=NULL;
  while(1){

        system("CLS");
        cout<<"1. Append "<<endl;
        cout<<"2. Prepend "<<endl;
        cout<<"3. join"<<endl;
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        switch(option)

        {

    case 1:
            cout<<"Enter Data : ";
            int data;
            cin>>data;
            append(data,head1);
            display(head1);
            break;
    case 2:
            cout<<"Enter Data : ";
            cin>>data;
            prepend(data,head);
            display(head);
            break;
   case 3:
          join(head,head1);
            display(head1);
        default:
            break;
        }
        system("PAUSE");
    }
  return 0;
}
