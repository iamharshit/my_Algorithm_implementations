#include<bits/stdc++.h>

using namespace std;


#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}


void insertion_sort(vector<int> v){
	int sz=v.size();
	int comparisions=0,shifts=0;
	for(int i=0;i<sz;i++){
		//cout<<"original: ";
		//VECTORPRINT(v)
		int j=i;
		while(j>0 && v[j]<v[j-1]){
			//swap
			shifts++;
			comparisions++;
			int temp=v[j-1];
			v[j-1]=v[j];
			v[j]=temp;	
			j--;
			//cout<<"	after shift= "; VECTORPRINT(v)
		}
		if(j>0 && v[j]>=v[j-1])
			comparisions++;
		//cout<<"	total comparisions= "<<comparisions<<endl;
		//cout<<"----------------------------"<<endl;
	}
	cout<<"comparsions= "<<comparisions<<endl;
	cout<<"shifts= "<<shifts<<endl;
	cout<<"final ans= "; VECTORPRINT(v)
}

int main(){
	//int arr[]={4,7,3,1,8,5,13,3,7,4,11,4};
	int arr[]={3,6,8,2,0,11,1};
	//cout<<"sdsd";
	vector<int> v(arr,arr+7);
	insertion_sort(v);		
	return 0;
}



