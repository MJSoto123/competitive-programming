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

const int N = 2'000'000 + 10;
double e[N];
double pre[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n, a, b; cin >> n >> a >> b;
    if(a == b){ cout << (n + a - 1) / a << "\n"; return 0; }

    if(a == 0){
        rep(i, 1, n + 1){
            int l = max(0, i - b);
            int r = max(0, i - 1);
            double sm = pre[r] - (l >= 1 ? pre[l - 1] : 0);
            double factor = double(b - a) / double(b - a + 1);
            e[i] = 1.0 + sm / double(b - a + 1);
            e[i] /= factor;
            pre[i] = pre[i - 1] + e[i];
        }
    }else{
        rep(i, 1, n + 1){
            int l = max(0, i - b);
            int r = max(0, i - a);
            double sm = pre[r] - (l >= 1 ? pre[l - 1] : 0);

            e[i] = 1.0 + sm / double(b - a + 1);
            pre[i] = pre[i - 1] + e[i];
        }
    }

    cout << e[n] << "\n";
}