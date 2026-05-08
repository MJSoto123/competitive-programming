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

    ll n, m; 
    int t = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        cout << "Case " << t++ << ": ";
        ll a1 = (n - 1) * n / 2;
        ll a2 = (m - 1) * m / 2;
        cout << a1 * a2 << "\n";
    }
}