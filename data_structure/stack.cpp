/*
	Stack implementation using Linked List
*/

#include <iostream>
using namespace std;

struct node{
	int value;
	node *next;
};

class stack{
	node *head;
	public:
		stack(){
			head=NULL;
		}

		void push(int val){
			if(head==NULL){
				head=new node;
				head->value=val;
				head->next=NULL;
			}
			else{
				node *temp=head;
				while(temp->next != NULL)
					temp=temp->next;
				temp->next=new node;
				temp->next->value=val;
				temp->next->next=NULL;
			}
		}
		int pop(){
			node *temp=head;
			if(head==NULL){
				cout<<"Nothing to pop!!"<<endl;
				return -1;
			}
			else if(head->next==NULL){
				int val=head->value;
				head=NULL;
				delete temp;
				return val;
			}
			else{
				node *prev=head;
				while(temp->next != NULL){
                                        prev=temp;
					temp=temp->next;
				}
				int val=temp->value;
				prev->next=NULL;
				delete temp;
				return val;
			}
		}
		void print(){
			if(head==NULL){
				cout<<"Stack is empty!!"<<endl;
			}
			else{
				node *temp=head;
				while(temp != NULL)
				{
					cout << temp->value << "<-";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};

int main(){
	stack s;
	s.push(4);
	s.push(7);
	s.push(19);
        s.push(77);

	cout<<s.pop()<<endl;
	//outputs 77
	cout<<s.pop()<<endl;
        //outputs 19

	s.print();
        //outputs 4<-7<-

	return 0;
}
