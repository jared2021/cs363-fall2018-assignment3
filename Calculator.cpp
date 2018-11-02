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
	std::string token;
	std::cout<<"Please type in your equation or 'QUIT' to exit the program. "<<'\n';
	std::cin>>input;
	while(input!=exit)
	{
		std::istringstream filter(input);
		std::cout<<"Is this it?"<<'\n';
		Command * cmd=0;
		std::cout<<"Does this work?"<<'\n';
		Stack <Command *> temp;
		std::cout<< "here?";
		Stack <int> answer;
		Stack_Expr_Command_Factory factory(answer);
		Array <Command *> postfix;
		Stack <char> precidence;
		Stack <Command *> output;
		int slot=0;
		std::cout<<"Got to here."<<'\n';
		while(!filter.eof())
		{
			bool parenthesis=false;
			filter>>token;
			if(token=="+")
			{
				cmd=factory.Add_Create();
				if(!parenthesis)
				{
					if(precidence.top()!= '>')
					{
						temp.push(cmd);
						precidence.push('<');
					}
					else if(precidence.top()=='>'||precidence.top()=='=')
					{
						while(precidence.top()=='>'||precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,temp.pop());
							slot=slot+1;
						}
					}
					else
					{
						temp.push(cmd);
						precidence.push('<');
					}
				}
				else
				{
					temp.push(cmd);
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
						temp.push(cmd);
						precidence.push('<');
					}
					else if(precidence.top()=='>'||precidence.top()=='=')
					{
						while(precidence.top()=='>'||precidence.top()=='=')
						{
							precidence.pop();
							postfix.set(slot,temp.pop());
							slot=slot+1;
						}
					}
					else
					{
						temp.push(cmd);
						precidence.push('<');
					}
				}
				else
				{
					temp.push(cmd);
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
							postfix.set(slot,temp.pop());
							slot=slot+1;
						}
					}
					else
					{
						temp.push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					temp.push(cmd);
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
							postfix.set(slot,temp.pop());
							slot=slot+1;
						}
					}
					else
					{
						temp.push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					temp.push(cmd);
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
							postfix.set(slot,temp.pop());
							slot=slot+1;
						}
					}
					else
					{
						temp.push(cmd);
						precidence.push('>');
					}
				}
				else
				{
					temp.push(cmd);
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
				slot=slot+1;
			}
		}
		while(!temp.is_empty())
		{
			postfix.set(slot,temp.pop());
			slot=slot+1;
		}
		for(int i=slot;i<-1;--i )
		{
			output.push(postfix.get(i));
		}
		while(!output.is_empty())
		{
			Command* c=output.pop();
			(*c).execute();
		}
	std::cout<< "Your answer is "<<answer.top()<<'\n';
	std::cout<< "Please type in your equation or type 'QUIT' to exit the program.";
	std::cin>>input;
	}	
}
