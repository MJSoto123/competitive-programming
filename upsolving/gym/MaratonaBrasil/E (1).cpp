#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y; cin >> x >> y;
    int res = (x - y) / 2;
    int res2 = x - res;
    cout << res << ' ' << res2 << '\n';
}