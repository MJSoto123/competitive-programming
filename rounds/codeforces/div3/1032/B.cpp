#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    st.insert(s[0]);
    st.insert(s[n - 1]);
    for(int i = 1; i < n - 1; i++){
        if(st.count(s[i])){ cout << "Yes\n"; return; }
        st.insert(s[i]);
    }   

    cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}