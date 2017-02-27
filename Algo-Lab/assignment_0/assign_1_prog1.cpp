#include<bits/stdc++.h>

using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++];}}

int main(){
        string num1,num2,tmp;
        cout<<"num1= "; cin>>num1; 
        cout<<"num2= "; cin>>num2;
	
	//making num2>num1
	if(num1.length()<num2.length()){
		tmp=num1;
		num1 = num2;
		num2 = tmp;
	}	
	//cout<<num1;
	vector<int> arr1(num1.length()),arr2(num2.length()),ans;	
	
	FOR(i,0,num1.length()-1){
		arr1[i]=(int)num1[i]-'0'; //cout<<arr1[i]<<" ";
	}
	FOR(i,0,num2.length()-1){
		arr2[i]=(int)num2[i]-'0'; //cout<<arr2[i]<<" ";
	}
	reverse(arr1.begin(),arr1.end());
	reverse(arr2.begin(),arr2.end());
		
	int temp,anss=0,initial_carry=0,another;
	FOR(i,0,num1.length()-1 ){
		if(i<=num2.length()-1)
			another = arr2[i];
		else
			another = 0;
		temp=arr1[i]+another+initial_carry;
		//cout<<"f: "<<arr1[i]<<"\ts:"<<another<<endl;
		ans.push_back(temp%10);
		//cout<<anss<<endl;
		if(temp>9){
                        initial_carry=1;
                }
                else{
                        initial_carry=0;
                }
	}

	if(initial_carry)
		ans.push_back(initial_carry);

	reverse(ans.begin(), ans.end());
	
	cout<<"sum= ";VECTORPRINT(ans) 
	cout<<endl;
        return 0;
}
