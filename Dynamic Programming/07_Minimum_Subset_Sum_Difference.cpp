#include <bits/stdc++.h>
using namespace std;

vector<int> getPossibleSum(vector<int> arr, int sum) {
	int n = arr.size();
	vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 or j == 0) {
				if (i == 0) dp[i][j] = false;
				if (j == 0) dp[i][j] = true;
				continue;
			}
			if (arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
			}
		}
	}
	vector<int> res;
	for (int i = 0; i <= sum/2; i++) 
		if (dp[n][i] == true) res.push_back(i);	
	return res;
}

int minimumDifference(vector<int> arr) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	vector<int> possibleSum = getPossibleSum(arr, sum);
	int res = INT_MAX;
	for (int i:possibleSum) res = min(res, sum - 2*i);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << minimumDifference(arr) << endl;
	return 0;
}