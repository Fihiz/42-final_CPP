# C++
## Module 04

*PERSONAL NOTES/RULES:*
- Think about using a reference rather than a copy
- Have a code, as const as I can

Day 04 [subject](https://cdn.intra.42.fr/pdf/pdf/20749/en.subject.pdf).
Here is an approach of [polymorphism](https://catonmat.net/cpp-polymorphism).

> Previously, we sew that class inheritance means we are part of the class we inherit.

```cpp

// .hpp
class Character
{	
	public:
   		void sayHello( std:: string const &target); // Character own way to say hello
};

class Warrior : public Character // Means a warrior is a character
{	
	/* We can redefine in a daughter class, the behavior of a Mother's class function.
	** This is overriding. */
	public:
   		void sayHello( std:: string const &target); // Warrior own way to say hello
};

class Cat
{
	// ...
};

// .cpp

void	Character::sayHello( std::string const &target )
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello( std::string const &target )
{
	std::cout << "F*** off " << target << " I don't like you !" << std::endl; // Over ride sayHello's mother function to have the Warrior's style
}

int		main()
{
	// This is OK, obviously, Warrior IS a Warrior
	Warrior* a = new Warrior();

	// This is also OK because Warrior IS a Character, so can be manipulate by "the reverse" side
	Character* b = new Warrior();

	// This would NOT be ok because Character IS NOT a Warrior (think to geneaology...)
	// (They are related in a way, the reverse is untrue)
	// Warrior* c = new Character ();

	// This would NOT be ok because Cat IS NOT a Character
	// (They are not even related)
	// Character* d = new Cat();

	a->sayHello("Students"); // Will display the overriden Warrior hello, he's a warrior from daughter Warrior class
	b->sayHello("Students"); // Will display the Character hello, he's a warrior but directly issued from mother Character class
}

```

> What if I want my Warrior be a real warrior, even if he's a character, but taking his own behavior ? 
__Virtual__ will be the key-word answer, meaning the linkage is now __dynamic__ and not static. 
In the case above, our linkage is static, meaning the resolution of our functions is static, compiling, I already know which is the function I'll call.
The only way for the compilator to know which behavior type to adopt for my class object is to know his type. As I typed my object as a character, the compilator
will adopt the character's behavior -> Meaning it's static, at the compilation, it won't change after. But as we asked before, if we want to say to the compilator
that my character is currently a warrior ? Maybe sometimes it will have to point on a warrior, or a mage, or a bear, or whatever. I can do a [Character*] that can point
on any characters I would have (a witcher, a king...) __depending on the user's choice__ (think to a gaming launcher, everything is set up to work with a character, 
you can dynamically choose which sub_type will have your character!). Thanks to virtual, my functions call resolution will be dynamic, meaning done while execution.

```cpp

// Virtual case

// .hpp
class Character
{	
	public:
   		virtual void sayHello( std:: string const &target); // Character own way to say hello
};

class Warrior : public Character // Means a warrior is a character
{	
	/* We can redefine in a daughter class, the behavior of a Mother's class function.
	** This is overriding. */
	public:
   		virtual void sayHello( std:: string const &target); // Warrior own way to say hello
};

class Cat
{
	// ...
};

// .cpp

void	Character::sayHello( std::string const &target )
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello( std::string const &target )
{
	std::cout << "F*** off " << target << " I don't like you !" << std::endl; // Over ride sayHello's mother function to have the Warrior's style
}

int		main()
{
	// This is OK, obviously, Warrior IS a Warrior
	Warrior* a = new Warrior();

	// This is also OK because Warrior IS a Character, so can be manipulate by "the reverse" side
	Character* b = new Warrior();

	a->sayHello("Students"); // Will display the overriden Warrior hello, he's a warrior from daughter Warrior class
	b->sayHello("Students"); // Will also display the Warrior hello
	/* Now the compilator will say "Ok, this is member method with a dynamic link, so I got to know at this moment which is the function I really need to call ?"
	** By this way, the compilator will go down in the inheritance tree until he find the real object type to call the good sayHello method. */
}

```

> We call a virtual member function, __a method__ (dynamic resolution of the scope). All we sew above is called __sub_typing polymorphism__.
Now let's see a __pure method__ definition (method... = 0). What does it mean ? Two things, there is no definition of it, meaning non implementation.
In this way, we can't instantiate this class, she doesn't have any behavior, she's an __abstact class__.
In other words, an abstract class means that __certain behaviors are defined, and some others are not AND the abstract class itself cannot be instantiated__.
To instantiate a derived object that inherits from ACharacter, as the warrior, the warrior will have to define the behaviors that are defined as abstract in the parent class.

```cpp

// .hpp
class ACharacter // By convention, we add "A" prefix to notificate that this class is abstract
{	
	private:
		std::string		name; // Attribute is possible by the fact that I have a concrete method, but only derived object can have it
		// Remember that an abstract class can't be instantiated
	public:
		virtual void 	attack( std::string const &target ) = 0; // Writing [method = 0], it defines her as a PURE method, so abstract
   		void 			sayHello( std:: string const &target); // Concrete method, so I also could have attributes
};

/* So we got a pure attack method above, in our abstract ACharacter class. That amounts to saying the method does not exist.
** In other words, my ACharacter class, even if she's saying that in case of inheritance, the derived object would have
** the attack behavior because she defines that a character should can know how attack whith the method attack, 
** it won't be able to attack by itself -> a ACharacter in itself has no attack. 
** It's just a way to factor certain behavior as the ability to sayHello to someone, but the daughter's classes will must have
** an attack method even if the mother doesn't have a defined one. Kind abstract for now... */

class Warrior : public ACharacter // Means a warrior is a ACharacter
{	
	public:
   		virtual void 	attack( std::string const &target ); 
		   // Means the warrior, which is a child class of ACharacter, has to define the pure methods of his mother or we either won't be able to instantiate a Warrior
		// Think to a prototype at the "zero status" and has to be described later while using ?
};

// .cpp

void 			ACharacter::sayHello( std::string const &target )
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void			Warrior::attack( std::string const &target )
{
	std::cout << "*attacks " << target << " with a sword*" << std::endl;
}

int				main()
{
	ACharacter*		a = new Warrior();

	// This would NOT be ok because ACharacter is abstract
	// ACharacter* b = new ACharacter(); // Compilator would say "I can't, the behavior is abstract !"

	a->sayHello("Students");
	a->attack("roger");
}
```

> I could do "worst", by creating an abstract mother class that only have pure methods ?
This class would only have abstract behaviors, we call that : __interface__. The main difference
between this class and the previous one that had a concrete and abstract method (so could have attributes),
is that I can't declare any attributes in this one below. This a way to think an interface as a contract for
the class heirs. __This is an interface to use derived objetcs, only a way to describre a behavior.__

```cpp
class 	ICoffeMaker // By convention, I notice this abstract class with an I
{
	// The only thing I want to say with this interface is that a CoffeeMaker may have a way to fill its tank
	// and a way to make coffee and so return a pointer on it (I use ICoffee* )
	public:
		virtual	void fillWaterTank( IWaterSource *src ) = 0;
		virtual ICoffee* makeCoffee( std::string const &type ) = 0;
	// It doesn't factor anything but only describe that any derived object of the ICoffeeMaker will have these behaviors
};

int		main()
{
	... ;
}
```

> Interface class has to be seen as a contract with the developper who is responsible for coding concrete classes.
It's like we were saying "Ok man, do your concrete classes as you wish, we don't care BUT I want them to work this way and this way".
It appears very useful when we have to developp with others, to describe an interface of objects they will have to make concrete. 
Then they can do as they wish but they already know how we'll use them thanks to the interface.
Another advantage would be to manipulate a tab of concrete objects, even if they don't have the same type, from a container.

## To understand the [virtual destructor](https://www.geeksforgeeks.org/virtual-destructor/).

> To sum up, always make base classes' destructors virtual when they're meant to be manipulated polymorphically.

## To understand the [shallow copy] and [deep copy](https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/).

> When designing classes that handle dynamically allocated memory, memberwise (shallow) copying can get us in a lot of trouble! This is because shallow copies of a pointer just copy the address of the pointer -- it does not allocate any memory or copy the contents being pointed to!

![shallowdeep](https://webdevdesigner.com/images/content/184710/0ffcda28f0afee9f7070f60cf2b28a8b.jpg)

## To understand the [NULL] and [nullptr](https://www.geeksforgeeks.org/understanding-nullptr-c/).

> __nullptr__ is a subtle example of the Return Type Resolver idiom that automatically deduces a null pointer of the correct type depending upon the type of the instance it is assigning to.