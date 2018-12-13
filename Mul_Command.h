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

	Mul_Command(Stack <int> & stack);

	~Mul_Command(void);

	virtual int evaluate (int n1,int n2)const;

	virtual int get_precidence(void);

private:

	//Stack <int> stack_;

	int precidence_;
};
#endif
