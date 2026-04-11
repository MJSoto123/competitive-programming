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

struct SparceTable{
    int n, LG;
    vvi spt;

    void build(const vi &a) {
        n = sz(a);
        LG = log2(n) + 1;
        spt.assign(LG, vi(n));
        for (int i = 0; i < n; i++) spt[0][i] = a[i];
        for (int j = 0; j < LG-1; j++)
            for (int i = 0; i+(1<<(j+1)) <= n; i++)
                spt[j+1][i] = min(spt[j][i], spt[j][i+(1<<j)]);
    }

    int query(int i, int j) {
        int k = 31-__builtin_clz(j-i+1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}