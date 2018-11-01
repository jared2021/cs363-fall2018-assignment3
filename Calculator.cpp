/* Honor Pledge
 * I pledge that I have neither given nor received any help
 * on this assignment
 *
 */
#include <iostream>
#include "Add_Command.h"
#include "Div_Command.h"
#include "Mul_Command.h"
#include "Sub_Command.h"
#include "Mod_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include <string>
#include <sstream>

int main()
{
	std::string input;
	std::string exit="QUIT";
	std::string converter;
	std::cout<<"Please type in your equation or 'QUIT' to exit the program. "<<'\n';
	std::cin>>input;
	while(input!=exit)
	{
		std::stringstream filter;
		filter.str(input);
		while(std::getline(filter,converter))
		{
			std::cout<<converter<<'\n';
		}
	}
}
