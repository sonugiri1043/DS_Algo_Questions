/*
  Best Time to Buy and Sell Stock IV [LeetCode 188]
  Say you have an array for which the i-th element is the price of a given stock on day i.
  Design an algorithm to find the maximum profit. You may complete at most k transactions.

  Note:
  You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
  Example 1:
  Input: [2,4,1], k = 2
  Output: 2
  Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

  Example 2:
  Input: [3,2,6,5,0,3], k = 2
  Output: 7
  Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
  Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

/*  
    dp[i][j] = maximum profit from at most i transactions using prices[0..j]

    A transaction is defined as one buy + sell.

    Now on day j, we have two options
    1. Do nothing (or buy) which doesn't change the acquired profit : dp[i][j] = dp[i][j-1]
    2. Sell the stock: In order to sell the stock, you must've bought it on a day t=[0..j-1].
       Maximum profit that can be attained is t:0->j-1 max( prices[j] - prices[t] + dp[i-1][t-1] )
       where prices[j]-prices[t] is the profit from buying on day t and selling on day j.
       dp[i-1][t-1] is the maximum profit that can be made with at most i-1 transactions with prices prices[0..t-1].
	
    Time complexity of this approach is O(n^2*k).
    In order to reduce it to O(nk), we must find t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1])
    this expression in constant time. If you see carefully,
	
    t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) is same as
    prices[j] + t:0->j-1 max(dp[i-1][t-1]-prices[t])
	
    Second part of the above expression maxTemp = t:0->j-1 max(dp[i-1][t-1]-prices[t]) can be included in the dp loop by keeping track of the maximum value till j-1.
    
    Base case:
    dp[0][j] = 0; dp[i][0] = 0

    DP loop:
    for i : 1 -> k
       maxTemp = -prices[0];
       for j : 1 -> n-1
          dp[i][j] = max(dp[i][j-1], prices[j]+maxTemp);
	  maxTemp = max(maxTemp, dp[i-1][j-1]-prices[j]);
    return dp[k][n-1];
*/

int maxProfit(int k, vector<int>& prices) {
  int n = prices.size();
  if( n <= 1) return 0;
 
  if (k >= n/2) {
    // fast case because there are [0, n/2] continuous increases
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
      int diff = prices[i] - prices[i-1];
      if (diff > 0) {
	maxProfit += diff;
      }
    }
    return maxProfit;
  }
 
  vector<vector<int>> dp( k+1, vector<int>(n) );
  for( int i = 1; i <= k; i++ ) {
    int localMax = dp[i-1][0] - prices[0];
    for( int j = 1; j < n; j++ ) {
      dp[i][j] = max( dp[i][j-1],  prices[j] + localMax );
      localMax = max( localMax, dp[i-1][j] - prices[j] );
    }
  }
  return dp[k][n-1];
}
