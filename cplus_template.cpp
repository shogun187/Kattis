#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nsz = 200;

int n, k;
int dp[nsz][nsz][2];

void inline init() {
    for (int i = 0; i < nsz; ++i) {
        for (int j = 0; j < nsz; ++j) {
            for (int l = 0; l < 2; ++l) {
                dp[i][j][l] = -1;
            }
        }
    }
}

int inline narrow_art_gallery(vector<vector<int> > &values, int row, int to_close, int closed_last) {
    if (row == n) {
        return 0;
    }

    if (dp[row][to_close][closed_last] != -1) {
        return dp[row][to_close][closed_last];
    }

    int result = narrow_art_gallery(values, row + 1, to_close, 0) + values[row][0];

    if (to_close > 0) {
        if (closed_last == 0) {
            result = max(result, narrow_art_gallery(values, row + 1, to_close - 1, 1) + values[row][1]);
        }
    }

    dp[row][to_close][closed_last] = result;
    return result;
}

int main() {
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }

        vector<vector<int> >  values(n, vector<int>(2));

        for (int i = 0; i < n; ++i) {
            cin >> values[i][0] >> values[i][1];
        }

        init();

        int result = narrow_art_gallery(values, 0, k, 0);
        cout << result << endl;
    }

    return 0;
}