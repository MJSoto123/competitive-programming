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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a; cin >> a;
    string b; cin >> b;

    int n = sz(a);

    vi dig;
    map<int, int> mp;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 5;
    mp[3] = 3;
    mp[4] = -1;
    mp[5] = 2;
    mp[6] = -1;
    mp[7] = -1;
    mp[8] = 8;
    mp[9] = -1;
    rep(i, 0, n){
        if(b[i] == 'S'){
            dig.emplace_back(a[i] - '0');
            continue;
        }

        int d = a[i] - '0';
        if(d == 3){
            if(b[i] == 'U' || b[i] == 'D') dig.emplace_back(3);
        }else{
            if(mp[d] != -1) dig.emplace_back(mp[d]);
        }
    }

    int m = sz(dig);
    sort(all(dig));
    if(m == 0){ cout << "\n"; return 0; }
    if(dig[0]){
        rep(i, 0, m) cout << dig[i];
        cout << "\n";
        return 0;
    }

    if(m == 1){ cout << dig[0] << "\n"; return 0; }

    int pos = -1;
    rep(i, 0, m) if(dig[i]){ pos = i; break; }
    if(pos == -1){ cout << 0 << "\n"; return 0; }

    swap(dig[0], dig[pos]);
    rep(i, 0, m) cout << dig[i]; cout << "\n";
}