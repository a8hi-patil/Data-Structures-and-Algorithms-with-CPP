Q1
float f = 10.5;
float p = 2.5;
float *ptr = &f;
(*ptr)++;
*ptr = p;
cout<<*ptr<<" "<<f<<" "<<p<<endl;
-> 2.5 2.5 2.5

Q2
int a = 7;
int b = 17;
int *c = &b;
*c = 7;
cout<<a<<" "<<b<<endl;
-> 7 7

Q3
int *ptr = 0;
int a = 10;
*ptr = a;
cout<<\*prt<<endl;
-> Error Assignment to Null Pointer

Q4 Which of the following gives the memory address of variables pointed by pointer 'a'
itn b = 10;
int \*a =&b;
->a

Q5
char ch = 'a';
char *ptr = &ch;
ch++;
cout<<*ptr<<endl;
-> b

Q6
int a = 7;
int \*c = &a;
c = c+1;
cout<<a<<" "<<c<<endl;
->7 Garbage Value

Q7 Assumen memory address of variable 'a' is 400 and an integer take 4 bytes what will be the output.
int a = 7;
int \*c = &a;
c = c +3;
cout<<c<<endl;
->412

Q8 Assume memory address of variable 'a' is 200 and a double variable of size 8 bytes what will be the output?
double a = 10.54;
double \*d = &a;
d = d+1;
cout<<d<<endl;
->208

Q9 Assume integer takes 4 bytes and intger pointer 8 bytes.
int a[5];
int \*c;
cout<<sizeOf(a)<<sizeof(c)<<endl;
->20 8

Q10
int a[] = {1,2,3,4};
cout<<_(a)<<_(a+1)<<endl;
-> 1 2

Q12
int a[] ={1,2,3,4};
int *p = a++;
cout<<*p<<endl;
->1

Q13
int arr[] = {4,5,6,7};
int *p = (arr+1);
cout<<*arr+9<<endl;
->13

Q14 Assume address of 0th index of array is b is 200.
char b[]="xyz";
char \*c = &b[0];
cout<<c<<endl;
->xyz

Q15
char s[] = "hello";
char \*p=s;
cout<<s[0]<<p[0]<<endl;
->h h

Q16
char arr[20];
int i;
for( i = 0 ; i<10 ; i++){
_(arr+1) = 65+i;
}
_(arr+i) ='\0';
cout<<arr<<endl;
-> ABCDEFGHI

Q17
char \*ptr;
char str[] = "abcdefg"
ptr = str;
ptr += 5;
cout<<ptr<<endl;
-> fg

Q18
int number[5]
int *p;
p=number;
*p=10;
p = &number[2];
*p =20;
p--;
*p = 30;
p = number + 2;
_p = 40;
p = number;
_(p+4)=50;
cout<<number array<<endl;
->10 30 20 40 50

Q19
char st[] = "ABCD";
for( int i= 0 ; i!='\0' ;i++){
cout<<st[i]<<_(st)+i<<_(i+st)<<i[st]<<endl;
}
-> A 65 A A
-> B 66 B B
-> C 67 C C
-> D 68 D D

Q20
float arr[5] = {12.5,10.0,13.5,90.5,0.5};
float *ptr1 = &arr[0];
float *ptr2 = ptr1 + 3;
cout<<\*ptr2<<endl;
cout<<ptr2-ptr1<<endl;
->90.5
->3

Q21

    void changeSign( int *p){
        *p = (*p)*-1;
    }
    int main() {
        int a = 10;
        changeSign( &a);
        cout<<a<<endl;
    }
    -> -10

Q22
void fun( int a[]){
cout<<a[0]<<" "<<endl;
}
int main(){
int a[]= { 1,2,3,4};
fun(a+1);
cout<<a[0]<<endl;
}
->2 1

Q23
void square( int *p){
int a = 10;
p=&a;
*p = (_p) _ (\*p);
}
int main(){
int a = 10;
square(&a);
cout<<a<<endl;
}
->10

Q24
void Q( int z){
z+=z;
cout<<z<<endl;
}
void P( int *y){
int x = *y +z;
Q(x);
\*y= x-1;
cout<<x<<endl;
}
int main(){
int x = 5;
P(&x);
cout<<x<<endl;
return 0;
}
-> 14 7 6

Q25
int a = 10;
int *p = &a;
int \*\*q = &p;
int b =20;
int *q = &b;
(\*p)++;
cout<<a<<b<<endl;
-> 10 21

Q26
int f( int x, int *py, int **ppz){
int y,z;
**ppz+=1;
z=\*\*ppz;
*py+=2;
y=*py;
x+=3;
return x+y+z;
}
int main(){
int c,*b,\*\*a;
c =4;
b=&c;
a =&b;
cout<<f(c,b,a)<<endl;
}
->18

Q27
int **\*r,**q,\*p,i=8;
p=&i;
(*p)++;
q=&p;
(\*\*q)++;
r=&q;
cout<<*p<<**q<<\***r<<endl;
->10 10 10

Q28
void increment( int **p){
(**p)++;
}
int main(){
int num = 10;
int \*ptr = &num;
increment(&ptr);
cout<<num<<endl;
}
->11
