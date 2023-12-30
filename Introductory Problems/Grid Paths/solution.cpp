#include <iostream>

#pragma GCC optimise ("O3")

using namespace std;
const int N=7;

string s;
int sol, ind, vl[]={0, 1, 0, -1}, vc[]={1, 0, -1, 0}, cnt;
int cnv[256];
bool mat[N+2][N+2];

inline void dfs(int i, int j){
    /*cout<<ind<<'\n';
    for (int i=0; i<=N+1; i++){
        for (int j=0; j<=N+1; j++)
            cout<<mat[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';*/
    if (i==N && j==1){
        mat[i][j]=0;
        if (ind==N*N-1)
            sol++;
        return;
    }
    if (ind==N*N-1){
        mat[i][j]=0;
        return;
    }
    int cnt=0;
    for (int k=0; k<4; k++){
        int l=i+vl[k];
        int c=j+vc[k];
        cnt+=mat[l][c];
    }
    if (cnt==2 && mat[i+vl[0]][j+vc[0]]==mat[i+vl[2]][j+vc[2]]){
        mat[i][j]=0;
        return;
    }

    ind++;
    if (s[ind-1]=='?')
        for (int k=0; k<4; k++){
            int l=i+vl[k];
            int c=j+vc[k];
            if (!mat[l][c]){
                mat[l][c]=1;
                dfs(l, c);
                mat[l][c]=0;
            }
        }
    else{
        int k=cnv[s[ind-1]];
        int l=i+vl[k];
        int c=j+vc[k];
        if (!mat[l][c]){
            mat[l][c]=1;
            dfs(l, c);
            mat[l][c]=0;
        }
    }
    ind--;
    mat[i][j]=0;
}

int main(){
    cnv['R']=0; cnv['D']=1; cnv['L']=2; cnv['U']=3;

    cin>>s;
    for (int i=0; i<=N+1; i++)
        mat[0][i]=mat[N+1][i]=mat[i][0]=mat[i][N+1]=1;
    mat[1][1]=1;
    dfs(1, 1);
    cout<<sol;

    return 0;
}
