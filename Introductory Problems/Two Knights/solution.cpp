#include <iostream>

#pragma GCC optimize("Ofast")

using namespace std;
typedef long long ll;

ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (ll i=1; i<=n; i++)
        cout<<i*i*(i*i-1)/2-4*(i-2)*(i-1)<<'\n';

    return 0;
}
