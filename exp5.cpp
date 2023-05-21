#include<bits/stdc++.h>

 

using namespace std;

 

class Node{

public:

            int val;

            Node *next;

 

            Node(){

                        this->val = INT_MIN;

                        this->next = NULL;

            }

           

            Node(int x){

                        val = x;

                        this->next = NULL;

            }

};

 

class LL{

            Node *head;

 

public:

            LL(){

                        this->head = NULL;

            }

 

            void insertAtBegin(int x){

                        Node *n1 = new Node(x);

                        n1->next = head;

                        head = n1;

            }

 

            void insertAtEnd(int x){

                        Node *n1 = new Node(x);

                        if(head==NULL){

                                    head=n1;

                                    return ;

                        }

                        Node *temp = head;

 

                        while(temp->next){

                                    temp = temp->next;

                        }

                        temp->next = n1;

            }

           

            bool isFound(int x){

                Node *temp = head;

                while(temp){

                    if(temp->val == x){

                        return true;

                    }

                    temp = temp->next;

                }

                return false;

            }

           

            void printList(){

                        if(!head){

                                    cout<<"Underflow: No data to print.";

                                    return ;

                        }x`

                        Node *temp = head;

                        while(temp){

                                    cout<<temp->val<<"->";

                                    temp = temp->next;

                        }

            }

};

 

int main(){

            LL l1,l2,l3;

            l1.insertAtEnd(1);

            l1.insertAtEnd(5);

            l1.insertAtEnd(7);

            cout<<(l1.isFound(12) ? "Found\n" : "Not Found\n");

            return 0;

}


 


 

for(int i=0 ; i<=n-m ; i++){

int curr_hash = calc_hash(str,i,m);

 

if(hash == curr_hash){

flag = true;

break;

}

}

 

if(flag)printf("Found");

else printf("Not Found");

 

return 0;

}