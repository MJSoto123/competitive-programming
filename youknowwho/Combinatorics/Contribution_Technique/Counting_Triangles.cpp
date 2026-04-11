#include<bits/stdc++.h>
using namespace std;

vector<long long> a(1e6 + 5), b(1e6 + 5), c(1e6 + 5);

int main(){
    for(int i = 1; i <= 1e6 + 1; i++){
        long long x = 1LL * i * (i + 1) / 2;
        a[i] = a[i - 1] + x;
        if(i % 2) b[i] = (i > 2 ? b[i - 2] : 0) + x;
        else c[i] = c[i - 2] + x;
    }

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        if(n % 2) cout << a[n] + c[n - 1] << "\n";
        else cout << a[n] + b[n - 1] << "\n";
    }
}