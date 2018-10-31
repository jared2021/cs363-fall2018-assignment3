//Honor Pledge:
//
//I pledge that I have neither given nor received any help
//on this assignment.

template <typename T>
Array_Base <T>::Array_Base (void)
:data_(new T[max_size_]),
 cur_size_(0),
 max_size_(10)
{

}

template <typename T>
Array_Base <T>::Array_Base (size_t length)
:data_(new T[length]),
 cur_size_(0),
 max_size_(length)
{

}

template <typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
:data_(new T[length]),
 cur_size_(length),
 max_size_(length)
{
	for(int i=0;i<cur_size_;++i)
	{
		data_[i]=fill;
	}
}

template <typename T>
Array_Base <T>::Array_Base(const Array_Base & array_base)
:data_(new T[max_size_]),
 cur_size_((array_base).size()),
 max_size_((array_base).max_size())
{
	for(int i=0;i<cur_size_;++i)
	{
		data_[i]=(array_base).data_[i];
	}
}

template <typename T>
Array_Base <T>::~Array_Base(void)
{
	delete data_;
}

template <typename T>
size_t Array_Base<T>::size(void)const
{
	return cur_size_;
}

template <typename T>
void Array_Base<T>::set_size (size_t n)
{
	cur_size_=n;
}

template <typename T>
size_t Array_Base<T>::max_size(void)const
{
	return max_size_;
}

template <typename T>
void Array_Base<T>::set_max_size(size_t n)
{
	max_size_=n;
}

template <typename T>
T & Array_Base<T>::get (size_t index)
{
	if(index>max_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return data_[index];
	}
}

template <typename T>
T & Array_Base<T>::data (size_t index) const
{
	if(index>max_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		return data_[index];
	}
}

template <typename T>
T Array_Base<T>::set (size_t index, T value)
{
	if(index>max_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		data_[index]=value;
	}
}

template <typename T>
int Array_Base<T>::find (T element)const
{
	bool found=false;
	int i=0;
	while(i<cur_size_)
	{
		if(data_[i]==element)
		{
			return i;
			found=true;
			i=cur_size_;
		}
		else
		{
			i=i+i;
		}
	}
	if(!found)
	{
		return -1;
	}
}

template <typename T>
int Array_Base<T>::find (T element, size_t start)const
{
	if(start>cur_size_)
	{
		throw std::out_of_range("That index is bigger than the array itself.");
	}
	else
	{
		bool found=false;
		int i=start;
		while(i<cur_size_)
		{
			if(data_[i]==element)
			{
				found=true;
				return i;
				i=cur_size_;

			}
			else
			{
				i=i+1;
			}
		}
		if(!found)
		{
			return -1;
		}
	}
}

template <typename T>
void Array_Base<T>::fill (T value)
{
	for(int i=0;i<max_size_;++i)
	{
		data_[i]=value;
		cur_size_=max_size_;
	}
}
