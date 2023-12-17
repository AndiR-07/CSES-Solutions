#include <iostream>

using namespace std;

string s;

int main(){
    cin>>s;
    int sol=1, crt=1;
    for (int i=1; i<s.size(); i++){
        if (s[i]==s[i-1])
            crt++;
        else{
            sol=max(sol, crt);
            crt=1;
        }
    }
    sol=max(sol, crt);
    cout<<sol;

    return 0;
}
