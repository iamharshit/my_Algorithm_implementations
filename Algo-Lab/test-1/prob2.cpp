#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
int search_status=0;

typedef struct Node{
	int value;
	Node *next_right;
	Node *next_left;
}Node;

int countX;
class LinkedList{
	public:
		Node *head;
		LinkedList(int x){
			head=new Node;
			head->value=x;
			countX = 0;
		}

		Node* insert(Node *curr,int x){
			if(curr==NULL){
				Node *temp=new Node;
				temp->value=x;
				return temp;
			} 		

			if(x<=curr->value)
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
					countX++;
				}
				search(temp->next_right,x);
			}
		}
};

int main(){
	int sz;
	cout<<"* Enter n: ";cin>>sz;

	cout<<"* Enter arr values: "<<endl;
	int x; cin>>x;
	LinkedList l(x);
	
	//insert
	FOR(i,1,sz-1){
		cin>>x;
		l.insert(l.head,x);
	}
	//search
	int X;
	cout<<"Enter the element to be searched: "; cin>>X;
	l.search(l.head,X);
	
	cout<<"* Output = "<<countX<<endl;
	
	return 0;
}
