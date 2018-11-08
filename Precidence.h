/* Honor Pledge 
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 *
 */

#ifndef _PRECIDENCE_H_
#define _PRECIDENCE_H_

#include "Converter.h"

class Precidence:public Converter
{
public:
	Precidence(void);

	Precidence(Stack <Command *> &temp,Stack <char> &precidence );

	~Preidence(void);

	void precidence(std::string &token,bool &parenthesis);
};
#endif
