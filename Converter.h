/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment.
 *
 */
#ifndef _CONVERTER_H_
#define _COnVERTER_H_

#include <string>
#include <sstream>
#include "Command.h"
#include "Stack_Expr_Command_Factory.h"
#include "Stack.h"

class Converter
{

public:
	Converter(void);

	Converter(Stack <Command*> &temp, Stack <char> &precidence);

	~Converter(void);

	bool infix_to_postfix(const std::string & infix,Expr_Command_Factory & factory,Array <Command*> & postfix);

	bool precidence(std::string &token,Command * cmd, Array <Command*> &postfix);

	int get_slot(void);

private:
	int slot_;

	bool parenthesis_;

	Stack <Command*> temp_;
	
	Stack <char> precidence_;
};

#endif