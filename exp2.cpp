#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nxtptr = NULL;
    while (currptr != NULL)
    {
        nxtptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nxtptr;
    }
    head = prevptr;
}
int digit(node *&head)
{
    int digit = 0;
    node *currptr = head;
    while (currptr)
    {
        digit = digit * 10 + currptr->data;
        currptr = currptr->next;
    }
    return digit;
}

void finalhead(node *&head, int sum)
{
    int d = 0;
    while (sum != 0)
    {
        d = sum % 10;
        sum /= 10;
        insert(head, d);
    }
}
int main()
{
    node *head = NULL;
    insert(head, 7);
    insert(head, 1);
    insert(head, 5);
    display(head);

    node *head1 = NULL;
    insert(head1, 5);
    insert(head1, 9);
    insert(head1, 2);
    cout << endl;
    display(head1);
    cout << endl;
    reverse(head);
    cout << "revresed linked list ";
    display(head);
    cout << endl;
    int num1 = digit(head); // first linked list digit
    cout << "Converted number is num1:" << digit(head);
    cout << endl;
    reverse(head1);
    display(head1);
    cout << endl;
    int num2 = digit(head1); // secoond linked list digit

    cout << "Next convertd number num2:" << digit(head1);
    cout << endl;
    int sum = num1 + num2;
    cout << "the nuber is " << sum;
    node *head2 = NULL; // third head for new linked list
    cout << endl;
    finalhead(head2, sum);

    cout << "final linked list: ";
    display(head2);

    return 0;
}