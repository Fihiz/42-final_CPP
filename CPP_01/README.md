# C++
## Module 01

Day 01 [subject](https://cdn.intra.42.fr/pdf/pdf/20254/fr.subject.pdf)

## To understand [new](https://en.cppreference.com/w/cpp/memory/new/operator_new) and [delete](https://www.cplusplus.com/reference/new/operator%20delete/).

Our first purpose is to imagine that our previous *malloc* and *free* will become *new* and *delete* in our CPP works.

Why ?
Calling a malloc in CPP would make confusion by the simple way that malloc wouldn't call our Constructor for our object. Meaning, that would be a disaster. Calling __new__ and __delete__, it will absolutely use malloc in the same way and also call our constructor and destructor properly for our objetcs. In the same way, free wouldn't call the destructor.

*Student.class.hpp*
```cpp
#include <iostream>

class Student
{
    private:
        std::string _login;

    public:
        Student(std::string login) : _login(login)
        {
            std::cout << "Student " << this->_login << " is born" << std::endl; //Here I declare and define my constructor in the same file
        }

        ~Student()
        {
            std::cout << "Student " << this->_login << " died" << std::endl;
        }

};
```

```cpp
#include "Student.class.hpp"

int     main()
{
    Student     bob = Student("bfubar"); //Allocates statically a student on the stack (la pile)
    Student*    jim = new Student("jfubar"); 
    //Allocates dynamically(so I need a pointer (to access it out of the scope?)) a student on the heap (le tas): malloc is used, then it calls Student constructor to initialize it and then return a pointer on my Student instance
    
    // Do some stuff here

    delete jim; //Jim is destroyed, new -> delete

    return (0); //Bob is destoyed
}
```

---

*Student.class.hpp*
```cpp
#include <iostream>

class Student
{
    private:
        std::string _login;

    public:
        Student( void ) : _login("ldefault") //Constructor that doesn't take a parameter
        {
            std::cout << "Student " << this->_login << " is born" << std::endl; //Here I declare and define my constructor in the same file
        }

        ~Student()
        {
            std::cout << "Student " << this->_login << " died" << std::endl;
        }

};
```

```cpp
#include "Student.class.hpp"

int     main()
{
    Student*    students = new Student[42];
    // In case of an array, I can't directly pass parameters
    
    // Do some stuff here

    delete [] students; //Destroys my students array (cf contact[8])

    return (0); //Bob is destoyed
}
```

---

## To understand [references](https://www.geeksforgeeks.org/pointers-vs-references-cpp/).

```cpp
#include "Student.class.hpp"

int     main()
{
    int     numberOfBalls = 42;

    int*    ballsPtr = &numberOfBalls; // A pointer on my previous int, that I initialize on the numberOfBalls adress
    int&    ballsRef = numberOfBalls; //(& is the type to indicate reference), Here I affect to ballsRef, directly the variable numberOfBalls (and not its adress).
    //The reference points on the variable, at this time I can't change what my reference points on (it's like a const pointer, always points on the same thing (to keep an old state...?)).
    // A reference cant point on nothing, it always has to be affected on something (initializated)

    std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

    // 1. Variable itself

    // 2. I'll use my ballsPtr which currently points on numberOfBalls (cause I initialized it with numberOfBalls adress) and I'll dereference it to acces to what the pointer points
    
    //3. I directly use ballsRef (no need to write& or anything) -> a reference is always like a dereferenced pointer (reference -> put a *), dereference is accessing to what the pointers point, so reference no need to be dereferenced (its always its state, a bit like an alias), at any time ballsRef makes reference to numberOfBalls
    
    //meaning, I print numberOfBalls three times: Once by the variable itself, once by the pointer and once by the reference


    *ballsPtr = 21; //Here I dereference my pointer to access to affect 21 value to numberOfBalls
    std::cout << numberOfBalls << std::endl; //Now prints 21
    ballsRef = 84; //If I want to affect something to my reference, I can directly affect with ballsRef =
    std::cout << numberOfBalls << std::endl; //Here it prints 84

    //result: 42,42,42,21,84

    return (0); //Bob is destoyed
}
```

__Pointers__: A pointer is a variable that holds memory address of another variable. A pointer needs to be dereferenced with * operator to access the memory location it points to. 

__References__ : A reference variable is an alias, that is, another name for an already existing variable. A reference, like a pointer, is also implemented by storing the address of an object. A reference can be thought of as a constant pointer (not to be confused with a pointer to a constant value!) with automatic indirection, i.e the compiler will apply the * operator for you.

```c
int i = 3; 

// A pointer to variable i (or stores address of i)
int *ptr = &i; 

// A reference (or alias) for i
int &ref = i; 
```

Until there, we use to have pointers for function parameters. Now I also can use references.

```cpp

void    byPtr(std::string* str) //Pointer
{
    *str += " and ponies";
}

void    byConstPtr(std::string const * str)
{
    std::cout << *str << std::endl;
}

void    byRef(std::string& str) //Reference
{
    str += " and ponies";
}

void    byConstRef(std::string const & str)
{
    std::cout << str << std::endl;
}

int     main()
{
    std::string str = "i like butterflies";

    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);
    byRef(&str);
    byConstRef(&str);
}

```

Now, let's see return by reference.

```cpp

#include <iostream>

class Student
{
    private:
        std::string _login;
    public: //Member functions that return 
        Student(std::string const & login) : _login(login)
        {
        }

        std::string&    getLoginRef() //A reference on the login
        {
            return this->_login;
        }

        std::string const & getLoginRefConst() const //A const reference on the login
        {
            return this->_login;
        }

        std::string*        getLoginPtr() //A pointer on the login
        {
            return &(this->_login);
        }

        std::string const * getLoginPtrConst() const 
        {
            return &(this->_login);
        }
}

int main()
{
    Student         bob = Student("bfubar");
    Student const   jim = Student("jfubar");

    std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
    std::cout << *(bob.getLoginRefConst()) << " " << *(jim.getLoginRefConst()) << std::endl;

    bob.getLoginRef() = "bobfubar"; //Same thing, here I directly use the reference
    std::cout << bob.getLoginRefConst() << std::endl;

    *(bob.getLoginRef()) = "bobbyfubar"; //Same thing, here I use a pointer that I dereference to affect something
    std::cout << bob.getLoginRefConst() << std::endl;
}
```

To think that now I'll only use reference because it's easier than pointer is a bad idea, 
reference complete pointer but won't replace it ! Even if the syntax is easier.
Remember that a reference is a bit like a non null pointer, constant and always dereferenced.
But, as seen before, I can't have a reference and not initialize it. It means, in case of an object that has a reference on a another object that is not initialized at its construction Example: A class that describes a playrole character, this character may have a weapon or not, but if I make reference in this case I'll have a weapon but not always want to have it, the difference with a pointer is that in first I can point on nothing and then point on a new weapon and change it or loose it...)
Rule -> If at a moment, it has to disappear or not exist, or change : I use a pointer
        If it has to always being existing, I'll use a reference (need to clear the difference with a static...)

## To understand [filestream]()

As there are streams to act on output/input standard, there are streams to act on files

```cpp

#include <iostream>
#include <fstream>

int     main()
{
    std::ifstream   ifs("numbers"); //ifs means Input File Stream
    unsigned int    dst;
    unsigned int    dst2;
    ifs >> dst >> dst2;

    std::cout << dst << " " << dst2 << std::endl;
    ifs.close();

    std::ofstream   ofs("test.out"); //create a test.out file

    ofs << "i like ponies a whole damn lot" << std::endl; //ofs means Output File Stream
	ofs.close();
}

```