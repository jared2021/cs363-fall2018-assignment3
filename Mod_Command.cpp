/* Honor Pledge 
 * 
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#include "Mod_Command.h"

Mod_Command::Mod_Command(Stack <int> & stack)
:Binary(stack)
{

}

Mod_Command::~Mod_Command(void)
{

}

int Mod_Command::evaluate(int n1, int n2)
{
	return n1 % n2;
}
