#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>

#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
const ll Nmax=2e5, inf=1e9;

struct point{
    ll x, y;
};
struct cmpy{
    bool operator()(const point &a, const point &b) const{
        if (a.y!=b.y)
            return a.y<b.y;
        return a.x<b.x;
    }
};

ll n, dist=inf*inf*8;
point v[Nmax];
set <point, cmpy> st;

bool cmpx(point a, point b){
    return a.x<b.x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;
    sort(v, v+n, cmpx);
    for (int i=0; i<n; i++){
        auto it=st.lower_bound({-inf, v[i].y-sqrt(dist)});
        if (it==st.end() && i==1)
            cout<<1;
        while (it!=st.end() && it->y<=v[i].y+dist){
            dist=min(dist, (v[i].x-it->x)*(v[i].x-it->x)+(v[i].y-it->y)*(v[i].y-it->y));
            if (v[i].x-it->x > sqrt(dist))
                it=st.erase(it);
            else it++;
        }
        st.insert(v[i]);
    }
    cout<<dist;

    return 0;
}
