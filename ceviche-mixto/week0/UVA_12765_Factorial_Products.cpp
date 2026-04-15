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


vvi fact(10, vi(10));
void init(){
    rep(i, 2, 10){
        int tmp = i;
        for(int d = 2; d <= 7; d++){
            int exp = 0;
            while(tmp % d == 0){
                exp++;
                tmp /= d;
            }
            fact[i][d] += exp;
        }
    }

    rep(i, 1, 10) rep(d, 0, 10) fact[i][d] += fact[i - 1][d];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        vi a(10), b(10);
        rep(i, 0, n){ int d; cin >> d; a[d]++; }
        rep(i, 0, m){ int d; cin >> d; b[d]++; }

        vi a2(10), b2(10);
        rep(i, 2, 10){
            rep(d, 0, 10) a2[d] += fact[i][d] * a[i];
            rep(d, 0, 10) b2[d] += fact[i][d] * b[i];
        }

        if(a2 == b2) cout << "YES\n";
        else cout << "NO\n";
    }   

}