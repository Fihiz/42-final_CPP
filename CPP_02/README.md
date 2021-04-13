# C++
## Module 02

Day 02 [subject](https://cdn.intra.42.fr/pdf/pdf/20261/fr.subject.pdf).

## To understand the [polymorphism](https://www.w3schools.com/cpp/cpp_polymorphism.asp) notion.

> Ad hoc polymorphism in C++ is implemented using __overloaded functions__. Function overloading __allows us to define two or more functions with the same name in the same scope__ (and may have different parameters). Overloaded functions are distinct and potentially heterogeneous implementations over a range of specific types.

*Sample.class.hpp*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    Sample( void );
    ~Sample ( void );

    // Here lie four overloading functions of a member function called bar: all functions 
    // have the same name, but different parameters for each overloading (Must precise 
    // that overloading is not only dedicated to a member functions). It allows us to 
    //specialize the function treatment according to its entry.

    void    bar( char const c ) const;      // Overloading of the bar function on a char
    void    bar( int const c ) const;       // Overloading of the bar function on an int
    void    bar( float const z ) const;     // Overloading of the bar function on a float
    void    bar( Sample const & i ) const;  // Overloading of the bar function on Sample const ref

};

#endif
```

*Sample.class.cpp*
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar( char const c ) const
{
    std::cout << "Member function bar called with char overload" << std::endl;
    return;
}

void    Sample::bar( int const n ) const
{
    std::cout << "Member function bar called with int overload" << std::endl;
    return;
}

void    Sample::bar( float const z ) const
{
    std::cout << "Member function bar called with float overload" << std::endl;
    return;
}

void    Sample::bar( Sample const & i ) const
{
    ( void ) i;
    std::cout << "Member function bar called with Sample const ref overload" << std::endl;
    return;
}

```

## To understand the [operator overloading](https://en.cppreference.com/w/cpp/language/operators) notion.

### C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

> An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).

>__When you call an overloaded function or operator, the compiler determines the most appropriate definition to use__, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload resolution.

---

```
Three ways to write simple arithmetic expressions

+(1, 1) > Prefixed notation, also known as functional notation (think to a function)
1 + 1 > Infixed notation, cause the operator is between the two operands (think to in)
1 1 + > Postfixed notation (Case of stack calculation... i++?)

Prefixed notation also possible as:
1.+( 1 ) > As we sew in cpp, we can have Class and Instance of it, now looks like a call method > An instance(1).functionMember(+)( sending 1 in param)
```

*Integer.class.hpp -> Simulates a natural int behavior with a class*
```cpp
#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

class Integer {

public:

    Integer( int const n ); 		// My class is built from a const int n
    ~Integer ( void );

    int     getValue( void ) const; // An accessor that get my int attribute value

    // Here we have two overloadings operator

    //a = b = c = d is allowed by the fact that I return a reference (not a pointer)
    Integer & operator=( Integer const & rhs); //Affectation operator (here it looks like there is only one paramater, but actually has two: this and rhs), by affecation, I mean modification so it won't be const

    //Here I return a result copy
    Integer  operator+( Integer const & rhs) const; //Addition operator, by addition, I mean two operands but I won't modify any of them, so I put it in const

private:

    int _n;

};

std::ostream & operator<<( std::ostream & o, Integer const & rhs );

#endif
```

> Operator Keyword allows to a simple class member function declaration, to have an overloading operator. Then I just need to precise what operator I want to between the keyword operator and the param parenthese (we can have unary, binary or ternary ones...). [=] operator is binary, at the left -in what- I want to assign, at the right -what- I want to assign. Same thing for [+], at the left one operand, at the right, another... Pre incr or post incr is unary.

