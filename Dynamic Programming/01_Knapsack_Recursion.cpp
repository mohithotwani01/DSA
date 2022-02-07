#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
	// base condition
	// 1. array size can be 0
	// 2. min weight can be 0
	// So in both the conditions our answer will be zero
	// since we are not able to take any element
	if (n == 0 or W == 0) return 0; 
	
	// recursive condition
	// 1. current wt is bigger than the capacity so we can't take it
	// 2. current wt is less than or equal to capacity so we can either take it or leave it
	if (wt[n-1] > W) {
		return knapsack(wt, val, W, n-1); // ask for the next element by reducing the size of the array
	} else {
		// add the val and subtract the wt from the capacity and calculate for rest
		int takeIt =  val[n-1] + knapsack(wt, val, W - wt[n-1], n-1);
		int leaveIt = knapsack(wt, val, W, n-1);
		// Return maximum from both of them
		// return max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
		return max(takeIt, leaveIt);
	}
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