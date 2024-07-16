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
