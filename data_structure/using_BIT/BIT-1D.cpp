#include<bits/stdc++.h>
using namespace std;

class BIT{
    private:
        vector<int> tree;
        int n;
    public:
        BIT(int sz){
            n=sz;
            tree.resize(n);
        }
        void update(int i,int x){
            while(i<=n-1){
                tree[i]+=x;
                i=i+(i&-i);
            }
        }
        int read(int i){
            int sum=0;
            while(i>0){
                sum+=tree[i];
                i=i-(i&-i);
            }
            return sum;
        }
};

int main(){
    BIT b(10);

    b.update(4,12);
    b.update(7,3);
    b.update(1,20);

    cout<<b.read(7)<<endl;
    cout<<b.read(5)<<endl;
    cout<<b.read(0)<<endl;
    cout<<b.read(1)<<endl;

    /* output:
       35
       32
       0
       20
    */

    return 0;
}
