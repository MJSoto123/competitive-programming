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

const int N = 1e3 + 100;
bitset<N> composite;
int dp[N];

int get(int d, int n){
    int pot = 10;
    while(pot < n) pot *= 10;
    return pot * d + n;
}

void init(){
    for(ll i = 3; i * i < N; i += 2){
        if(!composite[i]){
            for(ll j = i * i; j < N; j += i) composite[j] = 1;
        }
    }

    dp[2] = 1;
    dp[3] = 1;
    dp[5] = 1;
    dp[7] = 1;
    composite[2] = 1;
    for(int i = 3; i < N; i += 2){
        if(dp[i]){
            for(int j = 1; j <= 9; j++){
                int x = get(j, i);
                if(x < N && !composite[x]) dp[x] = 1;
            }
        }
    }

    for(int i = 2; i < N; i++) dp[i] += dp[i - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        cout << dp[n] << "\n";
    }
}