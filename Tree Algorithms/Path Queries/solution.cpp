//https://cses.fi/problemset/task/1138
#include <iostream>
#include <vector>
 
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll Nmax=2e5+5;
 
ll n, q, v[Nmax], t=1;
vector<ll> ad[Nmax];
pll range[Nmax];
 
struct FenwickTree{
    ll v[Nmax];
 
    void _add(ll pos, ll val){
        while (pos<=n){
            v[pos]+=val;
            pos+=(pos&(-pos));
        }
    }
    void add(ll l, ll r, ll val){
        _add(l, val);
        _add(r+1, -val);
    }
 
    ll _get(ll pos){
        ll ans=0;
        while (pos>0){
            ans+=v[pos];
            pos-=(pos&(-pos));
        }
        return ans;
    }
}aib;
 
inline void dfs(ll nod, ll p){
    range[nod].fi=t;
    for (auto it: ad[nod])
        if (it!=p)
            dfs(it, nod);
    range[nod].se=t;
    t++;
 
    aib.add(range[nod].fi, range[nod].se, v[nod]);
}
 
int main(){
    cin>>n>>q;
 
    for (ll i=0; i<n; i++)
        cin>>v[i];
    for (ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        x--; y--;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
 
    dfs(0, -1);
 
    for (ll i=0; i<q; i++){
        ll tp, x, y;
        cin>>tp>>x; x--;
        if (tp==1){
            cin>>y;
            aib.add(range[x].fi, range[x].se, y-v[x]);
            v[x]=y;
        }
        else cout<<aib._get(range[x].se)<<"\n";
    }
 
    return 0;
}
