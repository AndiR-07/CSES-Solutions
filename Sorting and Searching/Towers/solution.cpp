#include <iostream>
#include <set>

using namespace std;

int n, nr;
multiset<int> st;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>nr;
        auto it=st.upper_bound(nr);
        if (it!=st.end())
            st.erase(it);
        st.insert(nr);
    }
    cout<<st.size();

    return 0;
}
