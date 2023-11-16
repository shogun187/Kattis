#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>


#define loop(i, to) for (int i = 0; i < to; ++i)
#define cont(i, to) for (int i = 1; i<=to; ++i)
#define circ(i, fm, to) for (int i = fm; i <=to; ++i)
#define foreach(i, dat) for (__typeof(dat.begin()) i = dat.begin(); i != dat.end();++i)

typedef long long num;

using namespace std;

const int nsz = 1000000;
int n, dm, a[nsz], dp[nsz][2], mx[nsz], pre[nsz], suf[nsz], ans;
vector<int> p[nsz];
map<int, int> to;

void inline init() {
    static int b[nsz + 5];
    int sz = 0;
    cont (i, n) b[i] = a[i];
    cont (i, n) if (b[i] != b[i + 1]) a[++sz] = b[i];
    n = sz;
    cont (i ,n) to[a[i]] = 0;
    foreach(it, to) it->second = ++dm;
    cont (i, n) a[i] = to[a[i]], p[a[i]].push_back(i);
}

void inline upd(int &a, int b) {
    if (a < b) a = b;
}

int main() {
    scanf("%d", &n);
    cont (i, n) scanf("%d", &a[i]);
    init();
    circ (p, 2, dm) {
        int sz1 = int(::p[p].size()), sz0 = int(::p[p - 1].size());
        loop (i, sz1) {
            int u = ::p[p][i];
            dp[u][0] = mx[p - 1];
            if (a[u - 1] == p - 1) {
                if (sz0 > 1) upd(dp[u][1], dp[u - 1][0] + 1);
                else upd(dp[u][1], mx[p - 1] + 1);
            }
        }
        loop (i, sz1) {
            int u = ::p[p][i], cur = max(dp[u][0], dp[u][1]);
            pre[i] = max(i != 0 ? pre[i - 1]: 0, cur);
        }
        for (int i =sz1 - 1; i >= 0; i--) {
            int u = ::p[p][i], cur = max(dp[u][0], dp[u][1]);
            suf[i] = max(i != sz1 - 1? suf[i + 1] : 0, cur);
        }
        loop(i, sz1) {
            int u = ::p[p][i], cur = max(dp[u][0], dp[u][1]);
            upd(mx[p], cur);
            upd(dp[u][0], i != 0 ? pre[i - 1] : 0);
            upd(dp[u][0], i != sz1 - 1? suf[i + 1] : 0);
        }
    }
    ans = n - 1 - mx[dm];
    printf("%d\n", ans);
}