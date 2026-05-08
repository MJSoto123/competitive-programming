#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int MAXQ = 1'000'000 + 7; 
ll cnt[MAXQ]; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q; cin >> n >> m >> q; 
    vector<string> g(n); 
    rep(i,0,n) cin >> g[i]; 

    rep(i,0,n) rep(j,0,m) { 
        rep(di,-1,2) rep(dj,-1,2) { 
            if(di == 0 && dj == 0) continue; 
            int ci = i, cj = j; 
            if(g[ci][cj] == '*' || g[ci][cj] == '+') continue; 
            ll total = 0, last_sum = 0, last_num = 0; 
            bool prev_op = false, last_add = true, last_mul = false; 
            string cur; 
            while(ci >= 0 && ci < n && cj >= 0 && cj < m) { 
                cur.push_back(g[ci][cj]); 
                if(g[ci][cj] == '+') { 
                    if(prev_op) break; 
                    prev_op = true; 
                    last_add = true; 
                    last_mul = false; 
                    last_sum = 0; 
                    last_num = 0; 
                }else if(g[ci][cj] == '*') { 
                    if(prev_op) break ;
                    prev_op = true; 
                    last_add = false; 
                    last_mul = true; 
                    last_num = 0; 
                }else{ 
                    ll here = (ll)(g[ci][cj] - '0'); 
                    if(last_add) { 
                        total -= last_num; 
                        last_num = last_num * 10 + here; 
                        total += last_num; 
                        last_sum = last_num; 
                    }else{ 
                        assert(last_mul); 
                        total -= last_sum; 
                        if(last_num == 0) { 
                            last_num = here; 
                            last_sum *= last_num; 
                        }else{ 
                            last_sum /= last_num; 
                            last_num = last_num * 10 + here; 
                            last_sum *= last_num; 
                        }
                        total += last_sum; 
                    }
                    prev_op = false;  
                    if(total >= MAXQ) break; 
                    cnt[total]++; 
                }
                ci += di; 
                cj += dj;
            }
        }
    }

    rep(i,0,n) rep(j,0,m) { 
        if(g[i][j] == '+' || g[i][j] == '*') continue; 
        cnt[g[i][j] - '0'] -= 7; 
    }

    while(q--) { 
        int x; cin >> x; 
        cout << cnt[x] << "\n"; 
    }
}