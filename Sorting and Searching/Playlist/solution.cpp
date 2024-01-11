#include <iostream>
#include <map>
#include <deque>
 
using namespace std;
const int Nmax=2e5+5;
int n, v[Nmax], mx;
map<int, bool> mp;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int p1=0, p2=0;
    cin>>n;
    for (int p2=0; p2<n; p2++){
        cin>>v[p2];
        while (mp[v[p2]]){
            mp[v[p1]]=false;
            p1++;
        }
        mp[v[p2]]=true;
        mx=max(mx, p2-p1+1);
    }
    cout<<mx;
    return 0;
}
