/*
  The Tribonacci sequence Tn is defined as follows: 
  T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
  Given n, return the value of Tn.

  Example 1:
  Input: n = 4
  Output: 4

  Explanation:
  T_3 = 0 + 1 + 1 = 2
  T_4 = 1 + 1 + 2 = 4
*/

class Solution {
public:
  int tribonacci(int n) {
    if( n ==0 ) return 0;
    if( n == 1 || n == 2 ) return 1;
    vector<int> arr(n+1, 0);
    arr[1] = 1;
    arr[2] = 1;
    for( int i=3; i<=n; i++ ) {
      arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
  }
};
