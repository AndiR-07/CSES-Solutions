#include <iostream>
#include <algorithm>

#define fi first
#define se second
using namespace std;
const int Nmax=2e5+5;
typedef pair<int, int> pii;

int n, mx, nr, crt;
pii v[2*Nmax];

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>v[i*2].fi>>v[i*2+1].fi;
        v[i*2].se=1; v[i*2+1].se=-1;
    }
    sort(v, v+2*n);
    int i=0;
    while (i<2*n){
        nr=v[i].fi;
        while (i<2*n && v[i].fi==nr){
            crt+=v[i].se;
            i++;
        }
        if (crt>mx)
            mx=crt;
    }
    cout<<mx;

    return 0;
}
