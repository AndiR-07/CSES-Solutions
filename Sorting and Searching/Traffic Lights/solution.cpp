#include <iostream>
#include <set>
 
using namespace std;
 
int n, nr, x;
set<int> st;
multiset<int> dist;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>x>>n;
    st.insert(0); st.insert(x);
    dist.insert(x);
    for (int i=0; i<n; i++){
        cin>>nr;
        auto it1=st.upper_bound(nr);
        auto it2=it1; it1--;
        //cout<<*it1<<' '<<*it2<<'\n';
        dist.erase(dist.lower_bound(*it2-*it1));
        dist.insert(nr-*it1);
        dist.insert(*it2-nr);
        st.insert(nr);
        cout<<*dist.rbegin()<<' ';
    }
 
    return 0;
}
