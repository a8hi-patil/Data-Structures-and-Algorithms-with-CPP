- C++ STL : Algorithms

- Algorithms : A set of steps
  #include<algorithm>

- Iterator and Iterating Algorithms :

  1. for-each

     - for_each( start , end , callback)
     - foe_each( arr.begin(), arr.end(), printDouble)

  2. find

     - find( start , end , target) -> returns iterator
     - auto find(arr.begin(), arr.end() ,40)
     - cour<<\*it<<endl;

  3. find-if

     - find-if( start , end , callBack);
     - auto find-if( arr.begin() , arr.end() , checkEven)
     - cout<<\*it<<endl ;

  4. count

     - count(arr.begin(),arr.end(), target)

  5. count-if

     - count-if( arr.begin(), arr.end(), checkEven)

  6. sort

     - sort( arr.begin(),arr.end())

  7. reverse

     - reverse( arr.begin(),arr.end())

  8. rotate

     - rotate( arr.begin(),arr.begin()+3,arr.end())

  9. unique : removes duplicate in sorted array

     - auto it = unique( arr.begin(), arr.end())
     - arr.erase( it , arr.end())

  10. partition
      auto it = partition(arr.begin(),arr.end(),callBack)

- Numerical Algorithms

  - #include<numeric>

  1. accumulate

     - int sum = accumulate( arr.begin(),arr.end(),initialValue)

  2. inner_product

     - inner_product( arr.begin(),arr.end(), arr2.begin(), initialValue)

  3. partial_sum

     - partial_sum( arr.begin(), arr.end(), storage)

  4. iota
     - iota(arr.begin(),arr.end(),initialValue)

- Searching and Finding Algorithms

  1. binary_search
     bool it = binary_search( arr.begin(),arr.end(),target)

  2. lower_bound : greater or equal to value'
     auto it = lower_bound( arr.begin(), arr.end(), target)
     cout<<\*it<<endl;

  3. upper_bound : always greater value
     auto it = lupper_bound( arr.begin(), arr.end(), target)
     cout<<\*it<<endl;

  4. equal_range : finds the range of elements equal to value in storage range.

- Min and Max Algorithms

  1. min

     - cout<<min(10,15)<<endl;

  2. max

     - cout<<max(10,15)<<endl;

  3. min-element

     - auto it = min_element( arr.begin(), arr.end());
     - cout<<\*it<<endl;

  4. max-element
     - auto it = max_element( arr.begin(), arr.end());
     - cout<<\*it<<endl;

- Heap Algorithm

  1. make_heap - convert vector to heap

     - make_heap( arr.begin(), arr.end())

  2. push_heap - after insertion on heap perform this operation.

     - arr.push_back(99);
     - push_heap( arr.begin(), arr.end())

  3. pop_heap

  - pop_heap( arr.begin(), arr.end())
  - arr.pop_back()

  4. sort_heap
     -sort_heap(arr.begin(), arr.end() )

- Set Algorithm

  1. set_union
  2. set_intersectiom
  3. set-diffrence
  4. set_symmetric_diffrence
