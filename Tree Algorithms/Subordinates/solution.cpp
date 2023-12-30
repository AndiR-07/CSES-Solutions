#include <iostream>
#include <vector>
 
#define pb push_back
using namespace std;
const int Nmax=2e5;
 
int n, nr;
int sol[Nmax];
 
vector <int> ad[Nmax];
 
void dfs(int nod){
    if (ad[nod].size()==0)
        return;
    for (auto it:ad[nod]){
        dfs(it);
        sol[nod]+=sol[it]+1;
    }
}
 
int main(){
    cin>>n;
    for (int i=1; i<n; i++){
        cin>>nr; nr--;
        ad[nr].pb(i);
    }
    dfs(0);
    for (int i=0; i<n; i++)
        cout<<sol[i]<<' ';
 
    return 0;
}
