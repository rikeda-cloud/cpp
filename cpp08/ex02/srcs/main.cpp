#include "MutantStack.hpp"
#include <iostream>

// int main()
// {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int	main(void) {
	MutantStack<int>*	stack1 = new MutantStack<int>;

	stack1->push(10);
	stack1->push(11);
	stack1->push(12);
	stack1->push(1);
	stack1->push(2);

	std::cout << "stack1.top() = " << stack1->top() << std::endl;

	std::stack<int>	stack2(*stack1);
	MutantStack<int>	stack3(*stack1);
	MutantStack<int>	stack4 = *stack1;
	delete stack1;
	std::cout << "stack2.top() = " << stack2.top() << std::endl;
	std::cout << "stack3.top() = " << stack3.top() << std::endl;
	std::cout << "stack4.top() = " << stack4.top() << std::endl;

	return 0;
}
