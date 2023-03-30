#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
 int val;
 struct _Node *next;
}Node;

void print(Node*);
void reverse(Node*);
void printReverse(Node*);
int countOccurrence(Node*,int);
int countNodes(Node*);
int printSmallerItems(Node*);
int isCyclic(Node*);
int sum(Node*);          //recursive
int CountOccurrence(Node*,int); //recursive
Node *makeNode(int);
Node* locate(Node*,int);
Node* Locate(Node*,int); //recursive
Node* getMin(Node*);
Node* getMax(Node*);
Node* GetMin(Node*); //recursive
Node* append(Node*,Node**,int);
Node* insBeforeFirst(Node*,int);
Node* insAfterFirst(Node*,Node*,int);
Node* insBeforeLast(Node*,int);
Node* insAfterLast(Node*,int);
Node* rmvFirst(Node*,Node**);
Node* rmvLast(Node*,Node**);
Node* reverseList(Node*,Node**);
Node* insBefore(Node*,int,int);
Node* insAfter(Node*,Node*,int,int);
Node* rmvNode(Node*,Node**,int);
Node* clear(Node*);
Node* insertBefore(Node*,int,int); //recursive code
Node* insertAfter(Node*,Node*,int,int); //recursive code
Node* remvNode(Node*,Node**,int); //recursive code

void main()
{
 Node *start='\0',*last='\0',*nd='\0';
 int n;

 printf("\n");
 while(1)
 {
  printf("Enter a Number [0 to stop] : ");
  scanf("%d",&n);
  
  if(n==0) break;

  nd=makeNode(n);
  if(start=='\0')
   start=nd;
  else
   last->next=nd;
   last=nd;  
 }
 
 start=remvNode(start,&last,3);
 printf("\n\n");
 print(start);
}

