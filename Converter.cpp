/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment
 *
 */

#include "Converter.h"

Converter::Converter(void)
{

}

Converter::Converter(Stack <Command*> &temp, Stack <char> &precidence)
:parenthesis(false)
{

}

Converter::~Converter(void)
{

}

bool Converter::infix_to_postfix(const std::string &infix,Expr_Command_Factory & factory,Array <Command*> & postfix)
{
	std::istringstream input(infix);
	std::string token;
	Command *cmd=0;
	int slot=0;
	while(!input.eof ())
	{
		input>>token;
		if(token=="+")
		{
			cmd=factory.Add_Create();
			//do something here to calla function from another class to create precidence
		}
		else if(token=="-")
		{
			cmd=factory.Sub_Create();
		}
		else if(token=="*")
		{
			cmd=factory.Mul_Create();
		}
		else if (token=="/")
		{
			cmd=factory.Div_Create();
		}
		else if (token=="%")
		{
			cmd=factory.Mod_Create();
		}
		else
		{
			int placeholder;
			std::istringstream converter(token);
			converter>>placeholder;
			cmd=factory.Number_Create(placeholder);
			postfix.set(slot,cmd);
			slot=slot+1;
		}
	}
}
