#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll sol;
string s;

int main(){

    cin>>s;
    while (next_permutation(s.begin(), s.end()));
    do sol++;
    while (next_permutation(s.begin(), s.end()));
    cout<<sol<<'\n';
    do cout<<s<<'\n';
    while (next_permutation(s.begin(), s.end()));

    return 0;
}
