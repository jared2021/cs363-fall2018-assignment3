/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment.
 *
 */

#ifdef _SUB_COMMAND_H
#define _SUB_COMMAND_H

#include "Binary.cpp"

class Sub_Command:public Binary
{
public:

	Sub_Command(void);

	~Sub_Command(void);

	int evaluate(int n1, int n2);
};

#endif