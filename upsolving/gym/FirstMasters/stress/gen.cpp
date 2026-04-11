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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n = 4;
    string s = "";
    rep(i, 0, n) s += char('a' + rng() % 26);
    cout << n << "\n" << s << "\n";
}