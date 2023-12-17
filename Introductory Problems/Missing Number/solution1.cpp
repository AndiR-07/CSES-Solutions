//solved using a frequency array

#include <iostream>

using namespace std;
const int Nmax=2e5+5;

int n;
bool fr[Nmax];

int main(){
    cin>>n;
    for (int i=1; i<n; i++){
        int nr;
        cin>>nr;
        fr[nr]=1;
    }
    for (int i=1; i<=n; i++)
        if (!fr[i])
            cout<<i;

    return 0;
}
