/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _BINARY_H
#define _BINARY_H

#include"Command.h"
#include"Stack.h"

class Binary : public Command
{

public:

	Binary(void);

	Binary(Stack <int> & stack);

	virtual ~Binary(void);

	virtual bool execute (void);

	virtual int evaluate(int n1, int n2)const=0;

private:

	Stack <int> & s_;
	Stack <int> temp;
};

#endif