*Integer.class.cpp*
```cpp
#include <iostream>
#include "Integer.class.hpp"

Integer::Integer( int const n ) : _n( n )
{
    std::cout << "Constructor called with value" << n << std::endl;
    return;
}

Integer::~Integer( void )
{
    std::cout << "Destructor called with value " << this->_n << std::endl;
    return;
}

int    Integer::getValue( void ) const
{
    return this->_n; //Returns a val copy
}

Integer & Integer::operator=( Integer const & rhs) //One visible paramater, but actually has two : this and rhs
{
    std::cout << "Assignation operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl; //I can reach rhs value thanks to my accessor

    this->_n = rhs.getValue();

    return *this; //To return a ref on it, I just dereference my pointer
}

Integer   Integer::operator+( Integer const & rhs) const
{
    std::cout << "Addition operator called with " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;

    return Integer( this->_n + rhs.getValue() ); //Result will be used to create a new instance of integer, I return a copy (we loose some memory but...)
}

std::ostream & operator<<( std::ostream & o, Integer const & rhs )
{
    //My output stream is o
    o << rhs.getValue();
    return o;
}

int     main()
{
    Integer x( 30 );
    Integer y( 10 );
    Integer z( 0 );

    std::cout << "Value of x : " << x << std::endl; // Outputs 30
    std::cout << "Value of y : " << y << std::endl; // Outputs 10

    y = Integer ( 12 ); // Calling my overloading assignation operator, calling destructor then constructor again for update

    std::cout << "Value of y : " << y << std::endl; // Outputs 12
    std::cout << "Value of z : " << z << std::endl; // Outputs 0

    z = x + y;  // Calling my overloading assignation operator (in which we have a new instance creation) on the result of x + y : outputs 42

    std::cout << "Value of z : " << z << std::endl; // Outputs 42

    //Destruction of our three parameters
    return (0);
}

```
> All this appears useful to write arithmetic classes. Rules are important to make sense:
- Operator overloading must be natural
- It must have a relation with the natural semantic of its operator (wanting to make an addition of two matrix instances, I won't use *...)
- Don't do overload operator... > Even if it apears like a good idea, it's probably not. (?)

---

## To understand the [canonical form](https://people.canonical.com/~msawicz/guides/c++/cppguide.html) notion.

> Canonical form (coplien) is like a norm to ensure an uniform treatment.

We talk about canonical class, when it has at least:
 - A default contructor
 - A destructor
 - A copy constructor (a copy of the class we're declaring by a new instance)
 - An assignation operator (similar to copy constructor, but doesn't generate a new instance, only update the current one). 
 
 > All this constitute our new norme. *We could also have member function that serialize our class...*
.
*Sample.class.hpp*
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    // Constructors assembly
    Sample( void );                             // Default constructor, canonical requirement
    Sample ( int const n );
    Sample ( Sample const & src );              // Copy constructor: takes in parameter a class instance we're currently declaring/defining, canonical requirement
    // Destructor
    ~Sample ( void );                           // Canonical requirement

    Sample & operator=( Sample const & rhs);   // Equal operator, to make an assignment of this class, canonical requirement (let's see virtual later)

    int     getFoo( void ) const;

private:
    
    int _foo;

};

std::ostrean & operator<<( std::ostream & o, Sample const & rhs );

#endif
```

## Some definitions:

> __[Default Constructor](https://www.geeksforgeeks.org/constructors-c/):__ *A constructor is a member function of a class which initializes objects of a class. In C++, Constructor is automatically called when object(instance of class) create. It is special member function of the class.*

> __[Copy Constructor](https://en.cppreference.com/w/cpp/language/copy_constructor):__ *A copy constructor is a member function that initializes an object using another object of the same class.* 

## Some knowledge:

[Construction and Destruction, Copy and Affectation](https://www.iro.umontreal.ca/~pift1166/cours/ift1166/communs/Cours/2P/C14-1166.pdf). \
[Copy and Affectation](http://www-igm.univ-mlv.fr/~dr/CPP/TransparantsC++6.pdf).

---

## Go on our [exercises](https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/):

*By number we understand not so much a multitude of unities, as the abstracted ratio of any quantity to another quantity of the same kind, which we take for unity, Newton – Universal Arithmetic - 1728*

### To have basics:

*There are various types of number representation techniques for digital number representation, for example: Binary number system, octal number system, decimal number system, and hexadecimal number system etc. But Binary number system is most relevant and popular for representing numbers in digital computer system.*

![https://www.tutorialspoint.com/assets/questions/media/18154/36_1.jpg](https://www.tutorialspoint.com/assets/questions/media/18154/36_1.jpg)

### What is [fixed point representation](https://www.tutorialspoint.com/fixed-point-and-floating-point-number-representations) of integers?
*In fixed point notation, there are a fixed number of digits after the decimal point, whereas floating point number allows for a varying number of digits after the decimal point. Fixed-Point Representation − This representation has __fixed number of bits for integer part and for fractional part__.*

> "The key to represent fractional numbers, like 26.5 above, is the concept of binary point. A binary point is like the decimal point in a decimal system. It acts as a divider between the integer and the fractional part of a number."

---

## With fixed point notation, a number is expressed using a certain number of bits and the binary point is assumed to be permanently fixed at a certain position. For example, let us say that fixed point numbers use eight bits and that the binary point is fixed between the middle two bits, like in the table.

> The fixed point numbers provide a valuable balance of performance, accuracy, range and precision, which is why these numbers are widely used in graphics, sound, or science programs, to name a few.

[Fixed Point Number Representation Berkeley](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html). \
[Float](https://fr.wikipedia.org/wiki/Virgule_flottante#:~:text=6.3%20Liens%20externes-,Comparaison%20avec%20la%20virgule%20fixe,l'exposant%20e%20est%20fix%C3%A9.). \
[Binary Reminder](http://villemin.gerard.free.fr/Wwwgvmm/Numerati/ConBin.htm). \
[Binary Hexa Decimal Converter](https://sebastienguillon.com/test/javascript/convertisseur.html).

### Reminder:

__A float (4 bytes) or double (8 bytes) has three components__:

    - A sign bit, telling whether the number is positive of negative
    - An exponent giving its order of magnitude
    - A mantissa specifying the actuals digits of the number

```
 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

s = sign bit, e = exponent, m = mantissa
```

```
0      0x00000000
1.0    0x3f800000
0.5    0x3f000000
3      0x40400000
+inf   0x7f800000
-inf   0xff800000
+NaN   0x7fc00000 or 0x7ff00000
```

---

```
/* A careful reader should now realize the bit pattern of 53 and 26.5 is exactly the same.
** The only difference, is the position of binary point. In the case of 53 in 10 base, there is "no" binary point. 
** Alternatively, we can say the binary point is located at the far right, at position 0. 
** (Think in decimal, 53 and 53.0 represents the same number.) */

/* Now, we discuss shifting an integer to the right by 1 bit position is equivalent to dividing the number by 2. 
** In the case of integer, since we don't have a fractional part, we simply cannot represent digit to the right 
** of a binary point, making this shifting process an integer division. However, it is simply a limitation of 
**integer representations of binary number. */

/* In general, mathematically, given a fixed binary point position, shifting the bit pattern 
** of a number to the right by 1 bit always divide the number by 2. Similarly, shifting a number 
** to the left by 1 bit multiplies the number by 2. */

/* To define a fixed point type conceptually, all we need are two parameters:
** width of the number representation, and
** binary point position within the number */

L'avantage de la représentation en virgule flottante par rapport à la virgule fixe est que la virgule flottante est capable, à nombre de bits égal, de gérer un intervalle de nombres réels plus important.
Par exemple, une représentation décimale en virgule fixe ayant 7 chiffres décimaux dont 2 chiffres après la virgule peut représenter les nombres 12345.67, 123.45, 1.23, etc.
La représentation décimale en virgule flottante (comme le format IEEE 754 decimal32) peut quant à elle, avec sept chiffres décimaux,
représenter en plus 1.234567, 123456.7 = 1.234567 × 105, 0.00001234567 = 1.234567 × 10−5, 1234567000000000 = 1.234567 × 1015, etc.

Inconvénient
En revanche, le format à virgule flottante occupe un peu plus de place, car il est nécessaire d'encoder la position de la virgule (représentée par l'exposant). Pour le même espace disponible,
la virgule flottante offre donc une étendue de nombres plus grande au détriment de la précision.


Representation
There are several ways to represent a fixed-point value. The best representation will depend quite heavily on your particular use case. So do your research.
The simplest way (as far as I know) is to pick a scaling factor (powers of two are the most convenient) and then store the values you want to represent, scaled by that factor. So to convert a floating point number to this fixed-point representation you just multiply the number by your scaling factor and round to an integer. The resulting value is your fixed-point representation of the given value:
fixed_point_value = round(floating_point_value * scaling_factor)

To convert from your integer fixed-point representation back to floating point you cast your fixed-point value to a float, and then divide by your scaling factor:
floating_point_value = ((float)fixed_point_value)/scaling_factor
```