#include<bits/stdc++.h>
using namespace std;

#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}cout<<endl;}

#define VPRINT(_vec,a,b) {int _t=a;while(_t<=b){cout<<_vec[_t++]<<' ';}cout<<endl;}

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

vector<int> vec;

void swap(int i,int j){
	int temp=vec[j];
	vec[j]=vec[i];
	vec[i]=temp;
}

void quicksort(int start,int end){
	int pivot=end;
	int wall=start;
	VPRINT(vec,start,end)
	cout<<"pivot element= "<<vec[pivot]<<endl;

	FOR(curr,start,pivot-1){
		//if less then pivot
		//cout<<"vec[curr]="<<vec[curr]<<" "<<"vec[pivot]="<<vec[pivot]<<endl;
		if(vec[curr]<vec[pivot]){ 
			//cout<<vec[wall]<<" "<<vec[pivot]<<endl;
			swap(wall,curr);
			//cout<<vec[wall]<<" "<<vec[pivot]<<endl;
			//VECTORPRINT(vec)
			//cout<<"wall= "<<wall<<endl;
			wall++;
		}
	}

	//cout<<"final wall="<<wall<<endl;
	swap(wall,pivot);
        
       	cout<<"after sorting= ";VECTORPRINT(vec)	
	cout<<"-------------"<<endl;
	if(wall-start>=2) 
		quicksort(start,wall-1);

	if(end-wall>=2)
		quicksort(wall+1,end);

}

int main(){
	int arr[]={3,6,8,2,0,11,1};
	FOR(i,0,7-1)
		vec.push_back(arr[i]);
	
	cout<<"Initial Array= "; VECTORPRINT(vec)
	quicksort(0,vec.size()-1);
	cout<<"final array= "; VECTORPRINT(vec)
	return 0;
}


