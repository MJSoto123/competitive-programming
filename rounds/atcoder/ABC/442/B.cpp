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

    int n; cin >> n;
    int vol = 0;
    int on = 0;
    rep(i, 0, n){
        int op; cin >> op;
        if(op == 1) vol++;
        if(op == 2) vol = max(0, vol - 1);
        if(op == 3) on ^= 1;
        if(on && vol >= 3) cout << "Yes\n";
        else cout << "No\n";
    }
}