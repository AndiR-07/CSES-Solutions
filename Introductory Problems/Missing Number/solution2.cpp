// solved using Gauss sum formula

#include <iostream>

using namespace std;
typedef long long ll;
const int Nmax=2e5+5;

int n;
ll s, sg;

int main(){
    cin>>n;
    sg=(ll)n*(n+1)/2;
    for (int i=1; i<n; i++){
        int nr;
        cin>>nr;
        s+=nr;
    }
    cout<<sg-s;

    return 0;
}
