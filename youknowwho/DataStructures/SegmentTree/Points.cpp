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

struct Seg{
    int n;
    vi t;
    Seg(int nn) : n(nn), t(4 * nn + 10, -1) {}
    void setPoint(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        setPoint(2 * v + 1, l, mid, pos, val);
        setPoint(2 * v + 2, mid + 1, r, pos, val);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void setPoint(int pos, int val){ setPoint(0, 0, n - 1, pos, val); }

    int descend(int v, int l, int r, int lq, int val){
        if(lq > r) return -1;
        if(lq <= l && t[v] < val) return -1;
        if(l == r) return l;
        int mid = l + r >> 1;
        int ans = -1;
        if(t[2 * v + 1] >= val) ans = descend(2 * v + 1, l, mid, lq, val);
        if(ans == -1 && t[2 * v + 2] >= val) ans = descend(2 * v + 2, mid + 1, r, lq, val);
        return ans;
    }
    int descend(int lq, int val){ return descend(0, 0, n - 1, lq, val); }

    int query(int v, int l, int r, int pos){
        if(pos < l || pos > r) return -1;
        if(l == r) return t[v];
        int mid = l + r >> 1;
        return max(
            query(2 * v + 1, l, mid, pos),
            query(2 * v + 2, mid + 1, r, pos)
        );
    }
    int query(int pos){ return query(0, 0, n - 1, pos); }

    void print(){
        rep(i, 0, n) cerr << query(i) << " ";
        cerr << "\n";
        cerr << "\n";
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vvi info(n);
    rep(i, 0, n){
        string op; int x, y; cin >> op >> x >> y;
        int ga = 0;
        if(op == "add") ga = 0;
        if(op == "remove") ga = 1;
        if(op == "find") ga = 2;
        info[i] = {ga, x, y};
    }
    
    vi d;
    rep(i, 0, n) d.emplace_back(info[i][1]);
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    rep(i, 0, n) info[i][1] = lower_bound(all(d), info[i][1]) - d.begin();

    vector<multiset<int>> have(sz(d) + 1);
    Seg st(sz(d) + 1);
    rep(i, 0, n){
        int op = info[i][0];
        int x = info[i][1];
        int y = info[i][2];
        if(op == 0){
            have[x].insert(y);
            st.setPoint(x, *prev(have[x].end()));
        }
        if(op == 1){
            have[x].erase(have[x].find(y));
            if(have[x].empty()) st.setPoint(x, -1);
            else st.setPoint(x, *prev(have[x].end()));
        }
        
        if(op == 2){
            int bestx = st.descend(x + 1, y + 1);
            if(bestx == -1){
                cout << "-1\n";
                continue;
            }
            int besty = *have[bestx].lower_bound(y + 1);
            cout << d[bestx] << " " << besty << "\n";
        }
        // st.print();
    }
}