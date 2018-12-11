/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */
#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(void)
:stack_(temp)
{
	
}

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack <int> & answer)
:stack_(answer)
{

}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void)
{
		
}

Number* Stack_Expr_Command_Factory::Number_Create(int num)
{
	number=num;
	Number* c=new Number(stack_,number);
	return c;
}

Add_Command* Stack_Expr_Command_Factory::Add_Create(void)
{
	Add_Command* c=new Add_Command(stack_);
	return c;
}

Sub_Command* Stack_Expr_Command_Factory::Sub_Create(void)
{
	Sub_Command* c=new Sub_Command(stack_);
	return c;
}

Mul_Command* Stack_Expr_Command_Factory::Mul_Create(void)
{
	Mul_Command* c=new Mul_Command(stack_);
	return c;
}

Div_Command* Stack_Expr_Command_Factory::Div_Create(void)
{
	Div_Command* c=new Div_Command(stack_);
	return c;
}

Mod_Command* Stack_Expr_Command_Factory::Mod_Create(void)
{
	Mod_Command* c=new Mod_Command(stack_);
	return c;
}
