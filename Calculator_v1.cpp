/* Honor Pledge
 * I pledge that I have neither given nor received any help
 * on this assignment
 *
 */
#include <iostream>
#include "Add_Command.h"
#include "Converter.h"
#include "Div_Command.h"
#include "Mul_Command.h"
#include "Sub_Command.h"
#include "Mod_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include <string>
#include <sstream>

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

// COMMENT: Improve the design of your commands to reduce the design
// complexity of this method. Right now, there are too many if-else
// statements, and a lot of duplicate code.

int main()
{
	std::string infix;
	std::string exit="QUIT";
	std::string token;
	std::cout<<"Please type in your equation or 'QUIT' to exit the program. "<<'\n';
	std::getline(std::cin,infix);
	while(infix!=exit)
	{
		Stack <Command *> temp;
		Stack <char> precidence;
		Converter* convert=new Converter(temp,precidence);
		Stack <int> answer;
		Stack_Expr_Command_Factory factory( answer);
		Array <Command *> *postfix=new Array <Command*> (20);
		(*convert).infix_to_postfix(infix,factory,postfix);
		int end=(*convert).get_answer(answer);
		infix.clear();
		std::cout<< "Your answer is "<<end<<'\n';
		std::cout<< "Please type in your equation or type 'QUIT' to exit the program."<<'\n';
		std::getline(std::cin,infix);
		delete convert;
	}
}
