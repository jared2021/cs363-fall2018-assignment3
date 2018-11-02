/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this asssingmnet
 *
 */

#ifndef _NUMBER_H
#define _NUMBER_H

#include "Command.h"
#include "Stack.h"

class Number:public Command
{
public:
	Number(void);

	Number(Stack <int> & s, int n);

	~Number(void);

	bool execute(void);

protected:

	Stack <int> stack_;
	int number_;
};
#endif
