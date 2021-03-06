#include<bits/stdc++.h>
using namespace std;

#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}
#define VPRINT(_vec,a,b) {int _t=a;while(_t<=b){cout<<_vec[_t++]<<' ';}cout<<endl;}
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

vector<int> vec;
int binary_search_(int x,int start,int end){
	if(start>end) return -1;

	int mid=(start+end)/2;
	if(vec[mid]==x) return mid;
	else if(vec[mid]>x) return binary_search_(x,start,mid-1); //going left
	else return binary_search_(x,mid+1,end);
}

int main(){
	//int arr[]={3,6,8,2,0,11,11};
	//int arr[]={45,54,1,45,11,45,9};
	int arr[]={-1,-1,-1,-1,-1,-1,-1};	
	FOR(i,0,7-1)
		vec.push_back(arr[i]);
	
	cout<<"Original Array= "; VECTORPRINT(vec)
	sort(vec.begin(),vec.end());
	cout<<"Sorted Array= "; VECTORPRINT(vec)
	
	int element;
	cout<<"Enter element to be searched: "; cin>>element;
	int pos = binary_search_(element,0,vec.size()-1);
	if(pos!=-1){
		cout<<"Position of "<<element<<" is "<<pos+1;
		int poss=pos;		
		while(poss+1<=vec.size()-1 && vec[poss+1]==element){
			cout<<", "<<poss+2;				
			poss++;
		}
		poss=pos;
		while(poss-1>=0 && vec[poss-1]==element){
			cout<<", "<<poss-1+1;				
			poss--;
		}
		cout<<endl;
	}
	else 
		cout<<"Element "<<element<<" does not exist."<<endl;		

	return 0;
}

