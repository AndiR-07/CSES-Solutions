#include <iostream>
#include <vector>

#define pb push_back
using namespace std;
const int Nmax=2e5+5, LgNmax=18;

int n, q;
vector<int> ad[Nmax];
int h[Nmax];
int bl[Nmax][LgNmax];

// get heights
void dfs(int nod, int p){
    h[nod]=h[p]+1;
    // binarry lifting
    bl[nod][0]=p;
    for (int i=1; i<LgNmax; i++)
        bl[nod][i]=bl[bl[nod][i-1]][i-1];
    for (auto it:ad[nod])
        if (it!=p)
            dfs(it, nod);
}
// get k'th ancestor
int get_p(int nod, int k){
    if (h[nod]<k)
        return -1;
    int p=(1<<17);
    for (int i=LgNmax-1; i>=0; i--){
        if (k>=p){
            k-=p;
            nod=bl[nod][i];
        }
        p/=2;
    }
    return nod;
}
// lowest common ancestor between a and b
int lca(int a, int b){
    if (h[a]<h[b])
        swap(a, b);
    a=get_p(a, h[a]-h[b]);
    
    if (a==b)
        return a;
    for (int i=LgNmax-1; i>=0; i--)
        if (bl[a][i]!=bl[b][i]){
            a=bl[a][i];
            b=bl[b][i];
        }
    return bl[a][0];
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin>>n>>q;
    int nr;
    for (int i=1; i<n; i++){
        cin>>nr; nr--;
        ad[i].pb(nr);
        ad[nr].pb(i);
    }

    h[0]=-1;
    dfs(0, 0);

    int a, b;
    for (int i=0; i<q; i++){
        cin>>a>>b;
        a--; b--;
        cout<<lca(a, b)+1<<'\n';
    }

    return 0;
}
