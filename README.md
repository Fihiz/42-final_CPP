# C++
## Module 00

Day 00 [subject](https://cdn.intra.42.fr/pdf/pdf/16907/fr.subject.pdf). Here is a [first approach](https://www.w3schools.com/cpp/).

The [four principles](https://www.freecodecamp.org/news/object-oriented-programming-concepts-21bb035f7260/) of [object-oriented programming](https://www.techno-science.net/definition/5393.html) are encapsulation, abstraction, inheritance, and polymorphism.

---

## To understand the [namespace](https://www.geeksforgeeks.org/namespace-in-c/#:~:text=Namespace%20is%20a%20feature%20added,declared%20in%20the%20named%20scope.) notion.

```cpp
printf("Foo::gl_var: [%d]\n", Foo::gl_var );
```

*means: among the "Foo" namespace, I want to get the gl_var value, thanks to the [scope resolution operator](https://www.geeksforgeeks.org/scope-resolution-operator-in-c/) [::] -> variables can be accessed from outside the namespace using it.*
**In our case, we'll use a lot the**```std::```

---

## To understand the [Stdio streams](https://www.cplusplus.com/doc/tutorial/basic_io/) with the [iostream library](https://www.cplusplus.com/reference/iostream/).

```cpp
std::cout << "Hello World !" <<std::endl;
```
*means: thanks to [<<] operator, I redirect my "Hello World !" string into the stdout -> The [<<] operator inserts the data that follows it into the stream that precedes it. Also, the endl manipulator produces a newline character, exactly as '\n'.*

```cpp
#include <iostream>

int     main(void)
{
    char buf[512];

    std::cout << "Input a word: ";
    std::cin >> buf;
    std::cout << "You entered: [" << buf << "]" << std::endl;

    return 0;
}
```
*means: here, I'll catch the input data, redirecting it with [>>] operator from std::cin, to get it into my buf variable, which is a tab of 512 chars. Then I can print my buffer string on the stdin.*

---

## To understand the [class and instance](https://www.geeksforgeeks.org/c-classes-and-objects/).

*A Class could be compared to an architect plan for a home. Before to be able to build it, we must have a plan. It is the same for an object, we need to create its plan, and then we can build as objects as we want to from its class. Or a cake mold ! And do as cakes as we want to, our __instances__...* \
>__Class :__ *A class in C++ is the building block, that leads to Object-Oriented programming. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.*

---

*Class declaration*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    Sample( void ); //constructor
    ~Sample ( void ); //destructor (~ marks which is the destructor)

}; //semicolon is imperative to not have any error while compiling

#endif // ****** SAMPLE_CLASS_H
```

---

*Sample.class.cpp*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) //Into the Sample class, I want to access to the constructor function (Syntax with [::] as namespace relation...)
{
    std::cout << "Constructor called" << std::endl;
    return; //To indicate that Constructor finished (only indicative)
}
//Constructor and Destructor never take a type return
Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return; //End procedure indication
}
```
---

*Now, how to use my Class*
```cpp
#include "Sample.class.hpp"

int     main()
{
    Sample  cake; //My Class instance declaration, by it, I now have an instance variable named cake from the Sample class

    return (0);
}
```
*Class is the static part, it's a model. Our instance mold, that allow us to create as instances as needed.*
*Instanciating my class as above, I'll automatically call my __Constructor__.*
*Then, as in a C scope, all the local variables will be destroyed. Here in our example, my local instance variable will be destroyed by its __Destructor__ at the end of the main.*

```Class, instance, definition and declaration are key-notions. In our .h/.hpp, we can declare our class and its functions/attributes. Then, in our .cpp, we can define its member functions using a specific syntax (similar to the namespace).```

---

## To understand the [member attributes and member functions](https://www.geeksforgeeks.org/c-classes-and-objects/).

*Class declaration with a member attribute*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    int     foo; //A member attribute is a variable located into our class

    Sample( void );
    ~Sample( void );

    void    bar( void );    //We can directly have a function into our class
                            //in contrary to the Constructor and Destructor, it takes a type

	// Foo variable (attribute) and bar function (member function) will be usable each time I instantiate my class
};

#endif 
```
---

*Sample.class.cpp with a member function*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor called" << std::endl;

	this->foo = 42; //[this] is a pointer, points to the variable of the current instance 
					//(here I use [->] to dereference this pointer, similar to a struct in C)
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar(); //In cpp, we can call a member function with [this] pointer in the current instance

    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar( void ) //Member function has a return type, apparently not any parameter but not always the case...
{
    std::cout << "Member function bar called" << std::endl;
    return;
}
```

---

*Now, how to use my Class with its member function*
```cpp
#include "Sample.class.hpp"

int     main()
{
    Sample  cake; //Instantiating and calling the constructor

    cake.foo = 42; //Giving a value to my foo int located into my class
    std::cout << "instance.foo: " << instance.foo << std::endl;

    cake.bar(); //Calling my member bar function of my instance from the Sample class
    return (0); //Calling the destructor at the end
}
```
*Within the code of a member function (a constructor, destructor or another function ...), if we want to refer to our current instance, we will use the __this instance pointer__.*

---

## To understand the [initialization list]().

*Class declaration with attributes*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample1 {

public:

    char	a1; //Attributes
	int		a2;
	float	a3;

    Sample1( char p1, int p2, float p3 ); // Here I'll instanciate my three class attributes with these three parameters
    ~Sample1( void );

};

#endif
```

---

*Sample.class.cpp with a member function*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample1::Sample1( char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3) //Initialize my attributes
{
    std::cout << "Constructor called" << std::endl;
	//Similar in this example to : this->a1 = p1;...
	std::cout << "this->a1: " << this->a1 << std::endl;
	std::cout << "this->a2: " << this->a2 << std::endl;
	std::cout << "this->a3: " << this->a3 << std::endl;

    return;
}

Sample1::~Sample1( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

```
*Now, let's see our initialization comipiling*
```cpp
#include "Sample1.class.hpp"

int     main()
{
    Sample1  cake1( 'a', 42, 4.2f ); //Giving my three parameters

    return (0);
}
```
---

## To understand the [const variable]().

> Make your code as constant as possible, it will only be better.

*Class declaration with const*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    float const	pi; //Attributes
	int			qd;
	float	a3;

    Sample( float const f ); // Here I'll instanciate my three class attributes with these three parameters
    ~Sample( void );

	void		bar( void ) const; //Const key-word in my member function at its declaration, means to the compilator that the function will never modificate the current instance (this->an_attribute = value... is impossible)

};

