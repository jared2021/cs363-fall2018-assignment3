/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment.
 *
 */

#ifndef _ADD_COMMAND_H
#define _ADD_COMMAND_H

#include "Binary.h"

class Add_Command:public Binary
{
public:
	Add_Command(void);

	Add_Command(Stack <int> & stack);

	virtual ~Add_Command(void);
	
	virtual int evaluate (int n1, int n2)const;

	virtual int get_precidence(void);
	
private:
	int precidence_;
};

#endif
