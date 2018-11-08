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
#include "Precidence.h"
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
	std::cin>>infix;
	while(infix!=exit)
	{
		std::istringstream input(infix);
		Command * cmd=0;
		Stack <Command *> *temp=new Stack <Command *>;
		Stack <int> answer;
		Stack_Expr_Command_Factory factory( answer);
		Array <Command *> postfix;
		Precidence (infix,factory,postfix);
		Stack <char> precidence;
		Stack <Command *> output;
		int slot=0;
		while(!input.eof())
		{
			bool parenthesis=false;
			input>>token;
			std::cout<< token<<'\n';
			if(token=="+")
			{
				cmd=factory.Add_Create();
				if(!parenthesis)
				{
					if(precidence.top()!= '>')
					{
						(*temp).push(cmd);
						precidence.push('<');
					}
					else if(precidence.top()=='>'||precidence.top()=='=')
					{
						while(precidence.top()=='>'||precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,(*temp).pop());
							slot=slot+1;
						}
					}
					else
					{
						(*temp).push(cmd);
						precidence.push('<');
					}
				}
				else
				{
					(*temp).push(cmd);
					precidence.push('=');
				}
			}
			else if (token=="-")
			{
				cmd=factory.Sub_Create();
				if(!parenthesis)
				{
					if(precidence.top()!='>')
					{
						(*temp).push(cmd);
						precidence.push('<');
					}
					else if(precidence.top()=='>'||precidence.top()=='=')
					{
						while(precidence.top()=='>'||precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,(*temp).pop());
							slot=slot+1;
						}
					}
					else
					{
						(*temp).push(cmd);
						precidence.push('<');
					}
				}
				else
				{
					(*temp).push(cmd);
					precidence.push('=');
				}
			}
			else if (token=="*")
			{
				cmd=factory.Mul_Create();
				if(!parenthesis)
				{
					if(precidence.top()=='=')
					{
						while(precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,(*temp).pop());
							slot=slot+1;
						}
					}
					else
					{
						(*temp).push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					(*temp).push(cmd);
					precidence.push('>');
				}
			}
			else if (token=="/")
			{
				cmd=factory.Div_Create();
				if(!parenthesis)
				{
					if(precidence.top()=='=')
					{
						while(precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,(*temp).pop());
							slot=slot+1;
						}
					}
					else
					{
						(*temp).push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					(*temp).push(cmd);
					precidence.push('>');
				}
			}
			else if (token=="%")
			{
				cmd=factory.Mod_Create();
				if(!parenthesis)
				{
					if(precidence.top()=='=')
					{
						while(precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,(*temp).pop());
							slot=slot+1;
						}
					}
					else
					{
						(*temp).push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					(*temp).push(cmd);
					precidence.push('>');
				}
			}
			else if (token=="(")
			{
				parenthesis=true;
			}
			else if (token==")")
			{
				parenthesis=false;
			}
			else 
			{
				int placeholder;
				std::istringstream converter(token);
				converter>>placeholder;
				cmd=factory.Number_Create(placeholder);
				postfix.set(slot,cmd);
				std::cout<<"Placing a "<<cmd<< "in the Array in slot number "<<slot<<"."<<'\n';
				slot=slot+1;
			}
		}
		while(!(*temp).is_empty())
		{
			postfix.set(slot,(*temp).pop());
			slot=slot+1;
		}
		for(int i=slot;i<-1;--i )
		{
			output.push(postfix.get(i));
		}
		output.print();
		while(!output.is_empty())
		{
			Command* c=output.pop();
			(*c).execute();
			delete c;
		}
    
	std::cout<< "Your answer is "<<answer.top()<<'\n';
	std::cout<< "Please type in your equation or type 'QUIT' to exit the program.";
	std::cin>>infix;
	input.clear();
	delete temp;
	}	
}
