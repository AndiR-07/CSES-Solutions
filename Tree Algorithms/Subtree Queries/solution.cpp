#include <iostream>
#include <vector>
 
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
using namespace std;
typedef unsigned long long ll;
const ll Nmax=2e5+5;
using pii=pair<ll, ll>;
 
struct AIB{
    ll v[Nmax];
 
    void update(ll pos, ll val){
        while (pos<Nmax){
            v[pos]+=val;
            pos+=pos&-pos;
        }
    }
    ll querry(ll l, ll r){
        ll sol=0;
        while (r>0){
            sol+=v[r];
            r-=r&-r;
        }
        l--;
        while (l>0){
            sol-=v[l];
            l-=l&-l;
        }
        return sol;
    }
} aib;
 
vector <ll> ad[Nmax];
ll v[Nmax], crt;
pii range[Nmax];
 
void dfs(ll nod, ll p){
    crt++;
    range[nod].fi=crt;
    for (auto it:ad[nod])
        if (it!=p)
            dfs(it, nod);
    range[nod].se=crt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n, q;
    cin>>n>>q;
 
    for (ll i=1; i<=n; i++)
        cin>>v[i];
 
    ll a, b;
    for (ll i=0; i<n-1; i++){
        cin>>a>>b;
        ad[a].pb(b);
        ad[b].pb(a);
    }
 
    dfs(1, 0);
 
    for (ll i=1; i<=n; i++)
        aib.update(range[i].fi, v[i]);
 
    ll t, nod, x;
    for (ll i=0; i<q; i++){
        cin>>t>>nod;
        if (t==2)
            cout<<aib.querry(range[nod].fi, range[nod].se)<<'\n';
        else{
            cin>>x;
            aib.update(range[nod].fi, x-aib.querry(range[nod].fi, range[nod].fi));
        }
    }
    return 0;
}
