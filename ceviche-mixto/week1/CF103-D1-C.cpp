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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, b, p; cin >> n >> b >> p;
    ll w = n - b;
    ll mix = min(b, w); 
    ll fs = w - mix;
    ll ls = b - mix;
    if(fs % 2 == 1 && mix > 0){
        fs++;
        mix--;
        ls++;
    }
    rep(i, 0, p){
        ll pos; cin >> pos;
        if(pos > fs + 2 * mix) cout << 'X';
        else if(pos > fs){
            pos -= fs;
            cout << (pos % 2 ? '.' : 'X');
        }else cout << '.';
    }
    cout << "\n";
}