#include <iostream>

using namespace std;
typedef long long ll;

ll n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    while (n!=1){
        cout<<n<<' ';
        if (n%2==0)
            n/=2;
        else n=n*3+1;
    }
    cout<<1;

    return 0;
}
