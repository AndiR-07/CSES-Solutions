// convex hull using Graham's scan

#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;
typedef long long ll;
const ll Nmax=2e5;

struct point{
    ll x, y;
};

ll n;
point v[Nmax];

// referencing point A to BC line
// >0 -> left side; 0 -> on it; <0 -> right side
ll det(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
// sort by angle and if colinear, by distance
bool cmp(point a, point b){
    ll d=det({0, 0}, a, b);
    if (d!=0)
        return d>0;
    return a.x*a.x+a.y*a.y>b.x*b.x+b.y*b.y;
}
// constructs convex hull of points v[0..n-1]; 
// difx and dify are the coordinates of the lowest point
vector <point> ConvexHull(point v[], ll n, ll &difx, ll &dify){
    vector<point> hull;
    // find the point with lowest y
    ll pos=0;
    for (int i=0; i<n; i++)
        if (v[i].y<v[pos].y || (v[i].y==v[pos].y && v[i].x<v[pos].x))
            pos=i;
    // sort by angle
    swap(v[0], v[pos]);
    difx=v[0].x; dify=v[0].y;
    for (int i=0; i<n; i++){
        v[i].x-=difx;
        v[i].y-=dify;
    }
    sort(v+1, v+n, cmp);
    // reverse first colinear points
    pos=2;
    while (pos<n && det(v[0], v[1], v[pos])==0)
        pos++;
    reverse(v+1, v+pos);
    // build hull
    hull.pb(v[0]); hull.pb(v[1]);
    for (int i=2; i<n; i++){
        while (det(v[i], hull[hull.size()-2], hull.back())<0)
            hull.pop_back();
        hull.pb(v[i]);
    }
    return hull;
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;
    ll difx, dify;
    vector<point> hull=ConvexHull(v, n, difx, dify);
    cout<<hull.size()<<'\n';
    for (auto it:hull)
        cout<<it.x+difx<<' '<<it.y+dify<<'\n';

    return 0;
}
