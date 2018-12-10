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

	virtual std::shared_ptr <Number*> Number_Create (int num);

	virtual std::shared_ptr <Add_Command*> Add_Create(void);
	 
	virtual std::shared_ptr <Sub_Command*> Sub_Create(void);

	virtual std::shared_ptr <Mul_Command*> Mul_Create(void);

	virtual std::shared_ptr <Div_Command*> Div_Create(void);

	virtual std::shared_ptr <Mod_Command*> Mod_Create(void);

private:

	Stack <int> & stack_;

	Stack <int> temp;

	int number;
};
#endif
