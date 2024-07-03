- STL : Standard Template Library

- Common Componnet in STL:

  - Container
  - Algorithms
  - Iterators
  - Functors

- Containers :

1. Vectors

   - Dynamic Array that grow and shrink in size.

- How to create dynmaic size array in CPP?
  int n ;
  cin >> n;
  int \* arr = new int[n];

- Vectors in CPP

  - Include in header file : include<vector>
  - Declaration : vectore< data_type > name_of_vector;
  - Inserting value at end : vector_name.push_back( value )
  - Finding size of vector : vector_name.size()
  - Finding Capacity : vector_name.capacity()
  - Delete value from end : vector_name.pop()
  - Finding element at index : vector_name.at( index ) or vector_name[ index ]
  - Clearing the vector : v.clear()

- Initiliasatio of vector

  - vector< data_type > name_of_vector;
  - vector <int> v;
  - vector < int > arr( 5, -1); size = 5 : data = -1
  - vector < int > arr = { 1,2,3,4,5 };
  - vector < int > v { 1,2,3,4,5,6,7};

- How to copy Vector ?
  vector< int > v = { 1,2,3,4,5};
  vector < int > v2( v );

- Accessing first value v.front()
- Accessing last value v.back()

- Printing Values from vector
  for( auto item : v ){
  cout<<item<<" ";
  }

- Features of vector
  Contiguous Memory
  Dynamic sizing
  Automatic Reallocation
  Dynamic size and capacity
  Array like Acess

- Vector Methods

  1. v.begin() :Return iterator pointing to first position.
  2. v.end() : Return iterator pointing to position after last element,
  3. v.push_back( value ) : add value at end.
  4. v.pop_back( ) : Remove value from end.
  5. v.at( index ) : Return value at index.
  6. v.capacity( ) : Return capacity of vector.
  7. v.size( ) : Return size of vector.
  8. v.reserve( value ) : Defining mimimum size of vector.
  9. v.max_size( value ) : Max size that vector can have.
  10. v.clear() : Will remove all elements from vector.
  11. v.insert( pos, value) : insert value at position pos.
  12. v.erase( start , end ) : Delete all elemets in range start to end.
  13. v.swap( v2 ) : Swap values with vector two.

- Printing Values From Vector

  1. for( int i : v ) cout<<i<<endl;
  2. vector < int > :: iterator it = v.begin();
     while( it != v.end() ){
     cout<<\* it <<" " <<endl;
     it++;
     }

- Creating 2D arrays with vector
  vector< vector <int> > v2d;

2. List
   - Doubly Linked List
   - Allows fast insertions are removal at any location.
   - No random access like vectors.

- Creation of list
  list< int > mylist;

- Methods of list
  1. ml.push_back( v )
  2. ml.push_front( v )
  3. ml.pop_back( v )
  4. ml.pop_front( )
  5. ml.clear()
  6. ml.empty() : check list in empty or not.
  7. ml.front()
  8. ml.back()
  9. ml.begin()
  10. ml.end()
  11. ml.remove( v ) : Remove all occurances of value in list.
  12. ml.swap( ml2 )
  13. ml.insert( pos, value) : insert value at position pos.
  14. ml.erase( pos1,pos2) : delete values from pos1 to pos2.

3. Queue:
   - Provides a first in - first out ( FIFO ) data structure.
   - Declaration
     queue<int> q;

- Methods of Queue:
  1. q.push()
  2. q.pop()
  3. q.size()
  4. q.front()
  5. q.back()
  6. q.empty()
  7. q.swap(q2)

4. Stack
   - Provides last in - first out (FIFO) data structure.
   - Declaration
     stack < int > st;

- Methods of Stack
  1. st.push( v )
  2. st.size()
  3. st.top()
  4. st.empty()
  5. st.swap( st2)

5. Deque
   - Double ended queue
   - Declaration
     deque< int > dq;

- Methods of Deque
  1. dq.push_back()
  2. dq.push_front()
  3. dq.pop_front()
  4. dq.pop_back()
  5. dq.size()
  6. dq.front()
  7. dq.back()
  8. dq.clear()
  9. dq.empty()
  10. dq.begin()
  11. dq.end()
  12. dq[index]
  13. dq.at( index )
  14. dq.insert()
  15. dq.erase()
  16. dq.swap()

6. Priority Queue
   -Declaration
   - priority_queue<int> pq;

- Methods of Priority Queue
  1. pq.push()
  2. pq.pop()
  3. pq.top()
  4. pq.size()
  5. pq.empty()
  6. pq.clear()
  7. pq.swap( pq1 )

7. Map
   -Container that store data into key and value pair.

   1. unorderd_map
   2. ordered_map

   -Declaration
   unordered_map < string , string > table;
   table['in'] = "India"
   table.insert( make_pair("en", "England"))

- Map Methods
  table.size()
  table.empty()
  table.begin()
  table.find()
  table.clear()
  table.at('key')
  table.end()
  table.count('in')

8. Set
   - Sorted collections of unique elements.
     set<int> st;
     unorderd_set<int> st;

- Set Methods
  set.insert()
  set.end()
  set.find()
  set.begin()
  set.size()
  set.count()
