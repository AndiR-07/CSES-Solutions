#include <iostream>

using namespace std;
typedef long long ll;

ll n, sol;

int main(){
    cin>>n;
    ll p=5;
    while (p<=n){
        sol+=n/p;
        p*=5;
    }
    cout<<sol;

    return 0;
}
