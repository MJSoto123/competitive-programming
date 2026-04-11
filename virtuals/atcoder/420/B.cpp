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

    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vi b(n);
    for(int i = 0; i < m; i++){
        vi cnt(2);
        for(int j = 0; j < n; j++) cnt[s[j][i] - '0']++;
        if(cnt[0] < cnt[1]){
            for(int j = 0; j < n; j++) if(s[j][i] == '0') b[j]++;
        }else {
            for(int j = 0; j < n; j++) if(s[j][i] == '1') b[j]++;
        }
    }

    int mx = *max_element(all(b));
    for(int i = 0; i < n; i++) if(b[i] == mx) cout << i + 1 << " ";
    cout << "\n";
}