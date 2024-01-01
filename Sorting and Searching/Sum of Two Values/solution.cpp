#include <iostream>
#include <algorithm>
 
using namespace std;
const int Nmax=2e5+5;
 
int n, k;
int sol1, sol2;
pair<int, int> v[Nmax];
int main()
{
    cin>>n>>k;
    for (int i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
 
    int p1=0, p2=n-1;
    sort(v, v+n);
    while (p1<p2){
        while (p1<p2 && v[p1].first+v[p2].first>k)
            p2--;
        if (p1<p2 && v[p1].first+v[p2].first==k){
            sol1=v[p1].second;
            sol2=v[p2].second;
            p1++;
        }
        while (p1<p2 && v[p1].first+v[p2].first<k)
            p1++;
    }
    if (sol1==0)
        cout<<"IMPOSSIBLE";
    else cout<<sol1<<' '<<sol2;
    return 0;
}
