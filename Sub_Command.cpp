/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment
 *
 */

#include "Sub_Command.h"

Sub_Command::Sub_Command(void)
:precidence_(0)
{
	
}

Sub_Command::Sub_Command(Stack <int> & stack)
:Binary(stack),
precidence_(0)
{

}

Sub_Command::~Sub_Command(void)
{

}

int Sub_Command::evaluate (int n1, int n2)const
{
	return n1-n2;
}

int Sub_Command::get_precidence(void)
{
	return precidence_;
}
