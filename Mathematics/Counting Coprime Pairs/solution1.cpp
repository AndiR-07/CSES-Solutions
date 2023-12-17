//we use Sieve of Eratosthenes in order to factorize each number
//then we use the inclusion-exclusion principle to count the number of pairs that are coprime
//time complexity: O(n * log(n) + n*2^(nr of prime factors ~ 7))

#include <iostream>

using namespace std;
typedef long long ll;
const ll Vmax=1e6+5, MxNrofPrimeFactors=7;

ll n, nr, nrfp, sol;
ll sieve[Vmax], fp[MxNrofPrimeFactors], mult[Vmax];

void pinex(ll i, ll sgn, ll prod){
    if (i==nrfp){
        sol+=sgn*mult[prod];
        mult[prod]++;
        return;
    }
    pinex(i+1, sgn, prod);
    pinex(i+1, -sgn, prod*fp[i]);
}

int main(){
    // Sieve of Eratosthenes in order to find the first prime factor of each number
    sieve[1]=1;
    for (ll i=2; i<Vmax; i++)
        if (sieve[i]==0)
            for (ll j=i; j<Vmax; j+=i)
                sieve[j]=i;

    cin>>n;
    for (ll i=0; i<n; i++){
        cin>>nr;
        nrfp=0;
        while (nr!=1){
            if (nrfp==0 || fp[nrfp-1]!=sieve[nr])
                fp[nrfp++]=sieve[nr];
            nr/=sieve[nr];
        }
        pinex(0, 1, 1);
    }
    cout<<sol;
    

    return 0;
}
