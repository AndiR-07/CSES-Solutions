#include <iostream>
#include <set>

using namespace std;

int n, m;
multiset<int> st;

int main(){
    cin>>n>>m;
    int nr;
    for (int i=0; i<n; i++){
        cin>>nr;
        st.insert(nr);
    }
    for (int i=0; i<m; i++){
        cin>>nr;
        auto it=st.upper_bound(nr);
        if (it==st.begin())
            cout<<"-1\n";
        else{
            it--;
            cout<<*it<<'\n';
            st.erase(it);
        }
    }   

    return 0;
}
