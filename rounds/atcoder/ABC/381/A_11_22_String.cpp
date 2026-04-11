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

    int n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 0) { cout << "No\n"; return 0;}
    for(int i = 0; i < n / 2; i++) if(s[i] != '1') { cout << "No\n"; return 0;}
    if(s[n / 2] != '/') { cout << "No\n"; return 0;}
    for(int i = n / 2 + 1; i < n; i++) if(s[i] != '2') { cout << "No\n"; return 0;}
    cout << "Yes\n";
}