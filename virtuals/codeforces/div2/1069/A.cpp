#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n; cin >> n;
    set<int> st;
    rep(i, 0, n){
        int x; cin >> x;
        st.insert(x);
    }

    int lst = -1;
    while(sz(st) != lst){
        lst = sz(st);
        int x = sz(st);
        st.insert(x);
    }

    cout << lst << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}