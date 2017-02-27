#include <bits/stdc++.h>
using namespace std;

int arr[100];
int status[100];
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

void insert(int x){
	int i=1;
	while(status[i]){
		if(x<arr[i]) i=2*i;
		else i=2*i+1;
	}
	//inserting
	arr[i]=x;
	status[i]=1;
}

void in_order_traverse(int i){
	//going left		
	if(status[2*i])
		in_order_traverse(2*i);
	
	//current node
	cout<<arr[i]<<", ";

	//going right
	if(status[2*i+1])
		in_order_traverse(2*i+1);
}

int main(){
	/*
		 25
		/  \
	       20  50 
	      / \   /\
	     11 24 30 70
	*/
	int sz=7;
	//int arr[]={25,20,50,11,24,30,70};
	int arr[]={11,24,30,70,20,50,25};	

	FOR(i,0,sz-1)
	   insert(arr[i]);
	
	//in-order traversal
	int start=1;
	in_order_traverse(start);
	cout<<endl;
	
	return 0;
}
