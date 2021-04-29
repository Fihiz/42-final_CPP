# C++
## Module 07

Day 07 [subject](https://cdn.intra.42.fr/pdf/pdf/20753/en.subject.pdf).

*PERSONAL NOTES/RULES:*
- Think about using a reference rather than a copy
- Have a code, as const as I can

### To throw light on the notion of [templates](https://www.cplusplus.com/doc/oldtutorial/templates/), let's say that is a way to define code in which we'll introduce type variables.
> These templates will define functions, classes, or structures templates. This __code pattern__/__hole model__, will next be used by the compilator to instantiate the holes, where the type variables are, with types for which we're really interested by and use them at the right place.

```cpp

#include <iostream>

int		max( int x, int y)
{
	return ( x >= y ? x : y );
}

/* We would like to use this max function on every type, on float, on char... whatever.
** That is why instead of use an int as a return, I could do : */

// We agree to say that C would't accept this syntax, this is the C++ template power, I have to notice it to my compilator like below

template< typename T > // Can be seen as a declaration before to be able to use it
T	max(T x, T y) // T for type: the idea is to compare two homogenous datas (two floats, two ints, two chars...) so I systematically receive two T params
{
	return (x >= y ? x : y);
}

```
> Let's think about operators overload (=... >...)... What if my type T was a class instance ?
So that would be interisting to not take these params by copy, but taking their references.
If the class, is a voluminous one, we would prefer to not have to copy it, to preserve our memory resources.

```cpp
template< typename T >
T const & max(T &x, T &y) // Since our max function template will not modify the instance received as a parameter at any time, that instance can be const
{
	return (x >= y ? x : y); // If I don't change anything, my return is indeed passed by copy, but we receive a [const &] now... let's change our return value then
}

```

### How I use my template now ?
Let's see a template as a model, a code pattern. It's a mold but not the cake.
What we intend from the compilator, is that it takes this mold, and cook our cake.
I can do that demanding to the compilator to make an instanciation of this template.
I can do either implicit or explicit instanciation of it, and compilator will generate the code for me.

```cpp
template< typename T >									// Template definition: not usable in that way, it must be instantiated !
T	const 	&max(T &x, T &y)
{
	return (x >= y ? x : y);
}

int			foo( int x )
{
	std::cout << "Long computing time" << std::endl;
	return x;
}

int			main( void )
{
	int		a = 21;
	int		b = 42;

	std::cout << "Max of" << a << "and " << b << "is ";
	std::cout << max<int>( a, b ) << std::endl; 		// Explicit instanciation, between chevrons the type on which we want to instantiate our template (remember the cast syntax)
	std::cout << "Max of" << a << "and " << b << "is ";
	std::cout << max( a, b ) << std::endl; 				// Implicit instanciation, possible cause a and b are already int

	int		c = -1.7f;
	int		d = 4.2f;

	std::cout << "Max of" << c << "and " << d << "is ";
	std::cout << max<float>( c, d ) << std::endl; 		// Explicit instanciation
	std::cout << "Max of" << c << "and " << d << "is ";
	std::cout << max( c, d ) << std::endl; 				// Implicit instanciation

	char	e = 'a';
	char    f = 'z';

	std::cout << "Max of" << e << "and " << f << "is ";
	std::cout << max<char>( e, f ) << std::endl; 		// Explicit instanciation
	std::cout << "Max of" << e << "and " << f << "is ";
	std::cout << max( e, f ) << std::endl; 				// Implicit instanciation

	// No problem here...
	int		ret = max<int>( foo(a), foo(b) );			// Explicit instanciation, compilator will make the code for me
	std::cout << "Max of" << e << "and " << f << "is ";
	std::cout << ret << std::endl; 		

	return (0);
}

```

### What about data structures ?
We have just seen that we could make template functions. We can do the same with structures and classes.

```cpp

#include <iostream>

template< typename T >		// We'll see that later, but it's possible to pass multiple params, syntax still be the same template< typename T, typename U >
class List
{
	private:
		T			*_content; // We can remove the star if we're on a simple list... (?)
		List<T>		*_next;

	public:
		List<T>( T const &content )		// Constructor, receiving a T content, it will become the effective type we need in the right time
		{
			// Etc...
		}

		List<T>( List<T> const &list )
		{
			// Etc...
		}

		~List<T>( void )
		{
			// Etc...
		}

		// Etc...
}

int		main( void )
{
	List< int >				a(42);		// Here I got an instance of my List template, instantiatied for integer type
	List< float >			a(3.14f);
	List< List< int> >		c( a );		// Here I pass a list of an int list (bidimensional)

}

```

```STL means Standard Template Library```

``` .tpp extension convention for template file```

### Default type

```cpp

#include <iostream>

template< typename T = float > // Hey template, if I don't say you anything, please consider it's a float (implicit, explicit ?)
class Vertex
{
	private:
		T const _x;			// 3D coordinates
		T const _y;
		T const _z;
		Vertex( void );		// Forbid default constructor

	public:
		Vertex( T const &x, T const &y, T const &z) : _x( x ), _y( y ), _z( z ) { }
		~Vertex ( void ) { } // No dynamic allocation so my destructor does nothing

		T const &	getX( void ) const { return this_x; }
		// ... same
}

template< typename T> // Here we got a template of a stream overaload, precising a Type T to pass it in my stream
std::ostream & operator<<( std::ostream &o, Vertex< T > const & v ) {
	std::cout.precision( 1 );
	o << setiosflags( std::ios::fixed );
	o << "Vertex( ";
	o << v.getX() << ", ";
	// ... same
	return (o);
}

int		main( void )
{
	Vertex< int >	v1( 12, 23, 34 );
	Vertex<>	v1( 12, 23, 34 );		// Taking default type

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
}

```

### Specialization

```In all other cases, use the generic template, but if, and only if the type you give me is the following, use this partial version, otherwise if the types are the following, use this complete version```

case of bool:
```cpp
template<> // No precise type anymore
class Pair < bool, bool >{ }; // Specialization of the types
```

> When writing a template, we always have the possibility of writing one or more variations to adapt the behavior according to specific parameters received.