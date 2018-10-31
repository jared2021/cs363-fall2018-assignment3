/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & stack)
:stack_(stack)
{

}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void)
{
	delete stack_;
}


