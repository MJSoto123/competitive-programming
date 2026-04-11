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

// bool check(string s){
//     int n = sz(s);

//     int sum = 0;
//     rep(i, 0, n){
//         string want = to_string(sum);
//         if(s.substr(i, sz(want)) == want){

//         }
//         sum += (s[i] - '0');
//     }
// }

int get(int val){
    int ret = 0;
    while(val){
        ret += val % 10;
        val /= 10;
    }
    return ret;
}

void solve(){
    string s; cin >> s;
    int n = sz(s);
    // if(check(s)){ cout << s << "\n"; return; }   
    
    int tot = 0;
    vi cnt(10, 0);
    rep(i, 0, n){
        int d = s[i] - '0';
        tot += d;
        cnt[d]++;
    }

    rep(i, 1, tot + 1){
        int cur = i;
        vi sum;
        sum.emplace_back(cur);
        while(cur > 9){
            cur = get(cur);
            sum.emplace_back(cur);
        }

        vi need(10, 0);
        for(auto x : sum){
            while(x > 0){
                need[x % 10]++;
                x /= 10;
            }
        }

        int can = 1;
        int sm = 0;
        rep(j, 0, 10){
            if(need[j] > cnt[j]) can = 0;
            sm += j * need[j];
        }

        if(can && (tot - sm == sum[0] || tot - sm == 0)){
            rep(j, 0, 10){
                cnt[j] -= need[j];
            }
            for(int j = 9; j >= 0; j--){
                rep(k, 0, cnt[j]) cout << j;
            }
            for(auto x : sum) cout << x; cout << "\n";
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}