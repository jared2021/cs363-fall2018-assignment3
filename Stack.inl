// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment
//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	return (myArray).data(top_);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if((myArray).size()==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
