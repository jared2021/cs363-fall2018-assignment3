/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifdef _COMMAND_H
#define _COMMAND_H

class Command
{
public:
	Command(void);

	~Command(void);

	virtual void execute (void)=0;
};

#endif 
