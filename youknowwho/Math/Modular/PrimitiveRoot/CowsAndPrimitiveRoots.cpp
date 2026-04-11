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
int mod;
int add(int a, int b){ return (a + b >= mod ? a + b - mod : a + b); }
int mul(ll a, ll b){ return (a * b) % mod; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> mod;
    int ans = 0;
    for(int i = 1; i <= mod; i++){
        int pot = i;
        bool ok = true;
        for(int j = 1; j <= mod - 2; j++){
            if(pot == 1) ok = false;
            pot = mul(pot, i);
        }
        if(!ok || pot != 1) continue;
        ans++;
    }
    cout << ans << "\n";
}