// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
//
// Array
//
template <typename T>
Array <T>::Array (void)
:Array_Base<T>()
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:Array_Base<T>(length,fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:Array_Base<T>(array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if(this==&rhs)
	{
		return *this;
	}
	else
	{
		for(int i=0;i<(*this).size();++i)
		{
			(*this).get(i)=(rhs).get(i);
		}
		return *this;
	}
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if(index>(*this).max_size())
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return (*this).data(index);
	}
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if(index>(*this).max_size())
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return (*this).get(index);
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size>(*this).max_size())
	{
		std::cout<<"Resizing array.";
		T *temp= new T [new_size];
		for(int i=0;i<(*this).size();++i)
		{
			temp[i]=(*this).get(i);
		}
		for(int i=0;i<(*this).size();++i)
		{
			std::cout<<temp[i];
		}
		(*this).set_max_size(new_size);
		T *data_=new T [(*this).max_size()];
		for(int i=0;i<(*this).max_size();++i)
		{
			data_[i]=temp[i];
		}
	}
	else
	{
		(*this).set_size(new_size);
		(*this).set_max_size(new_size);
	}
}

template <typename T>
void Array <T>::shrink(void)
{
	if((*this).size_()<(*this).max_size())
	{
		(*this).set_max_size((*this).size());
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(this==&rhs)
	{
		return true;
	}
	else if((*this).size()!=(rhs).size())
	{
		return false;
	}
	else
	{
		bool equal=true;
		for(int i=0;i<(*this).size();++i)
		{
			if(this.get(i)!=(*rhs).get(i))
			{
				equal=false;
				return false;
			}
			else
			{
				equal=true;
			}
		}
		if(equal==true)
		{
			return true;
		}

	}
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !((*this)==rhs);
}

