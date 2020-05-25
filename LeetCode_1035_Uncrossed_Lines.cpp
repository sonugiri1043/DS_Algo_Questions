/*
  Uncrossed Lines [LeetCode 1035]
  We write the integers of A and B (in the order they are given) on two separate horizontal lines.
  Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:
  A[i] == B[j];
  The line we draw does not intersect any other connecting (non-horizontal) line.
  Note that connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.
  Return the maximum number of connecting lines we can draw in this way.

  Example 1:
  Input: A = [1,4,2], B = [1,2,4]
  Output: 2
  Explanation: We can draw 2 uncrossed lines as in the diagram.
  We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
 
  Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
  Output: 3
 
  Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
  Output: 2

  The recurrence relation for this DP is exactly the same as the Longest Common subsequence DP Problem.
  There we use to look for a match on 'char' and we check if we have a matching integer. You can also
  look at this problem as the longest Common sub-sequence in digits.

  Let dp[i][j] be the max no of connecting line b/w A[0...i-1] and B[0...j-1].
  Base case:
  dp[0][0] = 0;
  Recurrence Relation
  dp[i][j] = max( dp[i][j] , d[i-1][j-1] +1 )  if A[i-1] == B[j-1]
             max( dp[i-1][j], dp[i][j-1] ) if A[i-1] != B[j-1]

  Note: 1st row and 1st column in DP will be 0 since the other array is empty and we can't have any connecting line.
*/

int maxUncrossedLines( vector<int>& A, vector<int>& B ) {
  int m = A.size(), n = B.size();
  // dp[i][j] represent max no of connecting lines between A[0...i-1] and B[0...j-1]
  vector<vector<int>> dp( m+1, vector<int>( n+1, 0 ));
  
  for( int i=1; i <= m; i++ )
    for( int j=1; j <= n; j++ )
      if( A[i-1] == B[j-1] ) 
	dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 );
      else
	dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
  return dp[m][n];
}
