#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    string s; cin >> s;
    int n = sz(s);

    vi a, b, both;
    int cnt = 0;
    int lst = -1;
    char c;
    rep(i, 0, n){
        if(s[i] == '.') continue;
        cnt++;
        if(cnt % 2 == 1){
            lst = i;
            c = s[i];
        }else{
            int d = i - lst - 1;
            lst = -1;
            if(d == 0) continue;
            
            if(c != s[i]) both.emplace_back(d);
            else if(c == 'A') a.emplace_back(d);
            else b.emplace_back(d);
        }
    }
    if(lst != -1){
        if(c == 'A') a.emplace_back(n - 1 - lst);
        else b.emplace_back(n - 1 - lst);
    }

    int sma = accumulate(all(a), 0);
    int smb = accumulate(all(b), 0);
    int winner = 0;
    for(auto x : both) winner ^= x;

    if(winner) sma++;

    if(sma > smb) cout << "A\n";
    else cout << "B\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}