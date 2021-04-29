# C++
## Module 08

Day 08 [subject](https://cdn.intra.42.fr/pdf/pdf/20275/en.subject.pdf).

*PERSONAL NOTES/RULES:*
- Think about using a reference rather than a copy
- Have a code, as const as I can

## Discovering [STL](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/) and [containers](https://www.cplusplus.com/reference/stl/).

```
Standard Templates Library has four components

Algorithms
Containers
Functions
Iterators
```


```cpp

#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOperation;

int		main( void )
{
	std::list<int>							lst1;	// One of the most current template container, is the list (here templated on int)
	std::map<std::string, IOperation*> 		map1; 	// A map, we can use other type than string for our key values
	std::vector<int>						v1;		// Vector is a tab, taking the type we want, here initialized by default (let's check)
	std::vector<int>						v2(42, 100); // Here I initialize my vector, saying I want 42 entries that take 100 for value

	lst1.push_back(1);						// Here I can manage the content of my int list
	lst1.push_back(17);
	lst1.push_back(42);

	map1["opA"] = new OperationA;			// Remember subtyping, putting a pointer in the interface to store its derived objects
	map1["opB"] = new OperationB;

	// Here we discover iterator (similiraty with a pointer, kind of same behavior)
	
	std::list<int>::const_iterator	it;					// Here I instantiate a const_iterator through an int list
	// Can be read as "in an int list namespace, I want a const_iterator" (cf nested classes))
	
	std::list<int>::const_iterator	ite = lst1.end();	// Same stuff, here I initialize my second iterator on lst1.end()
	// It is not the last element but a value after, indicating we exceed the last elem int list)


	// Remember that there is no only const_iterator (also iterator), and that they're not only dedicated for list, but also map... (not stacks!)

	for (it = lst1.begin(); it != ite; ++it) // Here I compare it and ite
	{
		std::cout << *it << std::endl; // Can be dereferenced as a pointer
	}
	
	return (0);
}

```

Let's now have look on alogrithms.

```cpp

#include <iostream>
#include <algorithm>
#include <list>

void	displayInt( int i )
{
	std::cout << i << std::endl;
}

int		main( void )
{
	std::list<int> lst;

	lst.push_back(10); // Filling my list
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	// Now instead of doing iterators, with beginning and end...
	for_each(lst.begin(), lst.end(), displayInt); // My two iterators + the operation I want to apply on my data collection

	return (0);
}

```