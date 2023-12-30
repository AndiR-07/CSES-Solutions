#include <iostream>
 
using namespace std;
typedef long long ll;
const int Nmax=20;
 
ll v[Nmax], n, sum, sol;
 
void bkt(ll i, ll s){
    if (s>sum/2)
        return;
    if (i==n){
        sol=max(sol, s);
        return;
    }
    bkt(i+1, s);
    bkt(i+1, s+v[i]);
}
 
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }
    bkt(0, 0);
    cout<<sum-2*sol;
 
    return 0;
}
