#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
	// base condition
	if (n == 0 or W == 0) return 0;
	
	// if already calculated
	if (dp[n][W] != -1) return dp[n][W];
	
	// if not calculated then calculate it
	if (wt[n-1] > W) dp[n][W] = knapsack(wt, val, W, n-1);
	else dp[n][W] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
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
	// initialize matrix
	dp.resize(n+1, vector<int> (W+1, -1));
	cout << knapsack(wt, val, W, n) << endl;
	return 0;
}