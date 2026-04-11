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

    ll a, b; cin >> a >> b;
    int mx = 0;
    for(int i = 0; i <= a; i += 1000){
        if(i  + ((i) / 1000) * b <= a) mx = i;
    }

    cout << mx << "\n";
}