 /* Honor Pledge 
  *
  * I pledge that I have neither given nor recieved any help
  * on this assignment
  *
  */

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory:public Expr_Command_Factory
{
public:
	Stack_Expr_Command_Factory(void);

	Stack_Expr_Command_Factory (Stack <int> & answer);

	virtual ~Stack_Expr_Command_Factory(void);

	virtual Number* Number_Create (int num);

	virtual Add_Command* Add_Create(void);
	 
	virtual Sub_Command* Sub_Create(void);

	virtual Mul_Command* Mul_Create(void);

	virtual Div_Command* Div_Create(void);

	virtual Mod_Command* Mod_Create(void);

private:

	Stack <int> & stack_;

	Stack <int> temp;

	int number;
};
#endif
