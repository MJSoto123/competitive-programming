#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a; cin >> a;
    int n = a.size();
    if(n % 2) { cout << "No\n"; return 0;}

    map<char, int> mp;
    for(int i = 0; i < n; i = i + 2){
        if(a[i] != a[i + 1] || mp.count(a[i])) {cout << "No\n"; return 0;}
        mp[a[i]]++;
    }
    cout << "Yes\n";
}