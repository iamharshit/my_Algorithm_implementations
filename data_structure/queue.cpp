/*
	Queue implemented using Linked List
*/

#include <iostream>
using namespace std;

struct node{
	int value;
	node *next;
};

class queue{
	node *head;
	public:
		queue(){
			head=NULL;
		}
		void enqueue(int val){
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
		int dequeue(){
			if(head==NULL){
				cout<<"Nothing to dequeue!!"<<endl;
				return -1;
			}
			else{
				node *temp=head;
				int val=head->value;
				head=head->next;
				delete temp;
				return val;
			}
		}
		void print(){
			if(head==NULL){
				cout<<"Queue is empty!!"<<endl;
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
	queue q;

	q.enqueue(3);
	q.enqueue(4);
        q.enqueue(8);
	q.enqueue(19);

	cout<<q.dequeue()<<endl;
	//outputs 3

	q.print();
	//outputs 4<-8<-19<-

	return 0;
}
