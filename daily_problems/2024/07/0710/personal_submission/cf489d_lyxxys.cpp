#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3050;
/*
f[i][j] 表示点i到点j的路径恰好只经过 2条边 的路径条数
*/
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1), f(n+1, vector<int>(n+1));
    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    function<void(int,int,int)> dfs = [&](int x, int fa, int step){
        if (step == 2){
            f[fa][x] += 1;
            return;
        }
        for (auto &y: g[x]){
            if (x != y && fa != y)
                dfs(y, fa, step+1);
        }
    };

    for (int i = 1; i <= n; ++ i)
        dfs(i, i, 0);

    ll res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i == j) continue;
            res += f[i][j]*(f[i][j]-1)/2;
        }
    }
    cout << res << "\n";
}
