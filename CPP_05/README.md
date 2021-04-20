# C++
## Module 05

Day 05 [subject](https://cdn.intra.42.fr/pdf/pdf/20752/fr.subject.pdf). Here is a first approah of [nested notion](https://docs.microsoft.com/fr-fr/dotnet/csharp/programming-guide/classes-and-structs/nested-types).

*PERSONAL NOTES/RULES:*
- Think about using a reference rather than a copy
- Have a code, as const as I can

```cpp

// I make a Cat class in which I put a nested class named Leg

class Cat
[
    public:
    class Leg        // This class is owned by Cat
    {
        //[...]
    }; // Important, as a class end's declaration
];

// I make a Dog class in which I put a nested class named Leg

class Dog
{
    public:
    class Leg      // This class is owned by Dog
    {
        //[...]
    };
}

int     main()
{
    Cat         somecat;        // I can instantiate a Cat
    Cat::Leg    somecatsleg;    // I also can istantiate a Cat::Leg

    return(0);
}

```

> What we sew above is __nested classes__, it means another class, declared inside a class declaration block.

Here is our new purpose, a new way to do error management, [exceptions](https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1903837-gerez-des-erreurs-avec-les-exceptions).

> Exceptions is a way to __move up a message through the call stack__. Not like in C, when we had to return values as (-1), ... keeping us from the possibility to use negative values in other functions, or restricting us for the possibily to act something as we would like to. Now we'll see how to do and manage __exceptions__.


## To understand [exception handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm#:~:text=C%2B%2B%20exception%20handling%20is%20built,want%20to%20handle%20the%20problem.).

```cpp

#include <stdexcept>

void    test1()
{
    try                         // A try block, gonna try to do something that can return an exception
    {
		//Do some stuff here
		if (/* there's an error */)
        {
            throw std::exception(); // launching an exception if the program met an error
            // the Throw instruction moves up the blocks until it finds a Catch block (that we can see below)
        }
        else
        {
            //Do some stuff here, if everything went good
        }
    }
    catch (std::exception e) // In error case, Throw reach this block, e is a norm
    {
        //Handle the error here
        // For example, calling e.what that calls a method in the <stdexcept>
		// to return a message describing what error occured
    }
}

void    test2()
{
	// There is no try/catch in here, we're calling it in test3 below
    
	//Do some stuff here
    if (/* there's an error */)
    {
        throw std::exception(); // There is an exception to catch, but actually no Catch block
    }
     else
    {
        //Do some stuff here, if everything went good
    }
}

void    test3()
{
    try
    {
        test2(); // Calling test2 that contains Throw
		// if test2() finds an exception, it rides up until test3() call and will look up 
		// for a try block that can handle my exception

		// To help, I can think of the block cut I would have made in C (handling and checking errors with returns...)
    }
    catch (std::exception &e) // I can catch an exception by reference, e is a norm
	// It has to be seen as if Catch was a function that takes an exception in param
	// that will be initialized by the exception we catch
    {
        //Handle error
    }
}

// I'll define an exception
void    test4()
{
    class PEBKACException : public std::exception // Inheriting publically from std::exception
	// PEBKACE makes now part of std::exception that I can manipulate
    {
        public:
            virtual const char* what() const throw() // specifier Throw, at the end of a function definition
			// It means this Throw instruction can throw something or not
            {
                return ("Problem exists between keyboard and chair"); // Defining the error message I want to return
            }
    };

    try
    {
        test3();
    }
    catch (PEBKACException &e) //Here I got a specific catch
    {
        //Handle the fact that user is an idiot
    }
    catch (std::exception &e) //Here I got a generic catch
    {
        //Handle other exceptions that are like std::exception
    }
}

```

> __Try__ and __Catch__ can be seen as a replacement of our old return(-1), return(-2) and if (-2), if (-1)...
As the name seems to mean, __an exception must stay an exception__. 
If we have a function that seems doomed to fail half the time, we won't throw an exception.
Exceptions take a lot of resources when using Throw (more than returning a simple value). In case of a reccurent error, I may use a return value that indicate it (like boolean -> OK or NOT OK...).

But __in the case of unusual behavior__, which should'nt appear in our program running, __we can use exceptions__.
Think about the system function New that returns exceptions in case of no left space. Or a Open failure...



### Remember, a throw must always be in a try bloc which itself must be followed by a catch bloc.

> __Exceptions are caught by constant reference (hence the presence of the &) and not by value__, in order to reduce a copy and preserve the polymorphism of the received object. Remember the ingredients of polymorphism: a reference or a pointer is needed. As the thrown object could have virtual functions, on the catch via a reference, so that the two ingredients come together.

### Execution resumes after the catch block and not where the throw is.

Handling exceptions schema

![schema](http://www.infobrother.com/img/others/Exception-Handling.png)

List of standard exceptions

![standard](https://www.tutorialspoint.com/cplusplus/images/cpp_exceptions.jpg)

```Helpful metaphor:

[Try] is the fish, he's swimming as he should be (as our program would be running)
It was unexpected but the fisherman [throws] his fishing rod (as an error would occure while execution)
The fish is catched```
