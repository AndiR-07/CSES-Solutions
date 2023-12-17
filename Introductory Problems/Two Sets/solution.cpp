#include <iostream>

using namespace std;
typedef long long ll;
const ll Nmax=1e6+5;

ll n, sz, s, nr;
bool fr[Nmax];

int main(){
    cin>>n;
    if (n*(n+1)/2%2==1)
        cout<<"NO";
    else{
        nr=n;
        while (s+nr<n*(n+1)/4){
            s+=nr;
            sz++;
            fr[nr]=1;
            nr--;
            
        }
        fr[n*(n+1)/4-s]=1;
        sz++;
        cout<<"YES\n"<<sz<<'\n';
        for (ll i=1; i<=n; i++)
            if (fr[i])
                cout<<i<<' ';
        cout<<'\n'<<n-sz<<'\n';
        for (ll i=1; i<=n; i++)
            if (fr[i]==0)
                cout<<i<<' ';
    }

    return 0;
}
