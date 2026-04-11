#include <bits/stdc++.h>
using namespace std;

// Check si una configuración es válida
bool checkConfig(const string &s, const vector<int> &dir) {
    int n = s.size();
    vector<int> target(n, -1); // destino de salto de cada conejo
    vector<int> count(n, 0);   // cuantos quieren saltar a esa maceta

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int d = dir[i];
            int j = i + d;
            if (j < 0 || j >= n) continue; // se cae fuera -> no salta
            target[i] = j;
            count[j]++;
        }
    }

    // ahora revisamos si alguien salta de verdad
    for (int i = 0; i < n; i++) {
        if (target[i] == -1) continue;
        int j = target[i];
        // Si exactamente uno intenta saltar a j y j NO tiene conejo (es '1'), ese salto será efectivo -> inválido
        if (count[j] == 1 && s[j] == '1') return false;
        // En cualquier otro caso (count[j]==0, o count[j]>=2, o s[j]=='0') está bloqueado/salvado
    }
    return true;
}

// brute force para un string
bool bruteForce(string s) {
    int n = s.size();
    vector<int> idx;
    for (int i = 0; i < n; i++)
        if (s[i] == '0') idx.push_back(i);

    int k = idx.size();
    if (k == 0) return true; // no rabbits -> trivially OK
    if (k >= 25) {
        // guard rule: evitamos overflow en 1<<k cuando k grande; 
        // para stress testing corta, no deberías llegar aquí con k>24
        // pero puedes manejarlo distinto si lo deseas.
    }

    int total = 1 << k;
    for (int mask = 0; mask < total; mask++) {
        vector<int> dir(n, 0);
        for (int b = 0; b < k; b++) {
            // -1 = izquierda, +1 = derecha
            dir[idx[b]] = ((mask >> b) & 1) ? 1 : -1;
        }
        if (checkConfig(s, dir)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; string s;
    if (!(cin >> n >> s)) return 0;
    cout << (bruteForce(s) ? "YES\n" : "NO\n");
}
