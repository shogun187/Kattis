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

const int nsz = 200;

void inline init() {

}

void inline upd(int &a, int b) {
    a = b;
}

int findMax(const int *arr) {

    int len = 3;


    int max = arr[0];
    for (int i = 1; i < len; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {

    int n, k;

    int ans = 0;
    cin >> n >> k;

    int rms[n][2];


    loop(i, n) {
        loop(j, 2) {
            cin >> rms[i][j];
        }
    }

//    loop(i, n) {
//        loop(j, 2) {
//            cout << "rms " << i << j << " is " << rms[i][j] << "\n";
//        }
//    }


    int dp[n][k + 1][3];
    loop(i, n) {
        loop(j, k + 1) {
            loop(l, 3) {
                dp[i][j][l] = -1;
            }
        }
    }

    dp[0][0][0] = rms[0][0] + rms[0][1];


    if (k > 0) {
        dp[0][1][1] = rms[0][1];
        dp[0][1][2] = rms[0][0];
    }

//    loop(i, n) {
//        loop(j, k + 1) {
//            loop(l, 3) {
//                cout << "dp  " << i << j << l << " is " << dp[i][j][l] << endl;
//            }
//        }
//    }


    cont(i, n - 1) {
        loop(j, min(i + 1, k) + 1) {

            int a = dp[i- 1][j][0];
            int b = dp[i- 1][j][1];
            int c = dp[i- 1][j][2];
            int x = max(max(a,b),c);



//            cout << a << b << c << endl;
//
//            cout << "when i j is " << i << j << ", << " "x is " << x << endl;
            if (x >= 0) {
                dp[i][j][0] = rms[i][0] + rms[i][1] + x;
            }

            int cur1 = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0]);
            if (j > 0 && cur1 >= 0) {
                dp[i][j][1] = rms[i][1] + cur1;
            }

            int cur2 = max(dp[i - 1][j - 1][2], dp[i - 1][j - 1][0]);
            if (j > 0 && cur2 > 0) {
                dp[i][j][2] = rms[i][0] + cur2;
            }
        }
    }
    ans = *max_element(dp[n - 1][k], dp[n - 1][k] + 3);
    cout << ans;
}