#include <bits/stdc++.h>
#include <chrono>
#include<queue>
using namespace std;
using namespace std::chrono;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,avx,tune=native")

#define f0r(a,b) for(long long a=0;a<b;a++)
#define f1r(a,b) for(long long a=1;a<=b;a++)
#define f0rd(a,b) for(long long a=b-1;a>=0;a--)
#define f1rd(a,b) for(long long a=b;a>0;a--)
#define f(a,b,c) for(long long a=b;a<c;a++)
#define ms(arr,v) memset(arr,v,sizeof(arr))
#define pb push_back
#define mp make_pair
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout <<setprecision(prec)<<fixed;}
#define f first 
#define s second 
#define all(v) v.begin(),v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define printunique(v) {getunique(v); for(auto x:v) cout << x << " "; cout << endl;}
#define readgraph(list,edges) for(int i=0;i<edges;i++){int u,v; cin >> u >> v; list[u].pb(v); list[v].pb(u);}
#define ai(a,n) for(int ele=0;ele<n;ele++){cin >> a[ele];}
#define ao(a,n) for(int ele=0;ele<n;ele++){cout << a[ele] << " ";} cout << endl;
#define ain(a,n,i) for(int ele=i;ele<n;ele++){cin >> a[ele];}
#define aout(a,n,i) for(int ele=i;ele<n;ele++){cout << a[ele] << " ";} cout << endl;
#define vsort(v) sort(all(v))
#define rvsort(v) sort(all(v),greater<int>())
#define vsz(x)((long long)x.size())


typedef long long ll;
typedef long double lld;
typedef double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<pii> vpi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpl;

template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout,pair<A,B> const &p){return cout<<"("<<p.f<<","<<p.s<<")";}
template <typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout <<"[";for(int i=0;i<v.size();i++){cout<<v[i];if(i)cout<<","; cout<<v[i];}return cout<<"]";}
template<typename A,typename B> istream& operator>>(istream& cin,pair<A,B> &p){cin>>p.first;return cin>>p.second;}


mt19937 rng(steady_clock::now().time_since_epoch().count());
//usage just to do rng()

void usaco(string filename){
    //pragma message be careful freopen can be wrong
freopen((filename+".in").c_str(),"r",stdin);
freopen((filename+".out").c_str(),"w",stdout);
}
const lld pi=3.1415926535897932384626;
const ll mod=998244353;

bool cmp(pll a,pll b){
    return a.s<b.s;
}

namespace modop{
    ll madd(ll a, ll b){
        return (a+b)%mod;
    }
    ll msub(ll a, ll b){
        return (((a-b)%mod)+ mod)%mod;
    }
    ll mmul(ll a, ll b){
        return ((a%mod)*(b%mod))%mod;

    }
    ll mpow(ll base,ll exp){
        ll res=1;
        while(exp){
            if(exp%2==1){
                 res=(res*base)%mod;}
            
            exp>=1;
            base=(base*base)%mod;
        }
        return res;
    }
    ll minv(ll base){
        return mpow(base,mod-2);
    }
    ll mdiv(ll a,ll b){
        return mmul(a,minv(b));
    }
}
using namespace modop;
ll n,m,k,q,l,r,x,y,z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s,t;
ll ans=0;
pll seg[3005];
int dp[3005][3005];
vi rig[6005];


vpl edges[100005];
ll nleaf[100005];
ll wt[100005];



bool cmp(pii& a, pii& b) {
    return a.second < b.second;
}



void solve(int tc){  //robbing houses problem where u can't rob 2 near houses and each house has an amout of money
    cin>>n;
    f0r(i,n){
        cin>>y;
        a[i]=y; //array contains the money each house has
    }
    if(n==1){
        cout<<a[0]<<endl;
        
    }
    b[0]=a[0];
    b[1]=max(a[0],a[1]);
    f0r(i,n){
        b[i]=max(b[i-1],b[i-2]+a[i]); //to rob or not to rob that house 
    }
    cout<<b[n-1]<<endl;
}
int main(){
    #ifdef chadi_local 
    auto begin = std::chrono::high_resolution_clock::now();
    #endif
    send
     help
    int tc=1;
    cin>>tc;
    for(int t=0;t<tc;t++){
        solve(t);
    }
    #ifdef chadi_local
    auto end = std::chrono::high_resolution_clock::now();
    cout<<setprecision(4)<<fixed;
    //cout<< "execution time "<< std::chrono::duration_cast<std::chrono::duration<double>>(end-begin).count() << "s\n";
    #endif 
}