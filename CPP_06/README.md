# C++
## Module 06

Day 06 [subject](https://cdn.intra.42.fr/pdf/pdf/20756/en.subject.pdf).

### C Type conversion reminder

```C

int		maint( void )
{
	int 	a = 42;				// Reference value

	double	b = a;				// Implicit conversion cast, compilator will adapt the type
	
	/* Remember :  Double is a float type, with a double prescision (64bits), so bigger than a 32bits (int) type.
	** It means, every int type could fit in a 64bits type. This is why the initialization above is allowed. */
	
	double	c = (double) a;		// Explicit conversion cast

	double 	d = a;				// Implicit promotion -> Ok
	int		e = d;				// Implicit demotion -> Hazardous !
	int		f = (int) d;		// Explicit demotion -> Ok, you're in charge

	return (0);
}

```

> For an int type, all the bits follow each other. But for the float and the double, bits coding are different (Sign, exponent, mantissa...).
It means that if we made a copy of an int bits into a float bits, we wouldn't have the same pattern at all. But even if the coding is different, result values are the same.

> __There is a hierarchy in types__. An int type is smaller than a float type, it amounts to saying that int type has less precision.
As long as I try to fit an integer value into a float value, there is no problem. What if I do the contrary ? This is where we talk about hazardous behaviors, has a precision lost.
Think of the case where one uses a calculation in a loop and that the result uses the preceding calculation, everything is distorted, error marge would be giant.

> In our compilator, we have a number of checks that will be made. __Demotion__ is a good way to signalize to our compilator that we're ok to loose precision for a conversion (explicit cast).
There is a flag that forbid the presicion loss (int	e = d; this line wouldn't compile). Let's think to the contrary concept, __Promotion__.

> We have just seen that the C casts would allow us to convert types to other types, and for that to have a rearrangement of the bits to be able to correspond to the new type.

---

Now let's talk about __identitary conversion__, meaning that after it, the value keep the same bit pattern, in the same order. __There was no conversion during the cast__.
We call that __reinterpretation__.

```C

int 	main( void )
{
	float	a = 420.042f;		// Reference value

	void	*b = &a;			// Implicit reinterpretation cast
	void	*c = (void *) &a;	// Explicit reinterpretation cast

	void	*d = &a;			// Implitcit promotion -> OK !
	int		*e = d;				// Implicit demotion -> Hazardous !
	int		*f = (int *)d;		// Explicit demotion -> Ok, I obey !

	return (0);
}

 ```

> We had previously spoken of a hierarchy between types (int in a float but float in an int...).
In case of address type, we'll find the same idea. In particular on the __(void*)__ type which
__can contain an address of any type__. We can say that void* is more general, so preciser, 
than a float* for example, that makes us say that we find the same __hierarchy idea__.

> __Downcast and Upcast__ are particular case of reinterpretation in inheritance case.

> __Static cast__ allows us to a do a lot of simple conversions, and navigate into inheritance tree. Let's think to __Dynamic cast__ too.

```c

int		main( void )
{
	int a = 42;		// Reference value

	double c = a;	// Implicit promotion -> Ok
	int c = b;		// Implicit demotion -> Hell no !
	int d = static_cast<int>(b); // Explicit demotion -> Ok, I obey

	static_cast<int>(b) means I want to convert that double b into an int
	return (0);
}

```

```c

int		main( void )
{
	int a = 42;		// Reference value

	double c = a;	// Implicit promotion -> Ok
	int c = b;		// Implicit demotion -> Hell no !
	int d = static_cast<int>(b); // Explicit demotion -> Ok, I obey

	static_cast<int>(b) means I want to convert that double b into an int
	return (0);
}

```

## Dynamic_cast vs Static_cast

*"New programmers are sometimes confused about when to use static_cast vs dynamic_cast.*
*The answer is quite simple: use static_cast unless you’re downcasting, in which case dynamic_cast is usually a better choice.*
*However, you should also consider avoiding casting altogether and just using virtual functions."*

### Downcasting vs virtual functions

*"There are some developers who believe dynamic_cast is evil and indicative of a bad class design.*
*Instead, these programmers say you should use virtual functions.*
*In general, using a virtual function should be preferred over downcasting."*

*"However, there are times when downcasting is the better choice:*
*When you can not modify the base class to add a virtual function (e.g. because the base class is part of the standard library)*
*When you need access to something that is derived-class specific (e.g. an access function that only exists in the derived class)*
*When adding a virtual function to your base class doesn’t make sense (e.g. there is no appropriate value for the base class to return). Using a pure virtual function may be an option here if you don’t need to instantiate the base class."*

---

# Serialization and Deserialization

*"When we talk about serialization, we mean transforming the local data before sending, into a format that the receiver can interpret in order to retrieve the initial data."*  
The basic mechanisms are to flatten object (s) into a one-dimensional stream of bits, and to turn that stream of bits back into the original object (s).  
*"It's all about taking something complicated and turning it into a flat sequence of 1s and 0s, then taking that sequence of 1s and 0s (possibly at another place, possibly at another time) and reconstructing the original complicated “ something. ”"* 

> In computing, serialization is the encoding of information in the form of a series of smaller information for, for example, its backup (persistence) or its transport on the network (proxy, RPC…). The reciprocal activity of decoding this sequence to create a true copy of the original information is called deserialization.

[Source 1](https://bousk.developpez.com/cours/serialisation-bases/).  
[Source 2](https://isocpp.org/wiki/faq/serialization).