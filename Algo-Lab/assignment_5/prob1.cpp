#include <bits/stdc++.h>
using namespace std;

int arr[100];
int status[100];
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)

void swap(int a,int b){
	int temp=arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

int main(){
	/*
		 25
		/  \
	       80  530 
	      / \   / \
	     21 194 30 170
	*/
	int sz=7;
	int arr[]={0,25,80,530,21,194,30,170};	
	/*
	//percolution
	FOR(i,2,sz){
	   int k=i;
	   while(k/2>=1 && arr[k/2]<arr[k]){		
		//swap
		int temp=arr[k/2];
		arr[k/2] = arr[k];
		arr[k] = temp;

		k=k/2;
	   }
	}
	*/	
	
	//siftdown
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

	//print arr
	FOR(i,1,sz)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}
