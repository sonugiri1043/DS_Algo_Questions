/*
  We have a collection of stones, each stone has a positive integer weight.

  Each turn, we choose the two heaviest stones and smash them together.
  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

  If x == y, both stones are totally destroyed;
  If x != y, the stone of weight x is totally destroyed, and the stone of weight y
  has new weight y-x.
  At the end, there is at most 1 stone left.  Return the weight of this stone
  (or 0 if there are no stones left.)
 */

int lastStoneWeight( vector<int>& stones ) {
  priority_queue<int> queue;
  for( auto stone : stones ) queue.push( stone );
        
  int x, y;
  while( queue.size() >= 2 ) {
    x = queue.top(); queue.pop();
    y = queue.top(); queue.pop();
    if( x != y ) {
      queue.push( abs( x - y ) );
    }
  }
  if( queue.empty() ) return 0;
  else return queue.top();
}
