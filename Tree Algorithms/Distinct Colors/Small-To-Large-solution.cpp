#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <vector>
#include <unordered_set>
 
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
 
using namespace std;
ifstream fin ("");
ofstream fout ("");
typedef long long ll;
const ll Nmax=1e6+5, inf=1e9+5;
using pii=pair<int, int>;
 
int n, sol[Nmax];
unordered_set <int> st[Nmax];
vector <int> ad[Nmax];
 
void dfs(int nod, int p){
    for (auto it:ad[nod])
        if (it!=p){
            dfs(it, nod);
            if (st[nod].size()<st[it].size())
                swap(st[nod], st[it]);
            for (auto c:st[it])
                st[nod].insert(c);
        }
    sol[nod]=st[nod].size();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    int nr;
    for (int i=1; i<=n; i++){
        cin>>nr;
        st[i].insert(nr);
    }
    int a, b;
    for (int i=0; i<n-1; i++){
        cin>>a>>b;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    dfs(1, 0);
 
    for (int i=1; i<=n; i++)
        cout<<sol[i]<<' ';
    return 0;
}
