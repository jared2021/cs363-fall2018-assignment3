/* Honor Pledge 
 *
 * I pledge that I have neither given nor received any help
 * on this assignment/
 *
 */

#include "Mul_Command.h"

Mul_Command::Mul_Command(void)
:Binary(Stack <int> & stack),
stack_(stack)
{

}

Mul_Command::~Mul_Command(void)
{

}

int Mul_Command::evaluate (int n1,int n2)
{
	return (n1 * n2);
}
