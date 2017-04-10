//print linked list in reverse order

#include<bits/stdc++.h>
using namespace std;

struct node{
	int value;
	struct node *next;
};

void append_list(node *head,int i){
	node *tmp = new node;
	tmp = head;
	while(tmp->next!=NULL)
		tmp = tmp->next;
	tmp->next = new node;
	tmp->value = i;
}

void print_list(node *head){
	node *tmp = new node;
	tmp = head;
	while(tmp->next!=NULL){
		cout<<tmp->value<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

void insert_list(node *head,int pos,int val){
	if(pos==1){
		head->value=val;
		return;	
	}

	node *new_node = new node;
	new_node->value = val;

	node *tmp = new node;
	tmp = head;
	int count=0;
	while(count!=pos-2){
		tmp = tmp->next;
		count++;
	}
	new_node->next = tmp->next;
	tmp->next = new_node;	
}

int getsize_list(node *head){
	node *tmp = new node;
	tmp = head;
	int sz=0;
	while(tmp->next!=NULL){
		sz++;
		tmp = tmp->next;
	}
	return sz;
}

int search_list(node *head,int val){
	node *tmp = new node;
	tmp = head;
	int pos=1;
	while(tmp->value!=val){
		pos++;
		tmp = tmp->next;
	}
	return pos;
}

void delete_list(node *head,int val){
	node *tmp = new node;
	tmp = head;
	while(tmp->next->value!=val)
		tmp = tmp->next;
	tmp->next=tmp->next->next;
}

int getvalue_list(node *head,int pos){
	node *tmp = new node;
	tmp = head;
	int count=0;
	while(count!=pos-1){
		tmp = tmp->next;
		count++;
	}
	return tmp->value;
}

void edit_list(node *head,int pos,int val){
	node *tmp = new node;
	tmp = head;
	int count=0;
	while(count!=pos-1){
		tmp = tmp->next;
		count++;
	}
	tmp->value = val;
}

void swap_list(node *head,int pos1,int pos2){
	int val1 = getvalue_list(head,pos1);
	int val2 = getvalue_list(head,pos2);
	edit_list(head, pos1, val2);
	edit_list(head, pos2, val1);
}

void reverse_list(node *head){
	int sz=getsize_list(head);
	for(int i=1;i<=sz/2;i++)
		swap_list(head,i,sz-i+1);
}

int main(){
	node* head =new node;
	head->next = NULL;
	//for(int i=1;i<=9;i++) append_list(head,i);
	int n;
	cout<<"Enter no. of elements to be inserted: "; cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cout<<">>> ";cin>>temp;
		append_list(head,temp);
	}	
	cout<<"output= "<<endl;
	reverse_list(head);
	print_list(head);
	reverse_list(head);
}
