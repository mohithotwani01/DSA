#include <bits/stdc++.h>
using namespace std;

int numberOfSubsets(vector<int> arr, int sum) {
	int n = arr.size();
	vector<vector<int>> dp(n+1, vector<int> (sum+1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 or j== 0) {
				if (i == 0) dp[i][j] = 0;
				if (j == 0) dp[i][j] = 1;
				continue;
			}
			if (arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int n, sum;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> sum;
	cout << numberOfSubsets(arr, sum) << endl;
	return 0;
}