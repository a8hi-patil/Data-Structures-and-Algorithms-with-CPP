#include<iostream>
#include<vector>
using namespace std;
int findCommonElement(int a1[],int n1,int a2[],int n2,int a3[],int n3){
    int i =0;
    int k =0;
    int j =0;
    while( i < n1 && j < n2 && k < n3){
        if( a1[i]==a2[j] && a2[j]==a3[k]){
            return a1[i];
        }else if( a1[i] < a2[j]){
            i++;
        }else if( a2[j] < a3[k]){
            j++;
        }else{
            k++;
        }
    }
    return -1;
}
int main()
{
    int arr1[] = { 1, 5, 10, 20, 40, 80 };
    int arr2[] = { 6, 7, 20, 80, 100 };
    int arr3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int commonEle = findCommonElement(arr1,n1,arr2,n2,arr3,n3);
    cout<<"Common element is "<<commonEle<<endl;
    return 0;
}