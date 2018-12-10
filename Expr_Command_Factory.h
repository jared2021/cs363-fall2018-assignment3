 /* Honor Pledge
  *
  * I pledge that I have neither given nor receieved any help
  * on this assignment.
  *
  */

#ifndef _EXPR_COMMAND_FACTORY_H
#define _EXPR_COMMAND_FACTORY_H

#include "Number.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mul_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
#include <memory>
class Expr_Command_Factory
{
public:

	virtual std::shared_ptr <Number*> Number_Create(int num)=0;

	virtual std::shared_ptr <Add_Command*> Add_Create(void)=0;

	virtual std::shared_ptr <Sub_Command*> Sub_Create(void)=0;

	virtual std::shared_ptr <Mul_Command*> Mul_Create(void)=0;

	virtual std::shared_ptr <Div_Command*> Div_Create(void)=0;

	virtual std::shared_ptr <Mod_Command*> Mod_Create(void)=0;

private:

	Stack <int> stack_;

	int number;
};

#endif