#endif
```

---

*Sample.class.cpp with a const*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( float const f ) : pi( f ), qd( 42 ) //Initialize my attributes
{
    std::cout << "Constructor called" << std::endl;

    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar( void ) const //Const key-word in my member function at its definition
{
    std::cout << "Member function bar called" << std::endl;
	std::cout << "this->pi: " << this->pi << std::endl;
	std::cout << "this->qd: " << this->qd << std::endl;
    return;
}

```

> If we write a member function that does not modify the instance of our class, declare it and set it to const automatically. The more const and read-only the code, the more robust it will be.

## To understand the [encapsulation](https://waytolearnx.com/2019/09/encapsulation-en-cpp.html).

*Class declaration with public/private mode -> encapsulation*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {    //By default, if there is no precision, a class is private (structure is the contrary -> public)

public:            //Controlling what is visible from the exterior (reachable from inside and outside the class)

    int     publicFoo;

    Sample( char p1, int p2, float p3 ); //Means it's important to let the constructor and destructor reachable in the public part (exceptions)
    ~Sample( void );

    void    _publicBar( void ) const;

private: //(Only reachable from the class inside, invisible from outside) 
        //Allow to mask the implementation of our programm, only make visible what is useful for the user

    int     _privateFoo;

    void    _privateBar( void ) const; //underscore is well to prefix our private (convention)

};

#endif
```

---

*Sample.class.cpp with private and public class*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor called" << std::endl;
    // Being into my constructor, I can as well reach private and public part
    this->publicFoo = 0;
    this->_privateFoo = 0;
    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar( void ) const
{
    std::cout << "Member function bar called" << std::endl;
    return;
}

```

---

## To understand the [accessors]().

*Class declaration with accessors*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    Sample( void );
    ~Sample( void );

    int     getFoo ( void ) const; //Accessor (by convention, prefixed by get and set) + const, cause my accessor read only and won't modify
    void    setFoo( int v );
    int     compare( Sample * other) const; //Takes an adress in parameter to compare it with the current instance

private:

    int     _Foo; //I don't want my user has a direct access, but a controlled one that I can exercise 

};

