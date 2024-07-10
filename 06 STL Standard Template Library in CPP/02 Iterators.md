- Iterators is pointer like object. used to traverse over container.

- Creating Iterator
  vector<int> :: iterator it = arr.begin();
  while( it != arr.end()){
  cout<<\*it<<endl;
  it++;
  }

- Iterator Operators
  -All numerical operator works on iterator.
  - itr-> n ==> (\*itr).m

-Type of Iterators 1. Input 2. Output 3. Forward 4. Bi-directional 5. Random Access Iterator

- Why we use iterators?
  1. Working with algorithms
  2. Saving Memory
  3. Uniform Approach
  4. Simpler Code
