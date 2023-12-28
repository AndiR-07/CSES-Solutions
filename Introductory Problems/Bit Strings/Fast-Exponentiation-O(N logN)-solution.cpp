#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll n;
ll pow(ll b, ll e){
    if (e==0)
        return 1;
    if (e%2==0)
        return pow(b*b%MOD, e/2);
    return b*pow(b, e-1)%MOD;
}

int main(){
    cin>>n;
    cout<<pow(2, n);

    return 0;
}
