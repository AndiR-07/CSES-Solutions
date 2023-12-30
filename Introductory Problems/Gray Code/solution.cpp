#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

int n;
vector<string> sol;

int main(){
    cin>>n;
    sol.pb("");
    for (int i=0; i<n; i++){
        int sz=(1<<i);
        for (int j=sz-1; j>=0; j--)
            sol.pb(sol[j]+'1');
        for (int j=0; j<sz; j++)
            sol[j]+='0';
    }
    for (auto it:sol)
        cout<<it<<'\n';

    return 0;
}
