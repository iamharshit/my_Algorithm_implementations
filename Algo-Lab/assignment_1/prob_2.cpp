#include<bits/stdc++.h>

using namespace std;

#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])
int no=3;

vector<int> merge(vector<int> l,vector<int> r){
	vector<int> new_v;
	int i=0,j=0;
	while(i<l.size() && j<r.size())
	    if(l[i]<r[j]){	
		new_v.push_back(l[i]);
		i+=1;
	    }
	    else{
		new_v.push_back(r[j]);
		j+=1;
	    }

	while(i<l.size()){
		new_v.push_back(l[i]);
		i+=1;
	}
	while(j<r.size()){
		new_v.push_back(r[j]);	
		j+=1;
	}
	cout<<"AFTER MERGE= ";
	VECTORPRINT(new_v)
	return new_v;
}

vector<int> insert_sort(vector<int> v){
	
	int sz = v.size();
	cout<<"sz= "<<sz<<endl;
	if(sz<=no){
		// insertion sort
		for(int i=0;i<sz;i++){
			int j=i;
			while(j>0 && v[j]<v[j-1]){
				//swap
				int temp=v[j-1];
				v[j-1]=v[j];
				v[j]=temp;
				
				j--;
			}
		}
		cout<<"insertion sort= ";VECTORPRINT(v)
		return v;
	}
	
	else{
		int mid=sz/2;
		vector<int> left_v(v.begin(), v.begin() + mid);
		vector<int> right_v(v.begin()+mid, v.end());
		cout<<"-------------"<<endl;
		VECTORPRINT(left_v)
		VECTORPRINT(right_v)
		left_v=insert_sort(left_v);
		right_v=insert_sort(right_v);
		return merge(left_v,right_v);
	}
		
}

int main(){
	int arr[]={4,7,3,1,8,5,13,3,7,4,11,4};
	//cout<<"sdsd";
	vector<int> v(arr,arr+ARR_SIZE(arr));
	
	v = insert_sort(v);
	cout<<"------------"<<endl;		
	cout<<"final ans= "; VECTORPRINT(v) cout<<endl;
	return 0;
}
