#include <iostream>

using namespace std;
typedef long long ll;

int n, f, nr;
ll s, mx=-1000000000;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>nr;
        s+=nr;
        if (s>mx)
            mx=s;
        if (s<0)
            s=0;
    }
    cout<<mx;
    return 0;
}
