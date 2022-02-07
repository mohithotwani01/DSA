#include <bits/stdc++.h>
using namespace std;

bool isEqualPartitionPossible(vector<int> arr, int sum) {
	int n = arr.size();
	vector<vector<bool>> dp(n+1, vector<int>(sum+1));
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) dp[i][j] = false; // when array(i) is empty than there is no meaning of sum of elements so return false
			if (j == 0) dp[i][j] = true; // when sum(j) is zero and there is always a chance of empty subset so return it as true	
		}
	}
	
	// i: size of the array
	// j: target sum
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main() {
	int n, sum = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum+=arr[i];
	}
	if (sum%2 == 1) {
		cout << "false" << endl;
	} else {
		cout << boolalpha << isEqualPartitionPossible(arr, sum/2) << endl;
	}
	return 0;
}