/* Honor Pledge 
 *
 * I pledge that I have neither given nor recieved any help
 * on this assignment.
 *
 */

#include "Div_Command.h"
Div_Command::Div_Command(void)
:precidence_(1)
{

}

Div_Command::Div_Command(Stack <int> & stack)
:Binary(stack),
precidence_(1)
{

}

Div_Command::~Div_Command(void)
{

}

int Div_Command::evaluate (int n1, int n2)const
{
  // COMMENT: You are not handling divide by zero.
  // RESPONSE Now handle dividing by zero.
	if(n2==0)
	{
		throw("Cannot divide by zero.");
	}
	else
	{
		return (n1/n2);
	}
}

int Div_Command::get_precidence(void)
{
	return precidence_;
}
