# C++
## Module 02

Day 03 [subject](https://cdn.intra.42.fr/pdf/pdf/20745/en.subject.pdf).

## To understand the [inheritance](https://www.geeksforgeeks.org/namespace-in-c/#:~:text=Namespace%20is%20a%20feature%20added,declared%20in%20the%20named%20scope.) notion.

> __Inheritance__ is one of the fundamental OOP principles. According to it, __class can use variables and methods of another class as its own__.


__Inheritance__: *For any bird, there are a set of predefined properties which are common for all the birds and there are a set of properties which are specific for a particular bird. Therefore, intuitively, we can say that all the birds inherit the common features like wings, legs, eyes, etc. Therefore, in the object-oriented way of representing the birds, we first declare a bird class with a set of properties which are common to all the birds. By doing this, we can avoid declaring these common properties in every bird which we create. Instead, we can simply inherit the bird class in all the birds which we create.*

---

```cpp

class Cat
{
    private:
        int     _numberOfLegs;

    public:
        Cat();
        Cat(Cat const &);
        Cat& operator=(Cat const &);
        ~Cat();

        void        run(int distance);
        void        scornSomeone(std::string const &targert);
}

// I could also have a pony, with apparently same attributes...
class Pony
{
    private:
        int     _numberOfLegs;

    public:
        Pony();
        Pony(Cat const &);
        Pony& operator=(Pony const &);
        ~Pony();

        void        run(int distance);
        void        doMagic(std::string const &targert);
}

```

> Thanks to inheritance, I could say that Pony and Cat are both animals, so have two legs and can run.
What if I do an animal class that allows to its subclasses to inherit its behavior, and so do multiple animals ? The following is an example of how the concept of inheritance is implemented.

```cpp

class   Animal
{
     private:
        int     _numberOfLegs;

    public:
        Animal();
        Animal(Cat const &);
        Animal& operator=(Animal const &);
        ~Cat();

        void        run(int distance);
        void        call( void );
        void        eat( std::string const &what); //Takes the ref and not a copy?
}

class Cat : public Animal //Here my cat class inherits of my animal class (let's see public and private later...)
{
    private:
        int     _numberOfLegs;

    public:
        Cat();
        Cat(Cat const &);
        Cat& operator=(Cat const &);
        ~Cat();

        void        scornSomeone(std::string const &targert); //Has an extra behavior, in addition to its animal behavior
}
//It means my cat is an animal (in all points) but does not mean my cat is only an animal

class Pony : class Animal
{
    private:
        int     _numberOfLegs;

    public:
        Pony();
        Pony(Cat const &);
        Pony& operator=(Pony const &);
        ~Pony();

        void        doMagic(std::string const &targert); //His plus one own behavior
        void        run(int distance) //Already exists in animal but I can rewrite it in Pony(they may have a different way of running?)
}
//Also inherits of my animal class > it's an animal
```

> By instanciating a cat, I have to describe an animal class and so my cat has an "animal part". But remember that in addition to its animal part, can can have specifications. (Pony wouldn't have a moustache by the way...)

## To understand the [protected](https://docs.microsoft.com/fr-fr/cpp/cpp/protected-cpp?view=msvc-160#:~:text=Le%20protected%20mot%20cl%C3%A9%20sp%C3%A9cifie,de%20la%20d%C3%A9finition%20de%20classe.&text=Les%20classes%20d%C3%A9riv%C3%A9es%20ayant%20un,a%20initialement%20d%C3%A9clar%C3%A9%20ces%20membres.) encapsulation notion.

```cpp
{
    class Quadruped                 //Can access to name attribute, run() method and legs attribute

    private:
        std::string     name;       //Only accessible from the Quadruped object/instance
    
    protected:
        Leg             legs[4];    //Accessible from a Quadruped or derived object/instance

    public:
        void            run();      //Accessible from wherever(from main, from quadruped...)
};

    class   Dog : public Quadruped //Can access to run() method and legs attribute, not the name
    {
        ;
    };

    int     main()                  //Can only access run()

```

> To sum, [protected] means that I own some methods/attributes that my derived classes can legitimately use without permissions... -> Need to find the use cases. [Private], [protected]... All this constitute the __encapsulation inheritance levels__. -> Let's find examples as well.
Until there, we sew the lonely/simple inherit case. But there is also multiple inherit case... Need to go on.

> I could have an animal class and a quadruped class. Let's tell that a quadruped is not necessarly an animal. Then the dog could inherits from the quadruped and animal classes and so have the both behaviors... But, what if a class defines a behavior that is already created in the other one ? How do we specify which content we want ? We call that [diamond inheritance](https://www.geeksforgeeks.org/multiple-inheritance-in-c/).

> Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
The constructors of inherited classes are called in the same order in which they are inherited.

![Diamond](https://media.geeksforgeeks.org/wp-content/uploads/20190312133527/Need-of-Containership-in-C.jpg)

> [Virtual](https://en.wikipedia.org/wiki/Virtual_class) inheritance solves the classic “Diamond Problem”. It ensures that the child class gets only a single instance of the common base class. It is used when inheritance represents restriction of a set rather than composition of parts. In C++, a base class intended to be common throughout the hierarchy is denoted as virtual with the virtual keyword.

> When we use ‘virtual’ keyword, the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor.

```
You want: (Achievable with virtual inheritance)

  A  
 / \  
B   C  
 \ /  
  D 
And not: (What happens without virtual inheritance)

A   A  
|   |
B   C  
 \ /  
  D
```