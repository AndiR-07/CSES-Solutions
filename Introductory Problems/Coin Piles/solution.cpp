#include <iostream>

using namespace std;

int t, a, b;

int main(){
    cin>>t;
    while (t--){
        cin>>a>>b;
        if (a<b)
            swap(a, b);
        if ((a+b)%3==0 && 2*b>=a)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
