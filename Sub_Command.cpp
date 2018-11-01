/* Honor Pledge
 *
 * I pledge that I have neither given nor received any help
 * for this assignment
 *
 */

#include "Binary.h"
#include "Sub_Command.h"

Sub_Command::Sub_Command(void)
{

}

Sub_Command::~Sub_Command(void)
{

}

int Sub_Command::evaluate (int n1, int n2)
{
	return n1-n2;
}
