- (String)  
Learn the foundations of object-oriented programming in C++ with memory management and operator overloading, applied through a custom STRING class.
Specifically:  
  - Classes & Objects: how to define a class with private data and public methods.
  - Constructors & Destructor: default, parameterized, copy constructor, and how to manage dynamic memory safely.
  - Operator Overloading: customizing =, +, +=, ==, <, >, [], and stream operators (<<, >>).
  - Getters & Setters: controlled access to private members.
  - Dynamic Memory Management: using new, delete, and avoiding memory leaks.
  - Friend Functions: how external functions can access private class members.
  - Static Members: variables and methods shared across all objects of a class.
  - References & const: passing by reference and using const for safety.
  - String Manipulation: building a custom string class instead of using std::string.

- (Classes)  
This project teaches OOP in C++ with inheritance, polymorphism, memory management, and object collections, applied in a card game simulation.  
Specifically:  
  - Inheritance & Polymorphism → how derived classes (creature, land) extend a base class (card) and override virtual methods.
  - Abstract Classes → using pure virtual functions (clone, print) to enforce behavior in derived classes.
  - Dynamic Binding → calling overridden methods through base class pointers/references.
  - Deep Copy & Cloning → safely copying objects with clone() and copy constructors.
  - Dynamic Memory Management → creating and destroying arrays of pointers (new, delete).
  - Operator Overloading → redefining << for custom printing of objects.
  - Static Members → shared constants (max_cards, max_hand).
  - Randomization & Composition → building collections (pool, hand) that store different card types and select randomly.

- (Array)  
Here is shown how to build a flexible, reusable container class using templates, memory management, and operator overloading.  
Specifically:  
  - Templates → how to write generic classes (ARRAY<T>) that work with any data type.
  - Dynamic Memory Management → allocating and freeing arrays of type T.
  - Operator Overloading → redefining [], =, +=, and << for template classes.
  - Copy Constructor & Assignment → handling deep copies in templated objects.
  - Static Members in Templates → each data type specialization has its own static members.
