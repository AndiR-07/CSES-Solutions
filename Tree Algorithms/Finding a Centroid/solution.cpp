//https://cses.fi/problemset/task/2079
#include <iostream>
#include <vector>
 
#define pb push_back
using namespace std;
const int Nmax=2e5+5;
 
int n, w[Nmax];
vector<int> ad[Nmax];
 
void get_w(int node, int p){
    for (auto it:ad[node])
        if (it!=p){
            get_w(it, node);
            w[node]+=w[it];
        }
    w[node]++;
}
int get_centroid(int node, int p){
    for (auto it:ad[node])
        if (it!=p && w[it]>n/2)
            return get_centroid(it, node);
    return node;
}
 
int main(){
    cin>>n;
    int a, b;
    for (int i=0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        ad[a].pb(b);
        ad[b].pb(a);
    }
 
    get_w(0, -1);
    cout<<get_centroid(0, -1)+1;
 
    return 0;
}
