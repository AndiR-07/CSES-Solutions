#include <iostream>

using namespace std;
typedef long long ll;
const int Nmax=2e5+5;

int n, v[Nmax];
ll sol;

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i];
    for (int i=1; i<n; i++)
        if (v[i]<v[i-1]){
            sol+=v[i-1]-v[i];
            v[i]=v[i-1];
        }
    cout<<sol;
    return 0;
}
