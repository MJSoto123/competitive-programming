#include<bits/stdc++.h>
using namespace std;


int lso(int n) {return (n & (-n));}

struct FenwickTree{
    vector<long long> ft; 
    FenwickTree(int m) {ft.assign(m + 1, 0);};
    long long rsq(int j) {
        long long sum = 0;
        for(; j; j -= lso(j)) sum += ft[j];
        return sum;
    }
    void upd(int i, long long v) {
        for(; i < ft.size(); i += lso(i)) ft[i] += v;
    }
};

long long get(vector<int> &a){
    int n = a.size();
    FenwickTree ft(n);
    long long inv = 0;

    for(int i = n - 1; i >= 0; i--){
        inv += ft.rsq(a[i] - 1);
        ft.upd(a[i], 1);
    }
    
    return inv;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ori = get(a);

    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) even.emplace_back(a[i]);
        else odd.emplace_back(a[i]);
    }

    vector<int> now;
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for(int i = 0; i < odd.size(); i++) {
        now.emplace_back(even[i]);
        now.emplace_back(odd[i]);
    }

    if(n % 2) now.emplace_back(even.back());

    long long ans1 = get(now);
    if(ans1 % 2 == ori % 2) {
        for(auto x : now) cout << x << " ";
        cout << "\n";
        return;
    }

    swap(now[n - 1], now[n - 3]);
    long long ans2 = get(now); 
    for(auto x : now) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}