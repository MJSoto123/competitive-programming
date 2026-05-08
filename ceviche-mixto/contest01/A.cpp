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

    vi a(3);
    rep(i, 0, 3) cin >> a[i];

    sort(all(a));

    if(a[2] - a[0] >= 10) cout << "check again\n";
    else cout << "final " << a[1] << "\n";
}