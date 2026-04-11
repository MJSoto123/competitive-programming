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

const int N = 1e6 + 10;
int a[N], L[N], R[N];

ll go(int l, int r, int side = 0){
    if(l + 1 == r) return 0;
    int mid = l + r >> 1;
    
    ll ret = go(l, mid, 0) + go(mid, r, 1);
    {   // ret
        int i = l, j = mid;
        while(i < mid && j < r){
        if(L[i] > R[j]){
                ret += (mid - i);
                j++;
        }else i++;
        }
    }

    {   // sort L
        vi tmp;
        int i = l, j = mid;
        while(i < mid && j < r){
            if(L[i] < L[j]) tmp.emplace_back(L[i++]);
            else tmp.emplace_back(L[j++]);
        } 

        while(i < mid) tmp.emplace_back(L[i++]);
        while(j < r) tmp.emplace_back(L[j++]);
        rep(k, 0, sz(tmp)) L[l + k] = tmp[k];
    }

    {
        // sort R
        vi tmp;
        int i = l, j = mid;
        while(i < mid && j < r){
            if(R[i] < R[j]) tmp.emplace_back(R[i++]);
            else tmp.emplace_back(R[j++]);
        } 

        while(i < mid) tmp.emplace_back(R[i++]);
        while(j < r) tmp.emplace_back(R[j++]);
        rep(k, 0, sz(tmp)) R[l + k] = tmp[k];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    vi d(n);
    rep(i, 0, n) d[i] = a[i];
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    rep(i, 0, n) a[i] = lower_bound(all(d), a[i]) - d.begin();

    int uni = sz(d);
    vi frec(uni);
    rep(i, 0, n){ frec[a[i]]++; L[i] = frec[a[i]]; }

    frec.assign(uni, 0);
    for(int i = n - 1; i >= 0; i--){ frec[a[i]]++; R[i] = frec[a[i]]; }
    cout << go(0, n) << "\n";
}