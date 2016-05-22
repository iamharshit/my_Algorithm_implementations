#include <iostream>
using namespace std;

struct node{
	int value;
	node *next;
};

class linked_list{
	node *head;
	public:
		linked_list(){
			head=NULL;
		}
		void append(int val){
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
		void print(){
			if(head==NULL){
				cout<<"Linked List is empty"<<endl;
			}
			else{
				node *temp=head;
				while(temp != NULL)
				{
					cout << temp->value << "->";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		int count(){
			int ct=0;
			node *temp=head;
			while(temp != NULL)
			{
				ct++;
				temp=temp->next;
			}
			return ct;
		}
		void del(int val){
            node *temp=head;
			if (head->value == val){
				head=head->next;
				delete temp;
				return;
			}
			node *before=head;
			while(temp != NULL){
				if(temp->value == val)
				{
					before->next=temp->next;
					delete temp;
					return;
				}
				before=temp;
				temp=temp->next;
			}
			cout<<"No such item exist !!!"<<endl;
		}
		int position(int val){   // returns -1 if not found otherwise its position(0 based indexing followed)
			int pos=0;
			node *temp=head;
			while(temp != NULL){
				if(temp->value == val)
					return pos;
				pos++;
				temp=temp->next;
			}
			return -1;
		}
};

int main(){
	linked_list ll;
	ll.append(3);
	ll.append(4);
	ll.append(5);
  ll.del(4);

	ll.print();
	//ouputs 3->5->

  cout<<ll.count()<<endl;
  //outputs 2

  cout<<ll.position(5)<<endl;
  //outputs 1
    
	return 0;
}
