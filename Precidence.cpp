/* Honor Pledge 
 *
 * I pledge that I have neither given nor received any help on this assignment.
 *
 */

#include "Precidence.h"

Precidence::Precidence(void)
{

}

Precidence::Precidence(Stack <Command *> &temp,Stack <char> &precidence)
:Converter(temp,precidence)
{

}

Precidence::~Precidence(void)
{

}

void Precidence(std::string &token,bool &parenthesis)
{
	if(token=="+"&&!parenthesis||token=="-"&&!parenthesis)
	{
		if(precidence.top()!='>')
		{
			temp.push(cmd);
			precidence.push('<')
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
				
	}
}
