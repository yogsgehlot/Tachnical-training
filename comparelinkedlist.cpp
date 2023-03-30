#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
void prepend1(int data, node* &head1){
    node *newNode = new node();
    newNode->data = data;
    newNode->next = head1;
    head1 = newNode;

}
void prepend2(int data, node* &head2){
    node *newNode = new node();
    newNode->data = data;
    newNode->next = head2;
    head2 = newNode;

}
int IsSameLists(node* &head1, node* &head2)
{
    bool check=1;
    if(head1 == NULL && head2 == NULL)
        return 1;
    if(head1 == NULL || head2 == NULL)
        return 0;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data!=head2->data)
        {
            check=0;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return check;
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
    node *head1 = NULL;
    node *head2 = NULL;
    while(1){

        cout<<"1. Prepend 1 "<<" //";
        cout<<"2. Prepend 2"<<" //";
        cout<<"3. Check if same linked list"<<" //";
        cout<<"Any other number to exit"<<endl;
        int option;
        cin>>option;
        int data;
        switch(option)

        {
        case 1:
            cout<<"Enter Data : ";
            cin>>data;
            prepend1(data,head1);
            display(head1);
            break;
        case 2:
            cout<<"Enter Data : ";
            cin>>data;
            prepend2(data,head2);
            display(head2);
            break;
        case 3:
            cout<<"Linked List 1 : "<<endl;;
            display(head1);
            cout<<"Linked List 2 : "<<endl;;
            display(head2);
            cout<<"Output : "<<IsSameLists(head1, head2)<<endl;
            break;
        default:
            break;
        }
    }
}
