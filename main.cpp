#if STD_
#define STD std
#define CONTAINER std
#define PRINTCONTAINER() std::cout << "std::vector\n\n" << std::endl;
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#else
#define STD ft
#define CONTAINER ft
#define PRINTCONTAINER() std::cout << "STD::vector\n\n" << std::endl;
#include "inc/Vector.hpp"
#endif

int main(void)
{
	STD::vector<int> Vincent;
	STD::vector<int> Robin(10, 100);
	STD::vector<int> Jean(Robin);
	Vincent = Robin;
	return (0);
}