#endif
```

---

*Sample.class.cpp with private and public class*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor called" << std::endl;
    // Being into my constructor, I can as well reach private and public part
    this->publicFoo = 0;
    this->_privateFoo = 0;
    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::getFoo( void ) const
{
    return this->_foo; //Only returns a copy if my user decides to modify its value (protecting my intern state class)
}

int     Sample::compare( Sample * other ) const
{
    if ( this->_foo < other->getFoo() ) //Using get foo accessor cause foo is private
        return -1;
    else if ( this->_foo > other->getFoo() )
        return 1;
    
    return 0;
}

void    Sample::setFoo( int v )
{
    if ( v >= 0 )  //Getting the val user wants to attribute to foo, if it's positive, I allow assignation
        this->_foo = v;
    
    return;
}

```

## To understand the [non member attributes and non member functions](https://stackoverflow.com/questions/5920916/c-difference-between-member-and-non-member-functions).

*Class declaration and non member stuffs -> static*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    Sample( void );
    ~Sample( void );

    static int     getNbInst ( void ); //I'd like to count the number instances (only has a sense for the class but not for the instance so I can do it in static...)

private:

    int     _nbInst; //I don't want my user has a direct access, but a controlled one that I can exercise 

};

#endif
```

---

*Sample.class.cpp with private static function*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor called" << std::endl;
    Sample::_nbInst += 1; //Incrementing each thime contructor is called -> means eache instanciation

    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    Sample::_nbInst -= 1;

    return;
}

int     Sample::getNbInst( void )
{
    return Sample::_nbInst;
}

int     Sample::_nbInst = 0; //Initializing (only way with this syntax to initialize a non member attribute)

```
> A non-member function has no implicit this. It gets an implicit object pointer via this (only has access to public members).
---

*Now, let's see our pointer on member attribute*
```cpp
#include <iostream>
#include "Sample.class.hpp"

int     main()
{
    Sample  cake;
    Sample * cakep = &cake; // Pointer taking the adress

    int     Sample::*p = NULL; // Pointer that can get an adress of an attribute member (Sample:: makes declare a pointer on an int which is member of my class)
    void    (Sample::*f)( void ) const;

    p = &Sample::foo;

    instance.*p = 21;
    instance.*p = 42;

    f = &Sample::bar; //Pointinf on my member function bar

    (instance.*f)(); //.*(not a pointer) and .->(pointer) to know which instance
    (instance->*f)();

    return (0);
}
```
---

# Summary

> To create an object, I must create a class upstream. 
Creating a class, I draw the plans of my object (metaphore: to build a home, I'll need a plan). When I got my class, I can create as objects as I want. \
*Vocabulary: we say that an object is an instance of a class. This means that an object is the concrete materialization of a class (just as the house is the concrete materialisation of the plan of the house).*

---

![schema](https://user.oc-static.com/files/225001_226000/225311.png)

> In our class, we'll put __attributes__ : this is the name we give to the variables inside our class. And __methods__ : this is the name we give to the functions inside our class. The main question is : __what are the attributes and methods I'll need to draw my class ?__
Methods can be seen as actions that my object (instance from class) can do.
After declaring my attributes and methods into my class in my .hpp, I can intialize these attributes in the __constructor__.

> In short, __an object is indeed a mix of variables (attributes) and functions (methods)__. Most of the time, the methods read and modify the attributes of the object to make it evolve. An object is ultimately a small, intelligent and autonomous system, capable of monitoring its proper functioning on its own.

> __Encapsulation__: Each attribute and method can have its own right access.
__public__: the attribute or the method can be called from outside the object.
__private__: the attribute or the method cannot be called from outside the object. By default, all elements of a class are private. By example, making attributes private and methods public means my user can't modify any attribute of my object (from the main).
A __static member variable__ is a var that still existing in only one exemplar, no matter the number on instances of it.

### Encapsulation : all class attributes must be private.

> Indeed, the purpose of the object model is precisely to hide complex information (attributes) from the user to prevent him from doing anything stupid with it. And manage his action by accessors (ex: validate a number the user want to assign in negative, but I only accept his modification if it's positive).
Making my method prototype into my class in my .h, I can make definitions into an equivalent file in cpp and call as : Contact::addContact(void); ->constructor.
This lets the compiler know that this method relates to the class.
