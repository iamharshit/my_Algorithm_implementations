#include<bits/stdc++.h>
using namespace std;

#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}

#define VPRINT(_vec,a,b) {int _t=a;while(_t<=b){cout<<_vec[_t++]<<' ';}cout<<endl;}

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

vector<int> vec;
int k;

void swap(int i,int j){
	int temp=vec[j];
	vec[j]=vec[i];
	vec[i]=temp;
}

void quicksort(int start,int end){
	int pivot=end;
	int wall=start;

	FOR(curr,start,pivot-1){
		//if less then pivot
		if(vec[curr]<vec[pivot]){ 
			swap(wall,curr);
			wall++;
		}
	}
        //cout<<"wall="<<wall<<endl;
	swap(wall,pivot);
	//cout<<"k-1="<<k-1<<endl;

	if(wall==k-1){       
		cout<<"kth smallest element= "<<vec[k-1]<<endl;
		cout<<"current state= "; VECTORPRINT(vec)
		cout<<"------------"<<endl;
		return;
       	}
	if(wall-start>=2) 
		quicksort(start,wall-1);

	if(end-wall>=2)
		quicksort(wall+1,end);

}

int main(){
	int arr[]={3,6,8,2,0,11,1};
	FOR(i,0,7-1)
		vec.push_back(arr[i]);
	
	k=4;
	
	cout<<"Initial Array= "; VECTORPRINT(vec)
	quicksort(0,vec.size()-1);
	cout<<"final array= "; VECTORPRINT(vec)
	return 0;
}

//comment on complexity = nlog(n/k)

