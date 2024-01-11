#include <iostream>
 
using namespace std;
const int Nmax=2e5;
 
int n, fr[Nmax+1], sol;
 
int main()
{
    cin>>n;
    int nr;
    for (int i=0; i<n; i++){
        cin>>nr;
        if (fr[nr-1]==0)
            sol++;
        fr[nr]=1;
    }
    cout<<sol;
    return 0;
}
