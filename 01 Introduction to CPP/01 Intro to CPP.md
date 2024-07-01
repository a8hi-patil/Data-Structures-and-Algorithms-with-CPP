** What is CPP ?
-> Cpp is most popular cross platform programming language. which is used to created high performance applications such as OS, games etc.
   It was developed by Bjarne Stroustrup as an extension of C language. C++ give high level of control over system resources and memory

** First program in CPP

    #include<iostrem>                           -> Header files for input output
    using namespace std;
    int main(){                                 -> main method of program
        cout << "Hello World " << endl;         -> Prints hello world
        return 0;
    }

    ** #include
        This is pre-processor directive. This tell compiler to include the mentioned header file into the source code.

    ** using namespace std;
        This is used to import entity of std namespace into the current namespace of program.

    ** int main () { }
        This is main method of programm. It is also the entry point of the programm.

    ** return 0;
        This indicate that succesfull completion of program.

** C++ Variables
    Variables are nothing but name given to the memory locations.

    ** How to declare a varible

        ** Declaring the single variable
            type variabel_name;
        
        ** Declaring the multiple variables
            type variable_one, varibale_two, varibale_three;

    ** Data type : Type of data stored into the varibale.
    ** Variable Name : Name given to the variable.
    ** Value : The value stored into the variable.

    ** Rules of declaring the variables
        1. Variable name can contain letter, digits, underscores .
        2. Variable name is case sensitive.
        3. Variable name should not contain white spaces or any speacial charater.
        4. Variable name should begin with alphabet or underscore.
        5. We can not user C++ reserved key-words as a variable name.

    ** Variable declaration 
        int number;

    ** Variable initialisation
        number = 20 ;

    ** Variable declaration and defination
        int number = 20;

    ** Types of variables
        1. Local Variables
        2. Static Variables
        3. Instance Variables
    
    ** Defining constant variable
        const int number = 20 ;

** Scope rules in C++
    The scope is the area/block under a variables is visible. We can only refer variable in its scope.

    ** Global Scope
        Global scope variables are available in every part of the programm. 
        Global scope is also called as file scope.
    
    ** Local Scope
        Local variabeles are visible in the block they are declared and in an other blocks which are declared inside it.
        Local scope is also called as block scope.

** Data type in C++

    ** Primitive / Primary
        Integer, Character, Boolean, Floating point, Doble floating point, Void, Void character.

    ** Derived 
        Function, Array, Pointer, Reference.
    
    ** User defined
        Class, Structure, Union, Enum, Typedef.

**Data type modifiers
    Are used to built-in data types to modify the length of data that a perticular data type can hold.
    Data type modifiers are available in C++:
        1. Signed
        2. Unsigned
        3. Short
        4. Long
        

**Data types           Size in bytes

short int                   2
unsigned short int          2
unsigned int                4
int                         4
long int                    4
unsigned long int           4
long long int               8
unsigned long long int      8
signed char                 1
unsigned char               1
float                       4
double                      8
long double                 12


** User inputes

    1. cin>>variable_name;
    2. cin.getline(variable_name, number_of_characters);
    3. cin.get(variable_name, number_of_characters);
    4. cin.read(variable_name,number_of_characters);
    5. cin.ignore();

**Control Flow

    1. If statement
        if( condition ){
            //code
        }
    
    2. If - else statement 
        if( condition ){
            //code
        }else{
            //code
        }
    
    3. If - else - is statement
        if( condition ){
            //code
        } else if( condition ){
            //code
        }else{
            //code
        }
    
    4. Nested if - else statements
        if( condition ){
            if( another_condtion){
                //code
            }else{
                //code
            }
        }else{
            if( an_another_conditon ){
                //code
            }else{
                //code
            }
        }
    
    5. Switch Statement
        switch expression {
            case 1:
            //code
            break;
            
            case 2:
            //code
            break;

            default:
            //code
        } 
    
    6. Conditional Operator
        condition ? true : false;
    
    7. Jump Statement 

        break;
        continue;
        goto ;    -> label;
        return;

** C++ Loops

    1. For loop

        for( initilization ; condition ; updation ){
            //code
        }
    
    2. While loop

        while( condition ){
            //code
        }

    3. Do - while loop

        do{
            //code
        }while( condition )

** C++ Operators
    
    1. Arithmentic Operators
        Increament          ++
        Decreament          --
        Addition            +
        Subraction          -
        Multiplication      *
        Division            /
        Modulo              %

    2. Relational Operators
        ==
        >
        >=
        <
        <=
        !=
        
    3. Logial Operators
        AND         &&
        OR          ||
        NOT         !
    
    4. Bitwise Operators
        AND                 &    
        OR                  |
        XOR                 ^
        Left shift          <<
        Right shift         >>
        Ones compliment     ~

    5. Assignment Operators
        =
        +=
        -=
        *=
        /=

** Functions in C++

    Functions are nothing but re-usable block of code.

    Syntax :

        return_type function_name( parameter_type actual_parameter){
            //code
        };

** Number System
    1. Binary Number System
    2. Decimal Number System


** How to calculate one's compliment

    Flip all digits from 0 to 1 and 1 to 0;
    Ex.
        5  ->  101
           =>  010

** How to calculate two's compliment

    1. Take one's compliment
    2. Add 1 
    Ex.
        5 -> 101
          => 010
             010
            +  1
            ----
          => 011       

** Type Cast in C++
 
    1. Allows you to change the data type of varible.

    ** Implicit type casting
        -Automatic type casting
        -Promotes lower data type to higher order data types.
    
    ** Explicit type casting
        -Manual type casting
        -Use of casting operators to convert data types.
