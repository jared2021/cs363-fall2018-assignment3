/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * on this asssingmnet
 *
 */

#ifdef _NUMBER_H
#define _NUMBER_H

#include "Command.h"
#include "Stack.h"

class Number
{
public:

	Number(Stack <int> & s, int n);

	~Number(void);

	void execute(void);

protected:

	Stack <int> stack_;
	int number_;
};
#endif
