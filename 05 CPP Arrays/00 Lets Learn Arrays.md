- Array is collection of similar items

- Creation
  int arr [1000]
  data_type name size

- Initialisation
  int arr[5]={1,2,3,4,5}
  int arr[3]={10}
  int arr[]={10,20}

- When we try to access the value which index is not present in array we get garbage value or segmentation failed error.

- Filling the array
  fill(starting_address_of_array,endling_address_of_array,value)
  ex-
  int arr[5];
  fill(arr,arr+5,10);

- arr[i] means value at [ Base address + size * i]
- arr[i] is same as i[arr]
  \*(arr + i) == \*(i + arr)

- Functions with Arrays

  void receiveArray( int arr[ ]){ }
  int main(){
  int array[];
  receiveArray(array);
  }

- Arrays are always passed to function as reference.

- Pair
  Declaration : pair< data_type, data_type> variable_name ( value1,value2)
  : pair<int, int> p (10,20);
  Assignment : p.first = 10;
  p.seconf = 20;
