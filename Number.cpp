/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment
 *
 */

#include "Number.h"

Number::Number(Stack <int> &s, int n)
:stack_(s),
 number_(n)
{

}

Number::~Number(void)
{
	delete stack_;
}

void Number::execute (void)
{
	stack_.push(number_);
}
