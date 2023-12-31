#include <iostream>
#include <vector>
#include <unordered_map>
 
#pragma GCC optimise("O3")
 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int Nmax=2e5+5;
 
ll sol;
int n, k, w[Nmax], h[Nmax], fr[Nmax], st[Nmax], crt;
bool del[Nmax];
vector<int> ad[Nmax];
 
inline void get_w(int nod, int p){
    w[nod]=1;
    for (auto it:ad[nod])
        if (it!=p && !del[it]){
            get_w(it, nod);
            w[nod]+=w[it];
        }
}
inline int get_centroid(int nod, int p){
    for (auto it:ad[nod])
        if (it!=p && !del[it] && w[it]>n/2)
            return get_centroid(it, nod);
    return nod;
}
inline void get_h(int nod, int p){
    h[nod]=h[p]+1;
    st[crt++]=h[nod];
    if (h[nod]<=k)
        sol+=fr[k-h[nod]];
    for (auto it:ad[nod])
        if (it!=p && !del[it])
            get_h(it, nod);
}
inline void centroid_decomp(int nod){
    get_w(nod, -1);
    n=w[nod];
    int cent=get_centroid(nod, -1);
    h[cent]=0;
    int ant=0;
    for (auto it:ad[cent])
        if (!del[it]){
            get_h(it, cent);
            for (int i=ant; i<crt; i++)
                fr[st[i]]++;
            ant=crt;
        }
    for (int i=0; i<crt; i++)
        fr[st[i]]--;
    crt=0;
    del[cent]=1;
    for (auto it:ad[cent])
        if (!del[it])
            centroid_decomp(it);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin>>n>>k;
    int a, b;
    for (int i=0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    fr[0]=1;
    centroid_decomp(0);
    cout<<sol;
 
    return 0;
}
