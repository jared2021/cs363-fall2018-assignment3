/* Honor Pledge 
 * 
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#include "Mod_Command.h"

Mod_Command::Mod_Command(void)
:precidence_(1)
{

}

Mod_Command::Mod_Command(Stack <int> & stack)
:Binary(stack),
precidence_(1)
{

}

Mod_Command::~Mod_Command(void)
{

}

int Mod_Command::evaluate(int n1, int n2)const
{
	return n1 % n2;
}

int Mod_Command::get_precidence(void)
{
	return precidence_;
}
