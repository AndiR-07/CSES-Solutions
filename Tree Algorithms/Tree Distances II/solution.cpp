#include <iostream>
#include <vector>
 
#define pb push_back
using namespace std;
typedef long long ll;
const int Nmax=2e5;
 
int n, nr;
ll des[Nmax]; // no. of nodes in subtree
ll dp1[Nmax]; // sum for subtree nodes
ll dp2[Nmax]; // sum for non-subtree nodes
 
vector <int> ad[Nmax];
 
void dfs1(int nod, int p){
    des[nod]=1;
    for (auto it:ad[nod])
        if (it!=p){
            dfs1(it, nod);
            des[nod]+=des[it];
            dp1[nod]+=dp1[it]+des[it];
        }
}
void dfs2(int nod, int p){
    ll sum=dp1[nod]+dp2[nod];
    for (auto it:ad[nod])
        if (it!=p){
            dp2[it]=sum-dp1[it]-des[it]+n-des[it];
            dfs2(it, nod);
        }
}
 
int main(){
    cin>>n;
    int a, b;
    for (int i=1; i<n; i++){
        cin>>a>>b;
        a--; b--;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    
    for (int i=0; i<n; i++)
        cout<<dp1[i]+dp2[i]<<' ';
 
    return 0;
}
