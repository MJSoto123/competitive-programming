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

void fix(string &s, int l, int r){
    if(l + 1 == r) return;
    int mid = l + r >> 1;
    if(mid - l != r - mid) return;
    fix(s, l, mid); fix(s, mid, r);

    string sl = s.substr(l, mid - l), sr = s.substr(mid, r - mid);
    string tmp = "";
    if(sl < sr) tmp = sl + sr;
    else tmp = sr + sl;

    rep(i, 0, sz(tmp)) s[l + i] = tmp[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    fix(a, 0, sz(a));
    fix(b, 0, sz(b));

    cout << (a == b ? "YES" : "NO") << "\n";
}