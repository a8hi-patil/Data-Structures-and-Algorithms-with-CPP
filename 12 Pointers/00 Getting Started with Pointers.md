- Pointer

- Variable int a = 5;
- Pointer int \*aptr = &a;

-Declaration

    int       *ptr        =       &a;
    data_type name    assignment   address;

-Types

    1. Integer Pointer  int *ptr;
    2. Character Pointer char * ctr;
    3. Short Pointer    short *sptr;
    4. Long Pointer     long *lprt;
    5. Cutome Pointer   babbar *bptr;

- \* is a dereference Operator or Value at adress operator

- Size of pointer is always 8 bits.

- Null Pointer int \*ptr = 0;

- Copying Pointer
  int a = 10;
  int *p = &a;
  int *q = p;

- Pointers With Arrays

  int \*ptr = arr;
  arr[0] = 10;
  &arr[0] = 104;

- int arr[] = {10,20,30,40};
  int \*ptr = arr;

-Catch Why arr[i] == i[arr]
_(arr + i) == _ ( i + arr)

- Character Arrays

  char arr[100]= "Babbar";
  char *ptr = ch;
  cout<<*prt<<endl; -> "Babbar";

- Double Pointers

  Pointers Pointing to other pointers.

  int a = 10;  
   int *p = &a; *p
  int **q = &p; **q
