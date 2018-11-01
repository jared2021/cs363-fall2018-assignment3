/* Honor Pledge 
 *
 * I pledge that I have neither given nor recieved any help
 * on this assignment.
 *
 */

#include "Div_Command.h"

Div_Command::Div_Command(Stack <int> & stack)
:Binary(stack)
{

}

Div_Command::~Div_Command(void)
{

}

int Div_Command::evaulate (int n1, int n2)
{
	return (n1/n2);
}
