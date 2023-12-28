#include <iostream>

using namespace std;

string s, sol;
char lch;
int fr[256];

int main(){
    cin>>s;
    for (auto it:s)
        fr[it]++;
    int cnt=0;
    for (int i=0;i<256;i++){
        if (fr[i]%2==1){
            cnt++;
            lch=(char)i;
        }
        else if (fr[i]>0)
            for (int j=0;j<fr[i]/2;j++)
                sol+=(char)i;
    }
    if (cnt>1)
        cout<<"NO SOLUTION";
    else if (cnt==1){
        cout<<sol;
        for (int i=0; i<fr[lch]; i++)
            cout<<lch;
        for (int i=sol.size()-1;i>=0;i--)
            cout<<sol[i];
    }
    else{
        cout<<sol;
        for (int i=sol.size()-1;i>=0;i--)
            cout<<sol[i];
    }

    return 0;
}
