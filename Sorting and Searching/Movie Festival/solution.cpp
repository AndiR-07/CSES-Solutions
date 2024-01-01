#include <iostream>
#include <algorithm>

#define fi first
#define se second
using namespace std;
const int Nmax=2e5+5;
typedef pair<int, int> pii;

int n, mx, nr, crt, sol;
pii v[Nmax];

bool cmp(pii a, pii b){
    return a.se<b.se;
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i].fi>>v[i].se;
    sort(v, v+n, cmp);
    for (int i=0; i<n; i++)
        if (v[i].fi>=crt){
            sol++;
            crt=v[i].se;
        }
    cout<<sol;

    return 0;
}
