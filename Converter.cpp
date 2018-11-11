/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment
 *
 */

#include "Converter.h"
#include <iostream>
Converter::Converter(void)
{

}

Converter::Converter(Stack <Command*> &temp, Stack <char> &precidence)
:parenthesis_(false),
 temp_(temp),
 precidence_(precidence),
 slot_(0)
{

}

Converter::~Converter(void)
{

}

bool Converter::infix_to_postfix(const std::string &infix,Expr_Command_Factory & factory, Array<Command*> & postfix)
{
	std::istringstream input(infix);
	std::string token;
	Command *cmd=0;
	while(!input.eof ())
	{
		input>>token;
		std::cout<<token<<'\n';
		if(token=="+")
		{
			std::cout<<"Creating add command."<<'\n';
			cmd=factory.Add_Create();
			precidence(token,cmd,postfix);
		}
		else if(token=="-")
		{
			cmd=factory.Sub_Create();
			precidence(token,cmd,postfix);
		}
		else if(token=="*")
		{
			cmd=factory.Mul_Create();
			precidence(token,cmd,postfix);
		}
		else if (token=="/")
		{
			cmd=factory.Div_Create();
			precidence(token,cmd,postfix);
		}
		else if (token=="%")
		{
			cmd=factory.Mod_Create();
			precidence(token,cmd,postfix);
		}
		else
		{
			std::cout<<"Creating a number command."<<'\n';
			int placeholder;
			std::istringstream converter(token);
			converter>>placeholder;
			cmd=factory.Number_Create(placeholder);
			postfix.set(slot_,cmd);
			std::cout<<"Incrementing slot(while loop 1)"<<'\n';
			slot_=slot_+1;
		}
	}
	while(!temp_.is_empty())
	{
		std::cout<<"Popping elements off of the stack.(Converter while loop)"<<'\n';
		postfix.set(slot_,temp_.pop());
		std::cout<<"Incrementing slot (while loop 2)"<<'\n';
		slot_=slot_+1;
	}
	Stack <Command *> output;
	for(int i=slot_-1;i>-1;i--)
	{
		std::cout<<"i is "<<i<<'\n';
		std::cout<<"Pushing elements onto the output stack."<<'\n';
		output.push(postfix.get(i));
	}
	while(!output.is_empty())
	{
		Command* c=output.pop();
		std::cout<<"Executing command."<<'\n';
		(*c).execute();
		delete c;
	}
}
bool Converter::precidence(std::string &token, Command * cmd, Array <Command*> &postfix)
{
	if(token=="+"&&!parenthesis_||token=="-"&&!parenthesis_)
	{
		if(precidence_.top()!='>')
		{
			temp_.push(cmd);
			precidence_.push('<');
		}
		else if(precidence_.top()=='>'||precidence_.top()=='='||precidence_.top()=='!')
		{
			while(precidence_.top()=='>'||precidence_.top()=='='||precidence_.top()=='!')
			{
				precidence_.pop();
				postfix.set(slot_,temp_.pop());
				slot_=slot_+1;
			}
		}
	}
	else if(token=="+"&&parenthesis_||token=="-"&&parenthesis_)
	{
		if(precidence_.top()!='!')
		{
			temp_.push(cmd);
			precidence_.push('=');
		}
		else
		{
			while(precidence_.top()=='!')
			{
				precidence_.pop();
				postfix.set(slot_,temp_.pop());
				slot_=slot_+1;
			}
		}
	}
	else if(token=="*"&&!parenthesis_||token=="/"&&!parenthesis_||token=="%"&&!parenthesis_)
	{
		if(precidence_.top()=='='||precidence_.top()=='!')
		{
			while(precidence_.top()=='='||precidence_.top()=='!')
			{
				precidence_.pop();
				postfix.set(slot_,temp_.pop());
				slot_=slot_+1;
			}
		}
		else
		{
			temp_.push(cmd);
			precidence_.push('>');
		}
	}
	else if(token=="*"&&parenthesis_||token=="/"&&parenthesis_||token=="%"&&parenthesis_)
	{
		temp_.push(cmd);
		precidence_.push('!');
	}
	else if(token=="(")
	{
		parenthesis_=true;
	}
	else if(token==")")
	{
		parenthesis_=false;
	}
	return true;
}

int Converter::get_slot(void)
{
	return slot_;
}

int Converter::get_answer(Stack <int> & answer)
{
	int end=answer.pop();
	return end;
}
