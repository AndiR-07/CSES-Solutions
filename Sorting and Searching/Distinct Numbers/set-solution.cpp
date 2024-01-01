#include <iostream>
#include <set>

using namespace std;
const int Nmax=2e5+5;

int n, v[Nmax];
set <int> st;

int main(){
    cin>>n;
    int nr;
    for (int i=0; i<n; i++){
        cin>>nr;
        st.insert(nr);
    }
    cout<<st.size();

    return 0;
}
