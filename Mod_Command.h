 /* Honor Pledge
  * I pledge that I have neither given nor received any help
  * on this assignment.
  *
  */

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Binary.h"
class Mod_Command:public Binary
{
public:
	Mod_Command(void);

	Mod_Command(Stack <int> & stack);

	~Mod_Command(void);

	virtual int evaluate (int n1, int n2)const;

	virtual int get_precidence(void);

private:

	int precidence_;
};

#endif