Node *makeNode(int n)
{
 Node *nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

void print(Node *ptr)
{
 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
}

int countNodes(Node* ptr)
{
 int cnt=0;
 while(ptr)
 {
  cnt++;
  ptr=ptr->next;
 }
 return cnt;
}

Node* locate(Node* ptr,int n)
{
 while(ptr&&ptr->val!=n) ptr=ptr->next; 
 return ptr;
}

int countOccurrence(Node* ptr,int n)
{
 int cnt=0;
 
 while(ptr)
 {
  cnt=cnt+(ptr->val==n);
  ptr=ptr->next;
 }
 return cnt;
}

int printSmallerItems(Node *start)
{
 Node *ptr;
 float avg;
 int n;
 
 for(avg=n=0,ptr=start;ptr;ptr=ptr->next)
 {
  avg+=avg+ptr->val;
  n++;
 }
 avg/=n;
 printf("\nItems smaller than the Avg[%.2f] : ",avg);

 for(ptr=start,n=0;ptr;ptr=ptr->next)
 {
  if(ptr->val<avg)
  {
   printf("%d ",ptr->val);
   n++;
  }
 }
 return n;
}

int isCyclic(Node *ptr)
{
 Node *nxt;
 while(ptr)
 {
  nxt=ptr->next;
  if(ptr==nxt) return 1;
  ptr->next=ptr;
  ptr=nxt;
 }
 return 0;
}

void printReverse(Node* start)
{
 if(start==NULL) return;
 printReverse(start->next);
 printf("%d ",start->val);
}

Node* Locate(Node *ptr,int n)
{
 if(ptr==NULL||ptr->val==n) return ptr;
 return Locate(ptr->next,n);
}

int sum(Node *ptr)
{
 if(ptr==NULL) return 0;
 return ptr->val+sum(ptr->next);
}

int CountOccurrence(Node* start ,int n)
{
 if(start==NULL) return 0;
 return (start->val==n)+CountOccurrence(start->next,n);
}

Node* getMin(Node *ptr)
{
 Node *min=ptr;

 while(ptr)
 {
  if(ptr->val<min->val) min=ptr;
  ptr=ptr->next;
 }
 return min;
}

Node *GetMin(Node *start)
{
 Node* min;
 if(!start) return start;
   
 min=GetMin(start->next);
 
 if(min==NULL || start->val<min->val) min=start;

 return min;
}

void Reverse(Node* start)
{
 if(start==NULL||start->next==NULL)
 return;

 Reverse(start->next);
 start->next->next=start;
 start->next=NULL;

}
/* how to call append in main
   void main()
   {
    Node* start=NULL,*last=NULL;
    int n;
    
    while(1)
    {
     printf("\nEnter a number : ");
     scanf("%d",&n);

     if(n==0) break;
     start=append(start,&last,n);
    }
   }
   */
//Function to append node into the list

Node* append(Node*start,Node**p2last,int n)
{
 Node* nd=makeNode(n);

 if(start==NULL)
 start=nd;
 else
  (*p2last)->next=nd;

 *p2last=nd;

 return start;
}

//Recursive Code for reversing list
/*
 Function call in main
 reverse(start);
 nd=start;
 start=last;
 last=start ;
 */

void reverse(Node *start)
{
 if(start==NULL ||start->next==NULL)
 return;

 reverse(start->next);
 start->next->next=start;
 start->next=NULL;
}

//Function to insertBeforeFirst

Node* insBeforeFirst(Node*start,int n)
{
 if(start)
 {
  Node* nd=makeNode(n);
  nd->next=start;
  start=nd;
 }
 return start;
}

//Function to insertAfterFirst
//Function call statement last=insAfterFirst(start,last,n);

Node* insAfterFirst(Node* start,Node* last,int n)
{
 if(start)
 {
  Node* nd=makeNode(n);
  nd->next=start->next;
  start->next=nd;
  
  if(nd->next==NULL) last=nd;
 }
 return last;
}

//Function to insertBeforeLast 
//Function call statement start=insBeforelast;

Node* insBeforeLast(Node*start,int n)
{
 if(start)
 {
  Node *ptr=start,*prev;

  while(ptr->next)
  {
   prev=ptr;
   ptr=ptr->next;
  }
  Node *nd=makeNode(n);
  nd->next=ptr;
  
  if(ptr==start) start=nd;
  else prev->next=nd;
 }
 return start;
}

//Function to insertAfterLast
//Function call statement last=insAfterLast(Node*last,int n);

Node* insAfterLast(Node *last,int n)
{
 if(last)
 {
  Node* nd=makeNode(n);
  last=last->next=nd;
 }
 return last;
}

Node* insAfter(Node* ptr,Node* last,int pos,int n)
{
  /*
 int cnt=countNodes(ptr);
 int i=0;

 if(p<=cnt && cnt!=0 && p>0)
 {
  while(i<p-1)
  {
   ptr=ptr->next;
   i++;
  }
 
  Node* nd=makeNode(n);

  nd->next=ptr->next;
  ptr->next=nd;

  if(nd->next==NULL) last=nd;
 }
 return last;
 */

 while(ptr && pos>1) //For information based
 {                   //while(ptr && ptr->val!=info) ptr=ptr->next;
  ptr=ptr->next;
  pos--;
 }

 if(ptr)
 {
  Node *nd=makeNode(n);
  nd->next=ptr->next;
  ptr->next=nd;
  if(ptr==last) last=nd;
 }
 return last;
}

//Function to remove First Node of the list
//Function call statement start=rmvFirst(start,&last);

Node* rmvFirst(Node *start,Node **p2last)
{
 if(start)
 {
  Node* temp=start;
  start=start->next;

  if(start==NULL) *p2last=NULL;
  
  free(temp);
 }
 return start;
}

//Function to remove last Node of the list
//Function call statement start=rmvLast(start,&last);

Node* rmvLast(Node *start,Node **p2last)
{
 if(start)
 {
  Node *prev,*ptr=start;
  while(ptr->next)
  {
   prev=ptr;
   ptr=ptr->next;
  }
  if(ptr==start) start=*p2last=NULL;
  else
  {
   prev->next=NULL;
   *p2last=prev;
  }
  free(ptr);
 }
 return start;
}

//Non recursive code to reverse a list
//Function call statement start=reverseList(start,&last);

Node* reverseList(Node *start,Node **p2last)
{
  Node *prev=NULL,*ptr=start,*temp;

  while(ptr)
  {
   temp=ptr->next;
   ptr->next=prev;
   prev=ptr;
   ptr=temp;
  }
  *p2last=start;
  return prev;
}

//Function to insert a node before specified position

Node* insBefore(Node *start,int pos,int n)
{
 /*
 int cnt=countNodes(start);
 int i=0;

 if(p<=cnt && cnt!=0 && p>0)
 {
  Node* ptr=start,*prev=NULL;
  while(i<=p-2)
  {
   prev=ptr;
   ptr=ptr->next;
   i++;
  }

  Node *nd=makeNode(n);

  if(ptr==start) 
  {
   nd->next=start;
   start=nd;
  }
  else
  {
   nd->next=ptr;
   prev->next=nd;
  }
 }
 return start;
 */
 
  Node* prev,*ptr=start;

  while(ptr && pos>1)
  {
   prev=ptr;
   ptr-ptr->next;
   pos--;
  }
  if(ptr)
  {
   Node *nd=makeNode(n);
   nd->next=ptr;

   if(ptr==start)
     start=nd;
   else
   prev->next=nd;
  }
  return start;
}


Node* insertBefore(Node *start,int pos,int n) // recursive code
{
 /*
 if(pos==1) 
  if(ptr)
  {
  Node *nd=makeNode(n);
  nd->next=ptr;
  ptr=nd;
  }
  return ptr;
 }
 
 if(ptr)
 {
  Node *temp=insertBefore(ptr->next,pos-1,n);
  if(temp) 
  ptr->next=temp;
 }
  return ptr;
  */

 if(start==NULL) return start;

 if(pos==1)
 {
  Node *nd=makeNode(n);
  nd->next=start;
  return nd;
 }
 start->next=insBefore(start->next,pos-1,n);
 return start;
}


Node* insertAfter(Node *start,Node *last,int pos,int n)
{
 if(start==NULL) return start;

 if(pos==1)
 {
  Node *nd=makeNode(n);
  nd->next=start->next;
  start->next=nd;

  if(start==last)
  last=nd;
  return last;
 }
 return insAfter(start->next,last,pos-1,n);
}

Node* rmvNode(Node *start,Node **p2last,int pos)
{
/*
 if(start)
 {
  int cnt=countNodes(start);

  if(p<=cnt && p>0)
  {
   Node *prev=NULL,*ptr=start;
   int i=0;

   while(i<p-1)
   {
    prev=ptr;
    ptr=ptr->next;
    i++;
   }

   if(ptr==start)
   {
    if(start->next==NULL) 
     start=*p2last=NULL;
    else start=start->next;
   }

   else if(ptr==*p2last)
   {
    prev->next=NULL;
    *p2last=prev;
   }
   else
    prev->next=ptr->next;

    free(ptr);
  }
 }
 return start;
 */

 Node *prev,*ptr=start;

 while(ptr && pos>1)
 {
  prev=ptr;
  ptr=ptr->next;
  pos--;
 }

 if(ptr)
 {
  if(ptr==start)
  {
   start=start->next;
   
   if(start==NULL) *p2last=NULL;
  }
  else prev->next=ptr->next;

  if(prev->next==NULL) *p2last=prev;
  
  free(ptr);
 }
 return start;
}

Node* remvNode(Node *start,Node **p2last,int pos)
{
 if(start==NULL) return start;
 
 if(pos==1)
 {
  Node *temp=start;
  start=start->next;
   free(temp);
   return start;
 }
 
 start->next=remvNode(start->next,p2last,pos-1);
  
  if(start->next==NULL) *p2last=start;

  return start;   
}

// function to delete list
// finction call statement last=start=clear(start);
Node* clear(Node *ptr)
{
 Node* temp;
 
 while(ptr)
 {
  temp=ptr;
  ptr=ptr->next;
  free(temp);
 }
 return ptr;
}

// recursive codes for insBefore insAfter rmvNode