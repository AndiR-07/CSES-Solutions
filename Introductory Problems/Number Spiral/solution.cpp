#include <iostream>

using namespace std;
typedef long long ll;

ll q, x, y;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin>>q;
    while (q--){
        cin>>x>>y;
        ll sp=max(x, y);
        ll st=(sp-1)*(sp-1);
        if (sp%2==0)
            swap(x, y);
        if (x==sp)
            cout<<st+y<<'\n';
        else cout<<st+2*sp-x<<'\n';
    }

    return 0;
}
