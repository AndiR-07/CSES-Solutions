#include <iostream>

using namespace std;
const int Nmax=1e3;
const int inf=1e9;
typedef long long ll;

struct point{
    ll x, y;
};
// we presume that the segment formed betwwen this point and another one do not have a point of the polygon in it
// for this instance we are right and we got "lucky" but usually we will randomly generate points untill the condition holds true 
const point P={inf, inf-1};

// sign function
int sgn(ll nr){
    if (nr>0)
        return 1;
    else if (nr==0)
        return 0;
    return -1;
}
// referencing point A to BC line
// >0 -> left side; 0 -> on it; <0 -> right side
ll det(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
// check if segments AB and CD intersect
bool DoSegInt(point a, point b, point c, point d){
    //we presume that the end of a segment is not on the other segment
    // check if the points of each segment are on different sides of the other segment i.e. determinants have different signs
    // sgn function prevents overflow
    return (sgn(det(a, c, d))*sgn(det(b, c, d))<0 && sgn(det(c, a, b))*sgn(det(d, a, b))<0);
}
// check if point P is in polygon v with n vertices
// 0 -> outside; 1 -> inside; 2 -> on boundary
int IsInPolygon(point p, point v[], int n){
    bool bound=0;
    int i=0, cnt=0;
    while (i<n && !bound){
        if (det(p, v[i], v[i+1])==0 && min(v[i].x, v[i+1].x)<=p.x && p.x<=max(v[i].x, v[i+1].x) && min(v[i].y, v[i+1].y)<=p.y && p.y<=max(v[i].y, v[i+1].y))
            bound=1;
        else if (DoSegInt(p, P, v[i], v[i+1]))
            cnt++;
        i++;
    }
    if (bound)
        return 2;
    // if the number of polygon edges intersected by the ray i.e. cnt is odd then the point is inside the polygon
    return cnt%2;
}

int n, m;
point v[Nmax+1], w[Nmax];

int main(){
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;
    v[n]=v[0];
    for (int i=0; i<m; i++){
        cin>>w[i].x>>w[i].y;
        int ans=IsInPolygon(w[i], v, n);
        if (ans==0)
            cout<<"OUTSIDE\n";
        else if (ans==1)
            cout<<"INSIDE\n";
        else cout<<"BOUNDARY\n";
    }

    return 0;
}
