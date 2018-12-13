/* Honor Pledge 
 *
 * I pledge that I have neither given nor received any help
 * on this assignment/
 *
 */

#include "Mul_Command.h"

Mul_Command::Mul_Command(void)
:precidence_(1)
{

}

Mul_Command::Mul_Command(Stack <int> & stack)
:Binary(stack),
precidence_(1)
{

}

Mul_Command::~Mul_Command(void)
{

}

int Mul_Command::evaluate (int n1,int n2)const
{
	return (n1 * n2);
}

int Mul_Command::get_precidence(void)
{
	return precidence_;
}
