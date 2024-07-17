- Objects
  objects are entities in real world.

- Class
  class is blueprint of these entities.

- Syntax
  class ClassName{

  //propeties
  string name;
  ...
  ...
  ...

  //methods
  void changeName( string names){
  this->name = name;
  }
  ...
  ...
  ...

  };

- Creating objects;

  ClassName Obj1;
  ClassName Obj2;
  ClassName Obj3;

// Access propeties of object using . dot operatot.
cout<<Ob1.name<<end;
Obj1.changeName( "Harsh" );

- If we do not declare access modifiers then all data and data members are private.

- Access Modifiers

  1. private - data and data members are accessible only inside class
  2. public - data and data members are available everywhere
  3. protected - data and data members are accessible inside same and derrived class only.

- Pillars of OOPS

  1. Encapsulation
  2. Inheritance
  3. Polymorphism
  4. Abstraction

- Encapsulation

  1. Encapsulation is wraping up data and member functions in a single unit.
  2. Helps in hiding data.

- this pointer :: this is a special c++ pointer that points to current object.
  this-> prop is \*(this).prop
- Constructor

  1. Special method called automatically when object is created.
  2. Same as class name;
  3. Constructor doesnt have return type
  4. Only called once when object created.
  5. Memory allocation happens when constructor called.
  6. declared as piblic every time;
  7. Multiple constructor may present in class but with diffrent parameters.

- Types of constructor

  1. Non parameterized
  2. Parameterized
  3. Copy constructor

- Copy Constructor
  Special constructor used to copy values of one object to another object.
  CPP gives it as default.

- Shallow and Deep copy

  1. A shallow copy of an object copies all the member values from one object to another.
  2. A deep copy, on other hand, not only copies the member values but also makes copies of a dynaically allocated memory that the member points to.

- Destructor

  1. Oppposite to constructor.
  2. Used to deallocate the memory.

- Inheritance

  1.  When properties and member functions of base class are passed on to the derrived class.
  2.  Used for code reusability.
  3.  Parent constructor called first then child constructor.
  4.  Child destructor called first then parent destructor.

- Modes of Inheritance

Base Class    Derived Class   Derived Class   Derived Class
              Public          Protected       Private
Public        Public          Protected       Private
Protected     Protected       Protected       Private
Private       Not Accessible  Not Accessible  Not Accessible

-Types of Inheritance

1. Single Inheritance
2. Multi level inheritance
3. Multiple inheritance
4. Hierarchical inheritance
5. Hybrid inheritance

- Polymorphism

  1. Polymorphism is a ability of objects to take diffrent forms or behave in n diffrent ways depending on a context they are used.
  2. Compile time polymorphism
  3. Run time polymorphism

- Compile time polymorphism

  1. Function Overloading - Same name of function with diffrent paramaters
  2. Operator Overloading - Same operator used with multiple operation

- Run time polymorphism

  1. Function Overriding
  2. Parent and child contain the same function with diffrent implementation. The parent class function said to be overridden.
  3. Virtual Functions
  4. A virtual function is member function that you expect to be redefined by in derrived class.
  5. Virtual funtions are dynamic in nature.
  6. Defined by keyword virtual inside a base class and are always declared with base class and overriden in child class.
  7. A virtual function is called in run time.

- Abstraction

  1. Hinding all unnecessary details and showing only the important part.
  2. By using abstract class we can achive abstraction.
  3. use abstract keyword before class keyword.
  4. Abstarct classed are used to provide a base class from which other class can be derrived.
  5. They can not be instantiated and meant to be inherited.
  6. Abstract classes are typically used to define an interface for derived classes.

- Static Keyword
  1. Static Variables:
     - Varibles declared static in a function are created and initilised once for the lifetime of the programm.
     - Static variables in a class are created and initised once. They are shared by all the object of the class.
