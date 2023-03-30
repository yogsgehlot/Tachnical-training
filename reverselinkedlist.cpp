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
void reverselink(node* &head)
{
    node *ptr = head;
    if(ptr==NULL)
    {
        return;
    }

    node* prev = NULL;
    node* nxt = ptr->next;
    while(ptr->next!=NULL )
    {
        ptr->next = prev;
        prev = ptr;
        ptr = nxt;
        nxt = nxt->next;
    }
    ptr->next=prev;
    head=ptr;
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
        cout<<"1. prepend "<<endl;
        cout<<"2. reverselink "<<endl;
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        switch(option)

        {

    case 1:
            cout<<"Enter Data : ";
            int data;
            cin>>data;
            prepend(data,head);
            display(head);
            break;
    case 2:
            reverselink(head);
            display(head);
            break;
        default:
            break;
        }
        system("PAUSE");
    }
}
