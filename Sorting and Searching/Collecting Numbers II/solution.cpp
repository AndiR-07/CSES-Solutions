#include <iostream>
#include <cmath>
 
using namespace std;
const int Nmax=2e5;
 
int n, m, fr[Nmax+1], sol, v[Nmax+1], pos[Nmax+1];
 
int main()
{
    pos[0]=-1; pos[n+1]=n;
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>v[i];
        pos[v[i]]=i;
        if (fr[v[i]-1]==0)
            sol++;
        fr[v[i]]=1;
    }
    int a, b, si, sf;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        a=v[a-1]; b=v[b-1];
        if (a>b)
            swap(a, b);
        si=(pos[a-1]<pos[a])+(pos[a]<pos[a+1])+(pos[b]<pos[b+1]);
        if (abs(a-b)!=1)
            si+=pos[b-1]<pos[b];
        swap(v[pos[a]], v[pos[b]]);
        swap(pos[a], pos[b]);
        sf=(pos[a-1]<pos[a])+(pos[a]<pos[a+1])+(pos[b]<pos[b+1]);
        if (abs(a-b)!=1)
            sf+=pos[b-1]<pos[b];
        sol-=sf-si;
        cout<<sol<<'\n';
    }
    return 0;
}
