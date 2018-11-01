/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */
#include "Add_Command.h"
#include "Div_Command.h"
#include "Mul_Command.h"
#include "Sub_Command.h"
#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & stack)
:stack_(stack)
{

}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void)
{
	delete stack_;
}

Number_Command::Stack_Expr_Command_Factory(int num)
:number(num)
{
	Number_Command c= new Number_Command(number);
	return c;
}

Add_Command::Stack_Expr_Command_Factory(void)
{
	Add_Command c= new Add_Command();
	return c;
}

Sub_Command::Stack_Expr_Command_Factory(void)
{
	Sub_Command c= new Sub_Command();
	return c;
}

Mul_Command::Stack_Expr_Command_Factory(void)
{
	Mul_Command c= new Mul_Command();
	return c;
}

Div_Command::Stack_Expr_Command_Factory(void)
{
	Div_Command c= new Div_Command();
	return c;
}
