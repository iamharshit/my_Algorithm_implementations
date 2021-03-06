#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
int search_status=0;

typedef struct Node{
	int value;
	Node *next_right;
	Node *next_left;
}Node;

class LinkedList{
	public:
		Node *head;
		LinkedList(int x){
			head=new Node;
			head->value=x;
		}

		Node* insert(Node *curr,int x){
			if(curr==NULL){
				Node *temp=new Node;
				temp->value=x;
				return temp;
			} 		

			if(x<curr->value)
				curr->next_left=insert(curr->next_left,x);
			else 
				curr->next_right=insert(curr->next_right,x);

			return curr;
		}

		void inorder_traverse(Node *temp){
			if(temp!=NULL){
				inorder_traverse(temp->next_left);
				cout<<temp->value<<" ";
				inorder_traverse(temp->next_right);
			}
		}
		
		void search(Node *temp,int x){
			if(temp!=NULL){
				search(temp->next_left,x);
				if(temp->value==x){
					search_status= 1;
				}
				search(temp->next_right,x);
			}
		}

		Node* findmin(Node *temp){
			while(temp->next_left!=NULL) temp=temp->next_left;
			return temp;
		}
		
		Node* delete_(Node *temp,int x){
			if(temp==NULL) return NULL;		
			
			if(x<temp->value) 
				temp->next_left=delete_(temp->next_left,x);
			else if(x>temp->value)
				temp->next_right=delete_(temp->next_right,x);
			else{
				 if(temp->next_left==NULL && temp->next_right==NULL)
					temp=NULL;
				 else if(temp->next_left==NULL)
					temp=temp->next_right;
				 else if(temp->next_right==NULL)
					temp=temp->next_left;
				 else{
					Node *mini=findmin(temp->next_right);
					temp->value=mini->value;
					temp->next_right=delete_(temp->next_right, mini->value);				
			   	 }
			}
			return temp;
		}
};

int main(){
	/*
		 25
		/  \
	       20  50 
	      / \   /\
	     11 24 30 70
	*/
	int sz=7;
	int arr[]={25,20,50,11,24,30,70};
	//int arr[]={11,24,30,70,20,50,25};	
	
	LinkedList l(arr[0]);
	
	//insert
	FOR(i,1,sz-1)	
		l.insert(l.head,arr[i]);
	
	//print
	l.inorder_traverse(l.head); cout<<endl;
	
	//search
	search_status=0;
	l.search(l.head,120);
	if(search_status) cout<<"Item found"<<endl;
	else cout<<"Item Not found"<<endl;
	
	//delete
	l.head=l.delete_(l.head,111);

	//print again
	l.inorder_traverse(l.head); cout<<endl;

	return 0;
}
