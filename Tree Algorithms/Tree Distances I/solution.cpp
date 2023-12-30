#include <iostream>
#include <vector>
 
using namespace std;
const int Nmax=200000;
 
int n, dp1[Nmax], dp2[Nmax];
vector <int> ad[Nmax];
 
void dfs1(int node, int p){
    int mx=0;
    for (int i=0; i<ad[node].size(); i++)
        if (ad[node][i]!=p){
            dfs1(ad[node][i], node);
            if (dp1[ad[node][i]]+1>mx)
                mx=dp1[ad[node][i]]+1;
        }
    dp1[node]=mx;
}
void dfs2(int node, int p){
    int mx1=-1, mx2=-1, pos;
    for (int i=0; i<ad[node].size(); i++){
        int crt=ad[node][i];
        if (crt!=p){
            if (dp1[crt]>mx1){
                mx2=mx1;
                mx1=dp1[crt];
                pos=crt;
            }
            else if (dp1[crt]>mx2)
                mx2=dp1[crt];
        }
    }
    for (int i=0; i<ad[node].size(); i++){
        int crt=ad[node][i];
        if (crt!=p){
            if (crt==pos){
                dp2[crt]=max(dp2[node]+1, mx2+2);
            }
            else{
                dp2[crt]=max(dp2[node]+1, mx1+2);
            }
            dfs2(crt, node);
        }
    }
}
int main()
{
    cin>>n;
    int a, b;
    for (int i=1; i<n; i++){
        cin>>a>>b;
        a--; b--;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i=0; i<n; i++)
        cout<<max(dp1[i], dp2[i])<<' ';
    return 0;
}
