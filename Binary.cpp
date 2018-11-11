/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#include "Binary.h"

Binary::Binary(void)
:s_(temp)
{

}

Binary::Binary(Stack <int> & stack)
:s_(stack)
{

}

Binary::~Binary(void)
{

}

bool Binary::execute(void)
{
	std::cout<<"Popping the first number off the stack."<<'\n';
	int n2=s_.pop();
	std::cout<<"Popping the second number off the stack."<<'\n';
	int n1=s_.pop();
	int result=evaluate(n1,n2);
	std::cout<<"The result is "<<result<<'\n';
	s_.push(result);
}

