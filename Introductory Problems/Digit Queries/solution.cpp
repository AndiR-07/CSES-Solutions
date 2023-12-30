#include <iostream>

using namespace std;
typedef long long ll;

int q;
ll digit, ub, nrd, p, r, d, p2;

int main(){
    cin>>q;
    for (int i=0; i<q; i++){
        cin>>digit;
        ub=0; nrd=1; p=9, p2=1;
        while (ub+nrd*p<digit){
            ub+=nrd*p;
            p*=10;
            p2*=10;
            nrd++;
        }
        digit-=ub;
        d=(digit-1)/nrd; // d'th number with nrd digits
        r=(digit-1)%nrd; // r'th digit of the d'th number with nrd digits
        r=nrd-r;
        p2+=d;
        for (int i=1; i<r; i++)
            p2/=10;
        cout<<p2%10<<'\n';
    }

    return 0;
}
