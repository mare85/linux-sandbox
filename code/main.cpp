#include <iostream>
#include <memory>
int main() 
{
	std::unique_ptr<int> retValPtr(new int[1]);
	*retValPtr = 0;
	std::cout<< "complete me and nerd tree working"
		<< std::endl
		<< "ret value: " << *retValPtr
		<< std::endl;
	return *retValPtr;
}
