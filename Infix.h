/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _INFIX_H_
#define _INFIX_H_

class Infix
{
public:

	virtual bool infix_to_postfix(const std::string &infix,Expr_Command_Factory & factory,Array <Command*> & postfix)=0;
	
};
#endif
