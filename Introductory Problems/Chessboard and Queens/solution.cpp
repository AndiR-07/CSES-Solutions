#include <iostream>

using namespace std;
const int N=8;

string mat[N];
int lin[N], col[N], d1[2*N], d2[2*N], sol;

void bkt(int ind, int i){
    if (ind==N){
        sol++;
        return;
    }
    if (i==N*N)
        return;
    bkt(ind, i+1);
    if (mat[i/N][i%N]=='.' && lin[i/N]==0 && col[i%N]==0 && d1[i/N-i%N+N-1]==0 && d2[i/N+i%N]==0){
        lin[i/N]=1; 
        col[i%N]=1;
        d1[i/N-i%N+N-1]=1; 
        d2[i/N+i%N]=1;
        bkt(ind+1, i+1);
        lin[i/N]=0; 
        col[i%N]=0;
        d1[i/N-i%N+N-1]=0; 
        d2[i/N+i%N]=0;
    }
}

int main(){
    for (int i=0; i<N; i++)
        cin>>mat[i];
    bkt(0, 0);
    cout<<sol;

    return 0;
}
