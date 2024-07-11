
#include <iostream> 
#include <string.h> 
using namespace std;
int main() 
{ 
	char example[100]; 
	strcpy(example, "Abhi "); 
	strcat(example, "Patil"); 
	cout<<example<<endl;
    int length = strlen(example);
    cout<<"Lenght of string is "<<length<<endl;
	return 0; 
}
