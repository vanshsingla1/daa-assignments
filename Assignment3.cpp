// Q1
#include <iostream>
#include <vector>
using namespace std;

string LCS(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}

int main() {
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "Longest Common Subsequence = " << LCS(s1, s2) << endl;
    return 0;
}

// Q2
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    cout << "Minimum number of multiplications performed = " << matrixChainMultiplication(arr) << endl;
    return 0;
}

// Q3
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weight, vector<int>& profit, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    int res = dp[N][W];
    int w = W;
    cout << "Items selected: ";
    for (int i = N; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            cout << "Item " << i << " ";
            res -= profit[i - 1];
            w -= weight[i - 1];
        }
    }
    cout << "\nMaximum profit: " << dp[N][W] << endl;
    return dp[N][W];
}

int main() {
    int N = 4, W = 7;
    vector<int> profit = {5, 3, 8, 6};
    vector<int> weight = {2, 3, 4, 5};
    knapsack(W, weight, profit, N);
    return 0;
}

// Q4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSquareSubmatrix(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return 0;
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSize = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }
    return maxSize;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    cout << "Maximum size of square sub-matrix with all 1s: " << maxSquareSubmatrix(mat) << endl;
    return 0;
}

