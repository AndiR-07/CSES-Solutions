#include <iostream>

using namespace std;
typedef long long ll;

struct point{
    ll x, y;
};

// referencing point A to BC line
// >0 -> left side; 0 -> on it; <0 -> right side
ll det(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int t;
point a, b, c;

int main(){
    cin>>t;
    while (t--){
        cin>>b.x>>b.y>>c.x>>c.y>>a.x>>a.y;
        ll d=det(a, b, c);
        if (d>0)
            cout<<"LEFT\n";
        else if (d==0)
            cout<<"TOUCH\n";
        else cout<<"RIGHT\n";
    }

    return 0;
}
