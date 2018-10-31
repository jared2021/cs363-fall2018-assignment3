//Honor Pledge:
//
//I pledge that I have neither given nor received any help
//on this assignment.

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>
#include <stdexcept>

// COMMENT Do not place implementation code directly in the header file.
// RESPONSE Removed implementation from header file and placed it in a seperate C++ file.

template<typename T>
class Array_Base
{
public:
	Array_Base(void);

	Array_Base(size_t length);

	Array_Base(size_t length, T fill);

	Array_Base(const Array_Base & array_base);

	virtual ~Array_Base(void);
  
	size_t size (void) const;

  	void set_size (size_t n);

  	size_t max_size (void) const;

  	void set_max_size (size_t n);
	
	T & get (size_t index);

	T & data (size_t index) const;

	T set (size_t index, T value);
	
	int find (T element)const;

	int find (T element, size_t start)const;
	
	void fill (T value);


protected:
  T* data_;

  size_t cur_size_;

  size_t max_size_;
};

#include "Array_Base.cpp"
#include "Array_Base.inl"

#endif
