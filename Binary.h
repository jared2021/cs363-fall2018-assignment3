/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _BINARY_H
#define _BINARY_H

#include"Command.h"

class Binary:public Command
{
public:
	Binary(void);

	~Binary(void);

	bool execute (void);

	virtual int evaluate(int n1, int n2)const=0;
};

#endif
