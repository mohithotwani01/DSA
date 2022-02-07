#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
	vector<vector<int>> dp(n+1, vector<int>(W+1));
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			// base condition of recursion 
			// initialization of table - filling 1st row and
			//							 1st column with 0
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (wt[i-1] > j) { // current weight doesn't fit in bag
				dp[i][j] = dp[i-1][j];
			} else { // choice for the current weight
				int val1 = dp[i-1][j]; // not choosing the current weight
				int val2 = val[i-1] + dp[i-1][j-wt[i-1]]; // choosing the current weight 
				dp[i][j] = max(val1, val2);
			}
		}
	}
	return dp[n][W];
}


int main() {
	// n: number of items
	// W: capacity of knapsack
	// wt: weight of each item
	// val: value of each item
	int n,W;
	cin >> n >> W;
	vector<int> wt(n), val(n);
	for (int i = 0; i < n; i++) cin >> wt[i];
	for (int i = 0; i < n; i++) cin >> val[i];
	cout << knapsack(wt, val, W, n) << endl;
	return 0;
}