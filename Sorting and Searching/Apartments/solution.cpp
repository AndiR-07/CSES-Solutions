#include <iostream>
#include <algorithm>

using namespace std;
const int Nmax=2e5+5;

int n, m, k, sol;
int des[Nmax], ac[Nmax]; // desired / actual

int main(){
    cin>>n>>m>>k;
    for (int i=0; i<n; i++)
        cin>>des[i];
    sort(des, des+n);
    for (int i=0; i<m; i++)
        cin>>ac[i];
    sort(ac, ac+m);
    int p1=0, p2=0;
    for (int i=0; i<n; i++){
        while (p1<m && ac[p1]+k<des[i])
            p1++;
        while (p2<m && ac[p2]-k<=des[i])
            p2++;
        if (p1!=p2){
            sol++;
            p1++;
        }
    }
    cout<<sol;

    return 0;
}
