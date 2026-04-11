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

    int a, b; cin >> a >> b;
    
    int wins = (6 - max(a, b) + 1);
    int tot = 6;
    int g = gcd(wins, tot);
    wins /= g; 
    tot /= g;
    if(wins == 0) tot = 1;
    cout << wins << "/" << tot << "\n";
}