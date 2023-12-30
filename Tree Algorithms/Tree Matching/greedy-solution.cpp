#include <iostream>
#include <vector>
 
using namespace std;
const int Nmax=200000;
 
int n, used[Nmax]; // edge to him
vector <int> ad[Nmax];
int dfs(int nod, int p){
    int s=0, nru=0;
    for (int i=0; i<ad[nod].size(); i++)
        if (ad[nod][i]!=p){
            s+=dfs(ad[nod][i], nod);
            if (used[ad[nod][i]]==1)
                nru++;
        }
    if (nru>1)
        s-=nru-1;
    if (p!=-1){
        bool cused=0;
        for (int i=0; i<ad[nod].size(); i++){
            if (used[ad[nod][i]]==1)
                cused=1;
        }
        if (!cused){
            used[nod]=1;
            return s+1;
        }
        return s;
    }
    return s;
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
    cout<<dfs(0, -1);
    /*for (int i=0; i<n; i++)
        cout<<used[i]<<' ';*/
    return 0;
}
