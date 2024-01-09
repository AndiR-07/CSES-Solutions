#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int Nmax=2e5;

int n;
int v[Nmax];
ll ex=1;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i];
    sort(v, v+n);
    for (int i=0; i<n; i++){
        if (v[i]>ex)
            break;
        ex+=v[i];
    }
    cout<<ex;
    return 0;
}
