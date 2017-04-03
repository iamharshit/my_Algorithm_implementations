//stack implementation

#include<bits/stdc++.h>
using namespace std;

struct stack_ds{
	int top;
	int item[100];
};

void push_stack(stack_ds *stk, int x){
	stk->item[stk->top] = x;
	stk->top++;
}

void print_stack(stack_ds *stk){
	if(stk->top>=100){
		cout<<"Overflow has occured"<<endl;
		return;
	}
	for(int i=0;i<stk->top;i++)
		cout<<stk->item[i]<<" ";
	cout<<endl;
}

int empty(stack_ds *stk){
	if(stk->top==0)	return 1;
	else	return 0;
}

void pop_stack(stack_ds *stk){
	if(empty(stk)){
		cout<<"Underflow has occured"<<endl;
		return;
	}
	stk->top--;
	cout<<"Popped Element="<<stk->item[stk->top]<<endl;
}


int main(){
	stack_ds *mystack = new stack_ds;
	mystack->top=0;

	int tmp;
	while(1){
		cout<<"push:1   pop:2   exit:4"<<endl;
		cin>>tmp;
		if(tmp==1){
			cout<<"Choice? "; cin>>tmp;
			push_stack(mystack, tmp);
		}
		else if(tmp==2)
			pop_stack(mystack);		
		else if(tmp==4)
			break;
		else 
			cout<<"INVALID CHOICE !!!!"<<endl;
		print_stack(mystack);
	}

	return 0;
}
