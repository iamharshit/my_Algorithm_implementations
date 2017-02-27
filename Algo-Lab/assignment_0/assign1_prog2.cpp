#include<bits/stdc++.h>

using namespace std;
#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

vector<int> v;
int k,n;
void insertion_sort(int start){
	vector<int> temp;
	int i=start;
	while(i<=n-1){
		temp.push_back(v[i]);
		i+=k;
	}
        //insertion_sort
	int tmp;		
	for (int i = 0; i < temp.size(); i++){
		int j = i;
		while (j > 0 && temp[j] < temp[j-1]){
			  tmp = temp[j];
			  temp[j] = temp[j-1];
			  temp[j-1] = tmp;
			  j--;
		}
	}

	//sort(temp.begin(),temp.end());
	i=start;
	while(i<=n-1){
		v[i]=temp.front();
		temp.erase(temp.begin(),temp.begin()+1);//v.pop_front();
		i+=k;
	}
	
}

int main(){
	cout<<"Enter n: "; cin>>n;	
	n=10;
	v.resize(n);	

	cout<<"Enter list of numbers: ";
	FOR(i,0,n-1)
		cin>>v[i];
		
	cout<<"Enter k: "; cin>>k;

	while(k>1){
		FOR(i,0,k-1)
			insertion_sort(i);
		k/=3;
	}
	cout<<"==============="<<endl;
	cout<<"Partially sorted array: "; 
	VECTORPRINT(v)
	cout<<"final k: "<<k<<endl;
	
	return 0;
}
