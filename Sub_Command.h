/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment.
 *
 */

#ifndef _SUB_COMMAND_H
#define _SUB_COMMAND_H

#include "Binary.h"

class Sub_Command:public Binary
{
public:
	Sub_Command(void);

	Sub_Command(Stack <int> & stack);

	virtual ~Sub_Command(void);

	virtual int evaluate(int n1, int n2)const;

	virtual int get_precidence(void);

private:
	int precidence_;
};

#endif
