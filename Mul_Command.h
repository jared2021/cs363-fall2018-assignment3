/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _MUL_COMMAND_H
#define _MUL_COMMAND_H

#include "Binary.h"

class Mul_Command:public Binary
{
public:

	Mul_Command(void);

	~Mul_Command(void);

	int evaluate (int n1,int n2);

private:

	Stack <int> stack_;
};
#endif
