#include <iostream>

using namespace std;
typedef long long ll;

struct point{
    ll x, y;
};

// sign function
ll sgn(ll nr){
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
//check if point A is on segment BC
bool IsOnSeg(point a, point b, point c){
    // check if A is on BC line and between B and C
    return (det(a, b, c)==0 && min(b.x, c.x)<=a.x && a.x<=max(b.x, c.x) && min(b.y, c.y)<=a.y && a.y<=max(b.y, c.y));
}
// check if segments AB and CD intersect
bool DoSegInt(point a, point b, point c, point d){
    // check if 2 points from different segments coincide
    if ((a.x==c.x && a.y==c.y) || (a.x==d.x && a.y==d.y) || (b.x==c.x && b.y==c.y) || (b.x==d.x && b.y==d.y))
        return 1;
    // check if a point is on the other segment
    if (IsOnSeg(a, c, d) || IsOnSeg(b, c, d) || IsOnSeg(c, a, b) || IsOnSeg(d, a, b))
        return 1;
    // check if the points of each segment are on different sides of the other segment i.e. determinants have different signs
    // sgn function prevents overflow
    return (sgn(det(a, c, d))*sgn(det(b, c, d))<0 && sgn(det(c, a, b))*sgn(det(d, a, b))<0);
}

int t;
point a, b, c, d;

int main(){
    cin>>t;
    while (t--){
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        if (DoSegInt(a, b, c, d))
            cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
