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

const int N = 2e5 + 10;
ll a[N], pre[N], suf[N], sm[N];
ll lim; 

ll get(int l, int r){
    return sm[r] - sm[l];
}

ll divide(int l, int r){
    if(l + 1 == r) return a[l] < lim;
    int mid = l + r >> 1;
    
    ll ret = divide(l, mid) + divide(mid, r);
    {
        int i = l, j = r - 1;
        while(i < mid && j >= mid){
            if(suf[i] + pre[j] < lim){
                ret += (j - mid + 1);
                i++;
            }else j--;
        }
    }

    {
        int i = l, j = mid;
        ll extra = get(mid, r);
        vl tmp;
        while(i < mid && j < r){
            if(suf[i] + extra < suf[j]) tmp.emplace_back(suf[i++] + extra);
            else tmp.emplace_back(suf[j++]);
        }
        while(i < mid) tmp.emplace_back(suf[i++] + extra);
        while(j < r) tmp.emplace_back(suf[j++]);
        rep(i, 0, sz(tmp)) suf[l + i] = tmp[i];
    }

    {
        int i = l, j = mid;
        ll extra = get(l, mid);
        vl tmp;
        while(i < mid && j < r){
            if(pre[i] < pre[j] + extra) tmp.emplace_back(pre[i++]);
            else tmp.emplace_back(pre[j++] + extra);
        }
        while(i < mid) tmp.emplace_back(pre[i++]);
        while(j < r) tmp.emplace_back(pre[j++] + extra);
        rep(i, 0, sz(tmp)) pre[l + i] = tmp[i];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n >> lim;
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n + 1) sm[i] = sm[i - 1] + a[i - 1];
    rep(i, 0, n) pre[i] = suf[i] = a[i];

    cout << divide(0, n) << "\n";
}