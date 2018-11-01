 /* Honor Pledge 
  *
  * I pledge that I have neither given nor recieved any help
  * on this assignment
  *
  */

#ifdef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
class Stack_Expr_Command_Factory:public Expr_Command_Factory
{
public:
	Stack_Expr_Command_Factory (Stack <int> & stack);

	~Stack_Expr_Command_Factory(void)

	virtual Number_Command (int num);

	virtual Add_Command(void);
	
	virtual Sub_Command(void);

	virtual Mul_Command(void);

	virtual Div_Command(void);

private:

	Stack <int> stack_;

	int number;
};
#endif
