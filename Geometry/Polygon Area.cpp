#include <iostream>

using namespace std;
const int Nmax=1e3;
typedef long long ll;

struct point{
    ll x, y;
};

// referencing point A to BC line
// >0 -> left side; 0 -> on it; <0 -> right side
ll det(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
// determines the area of a polygon using shoelace formula
ll PolygonArea(point v[], int n){
    ll sol=0;
    for (int i=1; i<n-1; i++)
        sol+=det(v[0], v[i], v[i+1]);
    return abs(sol);
}

int n;
point v[Nmax+1];

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;
    v[n]=v[0];
    cout<<PolygonArea(v, n);

    return 0;
}
