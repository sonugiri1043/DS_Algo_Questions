/*
  Write an algorithm to determine if a number is "happy".

  A happy number is a number defined by the following process: Starting with any positive
  integer, replace the number by the sum of the squares of its digits, and repeat the process
  until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does
  not include 1. Those numbers for which this process ends in 1 are happy numbers.

  Example: 
  Input: 19
  Output: true
  Explanation: 
  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1
 */

class Solution {
public:
  int getSumOfDigitSquare( int n ) {
    int sum = 0;
    int rem;
    while( n ) {
      rem =  n % 10;
      sum += rem*rem;
      n = n/10;
    }
    return sum;
  }
    
  bool isHappy(int n) {
    // same as detecting cycle in a linked list 
    // we use slow and fast pointer concept
    int slow = getSumOfDigitSquare(n);
    int fast =  getSumOfDigitSquare( getSumOfDigitSquare(n) );
    while( slow != fast && slow != 1 ) {
      slow = getSumOfDigitSquare( slow );
      fast = getSumOfDigitSquare( getSumOfDigitSquare( fast ) );
    }
    return slow == 1;
  }
};
