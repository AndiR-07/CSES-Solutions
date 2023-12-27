// Pick's theorem states: 2*A=2*I+B-2 => I=(2*A-B+2)/2
// A -> area; 
// I -> number of lattice points inside; 
// B -> number of lattice points on the boundary
#include <iostream>
#include <algorithm>

using namespace std;
const int Nmax=1e5;
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
// determines the number of lattice points on the boundary of a polygon
ll get_B(point v[], int n){
    ll sol=0;
    for (int i=0; i<n; i++){
        ll dx=abs(v[i].x-v[i+1].x), dy=abs(v[i].y-v[i+1].y);
        sol+=__gcd(dx, dy); 
    }
    return sol;
}

ll n, I, B, area;
point v[Nmax+1];

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;
    v[n]=v[0];
    area=PolygonArea(v, n);
    B=get_B(v, n);
    cout<<(area-B+2)/2<<' '<<B;

    return 0;
}
