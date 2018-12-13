/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment
 *
 */

#include "Add_Command.h"

Add_Command::Add_Command(void)
:precidence_(0)
{

}

Add_Command::Add_Command(Stack <int> & stack)
:Binary(stack),
precidence_(0)
{

}

Add_Command::~Add_Command(void)
{

}

int Add_Command::evaluate(int n1, int n2)const
{
	return n1+n2;
}

int Add_Command::get_precidence(void)
{
	return precidence_;
}
