#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;
using ll = long long; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    set<int> st;
    map<int, int> mp;
    rep(i, 0, k + 2) st.insert(i);
    rep(i, 0, n){
        if(st.count(a[i])) st.erase(a[i]);
        mp[a[i]]++;
        if(i >= k){
            mp[a[i - k]]--;
            if(mp[a[i - k]] == 0) st.insert(a[i - k]);
        }

        if(i >= k - 1) cout << *st.begin() << " "; 
    }
    cout << "\n";
}