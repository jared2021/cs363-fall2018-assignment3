// $Id: ``Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

// Stack
//
template <typename T>
Stack <T>::Stack (void)
:top_(0)
{
		
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:myArray(stack.myArray),
 top_(stack.top_)
{
	
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
		
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
  // COMMENT The stack should be allowed to grow if no more space.
  // RESPONSE Stack can now grow if it has no more space.

	if(top_!=(myArray).max_size())
	{
		(myArray).set(top_,element);
		top_=top_+1;
		(myArray).set_size(top_);
	}
	else if (top_==(myArray).max_size())
	{
		(myArray).resize((myArray).max_size()+1);
		(myArray).set(top_,element);
		top_=top_+1;
		(myArray).set_size(top_);
	}
}
//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{
	if(top_!=0)
	{
		top_=top_-1;
		(myArray).set_size((myArray).size()-1);
		T temp=(myArray).get(top_);
		return temp;		
	}
	else
	{
		throw std::out_of_range("No items in stack to pop.");
	}
}
//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this==&rhs)
	{
		return *this;
	}
	else
	{
		for(int i=0;i<(myArray).size();++i)
		{
			(myArray).set(i,(rhs).myArray.data(i));
		}
		return *this;
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	(myArray).resize(0);
}

template <typename T>
void Stack <T>::print(void)
{
	for(int i=0;i<top_;++i)
	{
		std::cout<<(myArray).get(i);
	}
	std::cout<<'\n';
}
