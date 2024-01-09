#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int Nmax=2e5;

int n, f;
int v[Nmax];
ll s;
double sum;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i];
    sort(v, v+n);
    f=v[n/2];
    for (int i=0; i<n; i++)
        s+=abs(f-v[i]);
    cout<<s;
    return 0;
}
