#include <bits/stdc++.h>
using namespace std;

int status[100];
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)

int sz=7;
int array[]={0,25,80,530,21,194,30,170};
vector<int> arr(array, array + sizeof array / sizeof array[0]);

void swap(int a,int b){
	int temp=arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

void siftdown(){
	nFOR(i,sz/2,1){
	        int k=i;
		int j;
		do{
			j=k;
			if(2*j<=sz && arr[2*j]>arr[k])
			   k=2*j;
			if(2*j+1<=sz && arr[2*j+1]>arr[k])
			   k=2*j+1;
			//swap
			int temp=arr[k];
			arr[k] = arr[j];
			arr[j] = temp;		
		}while(j!=k);		
	}
}

void print(){
	FOR(i,1,sz)
		cout<<arr[i]<<" ";
	cout<<endl;	
}

int main(){
	/*
		 25
		/  \
	       80  530 
	      / \   / \
	     21 194 30 170
	*/

	//siftdown
	siftdown();
	cout<<"* Original Heap:";
	print();

	//delete max
	swap(1,sz);
	sz=sz-1;  arr.pop_back();
	siftdown();
	cout<<"* After deleting the maximum element: ";
	print();
	
	//heapsort
	cout<<"* Sorted array: ";
	int szz=sz;
	while(sz!=1){
		swap(1,sz);
		sz=sz-1;  
		cout<<arr[sz+1]<<" ";
		siftdown();
	}
	cout<<arr[sz]<<endl;

	//insert
	sz=szz;
	int x;
	cout<<"* Enter the value to be inserted: "; cin>>x;	
	arr.push_back(x);
	sz++;
	siftdown();
	print();

	return 0;
}
