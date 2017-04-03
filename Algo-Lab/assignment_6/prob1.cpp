//implement merge data structure

#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])

int n;
vector<int> arr;//[]={0, 1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20};
vector<int> label;//[]={0, 1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20};

void merge(int x,int y){
	int mini = min(label[x],label[y]);
	int maxi = max(label[x],label[y]);
	FOR(i,0,n )
		if(label[i]==maxi)
			label[i] = mini;
}

int find(int r){
	return label[r];
}

int main(){
	int x,y;
	cout<<"Enter size of array: ";cin>>n;
	FOR(i,0,n){
		arr.push_back(i);
		label.push_back(i);
	}

	while(1){
		cout<<"Press M for merge, F for find and Q to exit"<<endl;
		string tmp; cin>>tmp;
		if(tmp=="M"){ 
			cin>>x>>y;
			merge(x,y);
		}
		else if(tmp=="F"){
			cin>>x;
			cout<<"Label for element "<<x<<" is "<<find(x)<<endl;
		}
		else if(tmp=="P"){
			cout<<"Label array: ";
			FOR(i,0,n) cout<<label[i]<<" ";
			cout<<endl;
		}
		else if(tmp=="Q") break;
		else cout<<"Invalid !!!"<<endl;
	}	
	return 0;
}
