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
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    int g = __gcd(a, b);
    int l = a * b / g;

    if(l == b && l == a) cout << "0\n";
    else if(l == b) cout << "1\n";
    else cout << "2\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}