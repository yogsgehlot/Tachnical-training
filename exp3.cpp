#include<iostream>
#include<string>
using namespace std;
//two pointer apprpach
class Node{
	public:
		char data;
		Node *next;
       
		Node(char val){
			data=val;
			next=NULL;
		}
		
};
void insert(Node* &head,char val){
	Node* n=new Node(val);
	if(head==NULL){
		head=n;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next =n;
}
void display(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
bool isPalindrome(Node* head){
	Node *temp=head;
	string s="";
	bool flag=true;
	while(temp!=NULL){
		s+=temp->data;
		temp=temp->next;
	}
	int right=0,end=s.length()-1;	
	while(right<end){
		if(s[right]!=s[end]){
		flag=false;
		break;
		}
		else{
			right++;
			end--;
		}
		
	}
	
	return flag;
}

int main()
{
	Node *head=NULL;
	insert(head,'a');
	insert(head,'b');
	insert(head,'c');
	insert(head,'b');
	insert(head,'a');


	display(head);
	cout<<"\nIs palindrome or not -> "<<isPalindrome(head);
	
	
	return 0;
}