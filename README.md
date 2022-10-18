# FT_CONTAINERS
FT_CONTAINERS is a project from the 42 school in c++ with the goal:
- Recreate the container vector and its iterators
- Recreate the container stack
- Recreate the container map and its iterators

**In this project you will learn how to do the 3 stack**
*If you like it don't forget to put a star !*

## Useful links
### General links
- [What is a namespace](https://www.geeksforgeeks.org/namespace-in-c/#:~:text=Namespace%20is%20a%20feature%20added,the%20same%20name%20are%20allowed.)
- [What is a template](https://www.geeksforgeeks.org/templates-cpp/)
- [What is the keyword typedef](https://en.cppreference.com/w/cpp/language/typedef)
- [What is explicit keyword](https://www.geeksforgeeks.org/use-of-explicit-keyword-in-cpp/#:~:text=Explicit%20Keyword%20in%20C%2B%2B%20is%20used%20to%20mark%20constructors,can%20be%20used%20in%20typecasting.)

### Vector links
- [All vector functions](https://cplusplus.com/reference/vector/vector/)
- [Deallocate memory](https://en.cppreference.com/w/cpp/memory/allocator/deallocate)
- [allocate memory](https://cplusplus.com/reference/memory/allocator/allocate/)
- [How works max size](https://stackoverflow.com/questions/3813124/c-vector-max-size)
- [Introduction to Iterator](https://www.geeksforgeeks.org/introduction-iterators-c/)
- [what are iterator and how to create it](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)

## VECTOR

### How to do vector?
Begin by the beggining and read the [man](https://cplusplus.com/reference/vector/vector/).
I'm using template inside my hpp document. All my functions are in the hpp doc
The project is divided into 5 parts:
- **Canonical form**
- **Iterators**
- **Capacity**
- **Element access**
- **Modifiers**

#### Canonical Form
You have to create constructor, that means you need to:
- **Declare your variables**
	- Your allocator for the allocation of the memory for your vector,
	- The size of the vector.
	- The capacity for your memory (You can have a buffer to improve performance for your machine)
	- A pointer to your vector.
- **Create the constructor functions**
	- Be sure you allocate the memory for your new vector.
- **Create the desctructor functions**
	- Be sure you free the memory allowed from your vector.
- **Create the assign content functions**
	- Be sure you free the memory from the vector which will be copied.
	- Be sure you allocate the memory from the memory allocated you are copying

#### Iterators
This is the tricky part for vector. An iterator is an object which points to an element of your container. read the Iterator part to know more about it.
- Because I did a vector_iterator class, I created a typedef iterator and const_iterator which link and create an object vector_iterator directly link to my .hpp file.
- **begin and end**
	- Create two functions which send an iterator which point to the beginning and the end of your function.

#### Capacity functions
- **Max_size**
	- For the function max_size, i let you check this [documentation](https://en.cppreference.com/w/cpp/types/numeric_limits/max)
- **reserve**
	- You need to check if you current capacity if lesser than the number sent into the function. [Man of reserve](https://cplusplus.com/reference/vector/vector/reserve/)
	- If (n > capacity)
		You have to:
		- Create a new array
		- Allocate the new size
		- Construct your new array and deallocate your old one at the same time
		- Then you replace the new value.
- **resize**
[man of resize](https://cplusplus.com/reference/vector/vector/resize/)
	- If n > You capacity, you have to use the reserve function
	- If n < your size, you have to destroy memory
	- If n > your size, you have to allocate memory

#### Element Access
Nothing particular for this one, just return the value, these functions will allow you to test your program

#### Modifiers functions
There are functions where you don't need the iterators. Be sure, you have done at least capacity and element access to begin.
- **assign**
	- Don't forget to destroy the memory of your old content.
	- Construct your new array to give the value and memory.
- **swap**
	- To save time, use directly the function swap from the std. [Man here](https://cplusplus.com/reference/vector/vector/swap/)
- **clear**
	- Don't forget to destroy the memory also.
	- Put size to 0
- **push_back**
	- Use the reserve function, don't recode everything!

## Iterators
Iterators are the tricky part of this project. For my part I created a Iterator.hpp file for vector and for map.
To undestand how create your first own iterator, use this really insteresting [tutorial](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)

### Vector Iterators
You will need to create the vector_iterator class and the reverse_iterator class.

#### Vector_iterator
vector_iterator will be used for almost all your function, it will allow to do operators (++, --, ==, += etc...).
1. Create your typedef as the tutorial mentionned just above it explains a lot of things.
2. Create your constructor and destructor.
3. Create all your operators functions, you will need it when you will use your iterator.

#### Reverse_iterator
[What is iterator trait](https://www.boost.org/sgi/stl/iterator_traits.html)
[Nested class](https://www.geeksforgeeks.org/nested-classes-in-c/#:~:text=A%20nested%20class%20is%20a,access%20rules%20shall%20be%20obeyed.)
[How works "this"](https://www.javatpoint.com/cpp-this-pointer#:~:text=In%20C%2B%2B%20programming%2C%20this%20is,be%20used%20to%20declare%20indexers.)
[man reverse iterator](https://en.cppreference.com/w/cpp/iterator/reverse_iterator)

Here is the last difficult part about vector, doing the reverse_iterator.
You are maybe asking yourself what is this, how it works. I will try to explain.
**What is reverse iterator**
Reverse_iterator is an iterator adaptor that reverses the direction of a given iterator.

1. **Create a new class reverse_iterator**
- Indeed you have to declare new variables according to the [man](https://en.cppreference.com/w/cpp/iterator/reverse_iterator).
```c
template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef 		Iterator 												iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category		iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef typename iterator_traits<iterator_type>::reference				reference;
```
- **explaining the code above**
As you can see, you need to define as before your iterator, pointer etc... but it is more complicated. You need to create another class iterator trait (*you can find the class in my file utils*).
Iterator trait ([man here](https://en.cppreference.com/w/cpp/iterator/iterator_traits)) is the type trait class that provides uniform interface.
```c
iterator_traits<iterator_type>::iterator_category
// iterator_type means my iterator previously defined in vector_iterator
// iterator_traits<iterator_type>::iterator_category // means i am gonna take the iterator_category from iterator_traits class
```

2. **Iterator_Traits class **
- According to the man you need to create 3 class, our 1st class will take an template "iterator".
That means we will send our vector_iterator we created before on it.
```c
/*** We define the iterator trait here ***/
	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};
```
- Our Iterator will take the iterator_category we previously defined in our vector_iterator.
That what means *Iterator::iterator_category* for example in english, we are looking for iterator_category from Iterator.
- We also need a class for pointer T*.
```c
/*** The second iterator trait is for the case you have a pointer ***/
	template <class T>
	class iterator_traits<T *>
	{
	public:
		typedef std::random_access_iterator_tag 	iterator_category;
		typedef T                         		 	value_type;
		typedef std::ptrdiff_t                 		difference_type;
		typedef T*									pointer;
		typedef T&                        		 	reference;
	};
```

3. **Create all your members functions**

- Don't forget because it is reverse, when you have your operator++ for example, you have to do
```c
reverse_iterator& operator++()
{
	this->_ptr--;
	return (*this);
}
```

