 /* Honor Pledge
  *
  * I pledge that I have neither given nor receieved any help
  * on this assignment.
  *
  */

class Expr_Command_Factory
{
public:

	virtual Number_Command(int num)=0;

	virtual Add_Command(void)=0;

	virtual Sub_Command(void)=0;

	virtual Mul_Command(void)=0;

	virtual Div_Command(void)=0;
}
