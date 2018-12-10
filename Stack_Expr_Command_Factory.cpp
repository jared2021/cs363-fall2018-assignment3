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

std::shared_ptr <Number*> Stack_Expr_Command_Factory::Number_Create(int num)
{
	number=num;
	std::shared_ptr <Number*> c=new Number(stack_,number);
	return c;
}

std::shared_ptr <Add_Command*> Stack_Expr_Command_Factory::Add_Create(void)
{
	std::shared_ptr <Add_Command*> c=new Add_Command(stack_);
	return c;
}

std::shared_ptr <Sub_Command*> Stack_Expr_Command_Factory::Sub_Create(void)
{
	std::shared_ptr <Sub_Command*> c=new Sub_Command(stack_);
	return c;
}

std::shared_ptr <Mul_Command*> Stack_Expr_Command_Factory::Mul_Create(void)
{
	std::shared_ptr <Mul_Command*> c=new Mul_Command(stack_);
	return c;
}

std::shared_ptr <Div_Command*> Stack_Expr_Command_Factory::Div_Create(void)
{
	std::shared_ptr <Div_Command*> c=new Div_Command(stack_);
	return c;
}

std::shared_ptr <Mod_Command*> Stack_Expr_Command_Factory::Mod_Create(void)
{
	std::shared_ptr <Mod_Command*> c=new Mod_Command(stack_);
	return c;
}
