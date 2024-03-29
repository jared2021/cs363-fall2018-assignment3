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
:parenthesis_(false),
 temp_(temp),
 precidence_(precidence),
 slot_(0)
{

}

Converter::~Converter(void)
{
	delete add;
	delete sub;
	delete mul;
	delete div;
	delete mod;
	delete num;
	delete com;
}

void Converter::infix_to_postfix(const std::string &infix,Expr_Command_Factory & factory, Array<Command*> * postfix)
{
	std::istringstream input(infix);
	std::string token;
	while(!input.eof ())
	{
		input>>token;
		if(token!="+"&&token!="-"&&token!="*"&&token!="/"&&token!="%")
		{
			int placeholder;
			std::istringstream converter(token);
			converter>>placeholder;
			num=factory.Number_Create(placeholder);
			postfix->set(slot_,num);
			slot_=slot_+1;
		}
		else if(token=="+")
		{
			add=factory.Add_Create();
			precidence(token,add,postfix);
		}
		else if(token=="-")
		{
			sub=factory.Sub_Create();
			precidence(token,sub,postfix);
		}
		else if(token=="*")
		{
			mul=factory.Mul_Create();
			precidence(token,mul,postfix);
		}
		else if (token=="/")
		{
			div=factory.Div_Create();
			precidence(token,div,postfix);
		}
		else if (token=="%")
		{
			mod=factory.Mod_Create();
			precidence(token,mod,postfix);
		}
	}
	while(!temp_.is_empty())
	{
		postfix->set(slot_,temp_.pop());
		slot_=slot_+1;
	}
	Stack <Command*> output;
	for(int i=slot_-1;i>-1;i--)
	{
		output.push(postfix->get(i));
	}
	while(!output.is_empty())
	{
		com=output.pop();
		(*com).execute();
	}
}
void Converter::precidence(std::string &token, Command * cmd, Array <Command*> *postfix)
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
				postfix->set(slot_,temp_.pop());
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
				postfix->set(slot_,temp_.pop());
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
				postfix->set(slot_,temp_.pop());
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
