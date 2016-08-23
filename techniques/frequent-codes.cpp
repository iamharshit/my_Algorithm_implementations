// sorting an array from largest to smallest
vi v;
bool compare(pii &a,pii &b){
    return a.X==b.X ? a.Y>b.Y : a.X>b.X; 
}
sort(v.begin(),v.end(),compare);

//creating an empty array
int arr[]={};

//clearing all the elements of an array
memset(arr,0, sizeof arr);

//for viewing precision
cout<<numeric_limits<lonng double>::digits10<<endl;

//difference between 2 sets
set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),inserter(s3,s3.end() ));

//computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<lli>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

// computes A ^ p
matrix power(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, power(A, p-1));
    matrix X = power(A, p/2);
    return mul(X, X);
}

// computes no. of set bit in an integer
int nSetBits(int i) {
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

// using goto
FOR(i,1,6){
    cout<<"i= "<<i<<endl;
    if(i==3) goto hell;
}
hell:
    cout<<"xx"<<endl;

// setting whole 2d vector to 0
int c[2][2] = {0};

// converting x to long long
 1LL*x

lli gcd(lli a,lli b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

lli fastexpo(int a,int b){
    lli res=1;
    while(b){
        if(b&1) res*=a;
        a=a*a;
        b/=2;
    }
    return res;
}

// prime factorises of n
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
int n;
cin>>n;
int index=0;
int pf=prime[index];
while(n!=1 && pf*pf<=n){
    while(n%pf==0) {n/=pf; cout<<"pf= "<<pf<<endl;}
    pf=prime[++index];
}
if(n!=1) cout<<"n="<<n<<endl;

//getting inverse (by method 1)
void getinverse(int a,int nod,int &x,int &y){
    if(a==0){
        x=0; y=1; return;
    }
    int x1,y1;
    getinverse(nod%a,a,x1,y1);
    x=y1-(nod/a)*x1;
    while(x<0) x+=nod;
    y=x1;
    while(y<0) y+=nod;
}

//getting inverse (by method 2)
int inverse(int a){
    //int nod=(mod-1)/2;
    int nod=7;
    int x,y;
    getinverse(a,nod,x,y);
    while(x)
    return x;
}

//  making 2d vector array in c++
vector<pair<int,int> > v[1001][1001];
