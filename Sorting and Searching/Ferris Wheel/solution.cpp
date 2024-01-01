#include <iostream>
#include <algorithm>

using namespace std;
const int Nmax=2e5+5;

int n, x, sol, p1, p2;
int v[Nmax];

int main(){
    cin>>n>>x;
    for (int i=0; i<n; i++)
        cin>>v[i];
    sort(v, v+n);
    p1=0; p2=n-1;
    while (p1<p2){
        sol++;
        if (v[p1]+v[p2]>x)
            p2--;
        else{
            p1++;
            p2--;
        }
    }
    if (p1==p2)
        sol++;
    cout<<sol;

    return 0;
}
