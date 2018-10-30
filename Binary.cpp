/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#include "Binary.h"

Binary::Binary(void)
{

}

Binary::~Binary(void)
{

}

bool Binary::execute(void)
{
	int n2=s_.pop();
	int n1=s_.pop();
	int result=this->evaluate(n1,n2);
	s.push(result);
}

virtual int Binary::evaluate (int n1,int n2)const =0;
