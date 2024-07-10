 #include<iostream>
 using namespace std;

 double squareWithPrecision( int num){
    double start = 0 ;
    double end = num;
    double mid = start + ( end - start) / 2;
    double ans = 0;
    while (( end - start )> 0.001 )
    {
       double sqr = mid*mid;
       if( sqr <= num){
        ans = mid;
        start = mid;
       }else{
        end = mid;
       }
       mid = start + ( end - start) / 2;
    }
    return ans;
 }

int main(){
    cout<<"Enter a number : ";
    int num ;
    cin>>num;
    cout<<"Square root of the number "<<num<<" is "<<squareWithPrecision(num)<<endl;
}