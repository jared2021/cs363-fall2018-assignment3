/* Honor Pledge 
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Binary.h"

class Div_Command:public Binary
{
public:
	Div_Command(void);

	~Div_Command(void);

	int evaulate (int n1, int n2)
};

#endif
