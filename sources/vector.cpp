#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
    		
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (elements_ != nullptr){
		delete [] elements_;
	}
	
	elements_ = new int [other.capacity_];
    	for (std::size_t i = 0; i < other.capacity_; i++) {
        	elements_[i] = other.elements_[i];
    	}
	size_ = other.size_;
 	capacity_ = other.capacity_;
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ != other.size_){
		return false;		
	}
	else 
	{
		for (std::size_t i = 0; i < other.capacity_; i++){
			if (elements_[i] != other.elements_[i]){
			return false;
			}
		}
		return true;
	}
}

vector_t::~vector_t()
{
	if (elements_ != nullptr){
		delete[] elements_;
	}
	
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (elements_ == nullptr){
		size_++;
		capacity_++;
		elements_ = new int [capacity];
		elements_[size-1] = value;
	}else
	{
		size_++;
		if (size_ > capacity_){
			capacity_ *= 2;
			int * elements = new int elements[size_];
			for (std::size_t i = 0; i < size_ - 1; i++){
				elements[i] = elements_[i];
			}
			elements[size-1] = value;
			delete[] elements_;
			int * elements_ = new int elements_[capacity_];
			for (std::size_t i = 0; i < size_; i++){
				elements_[i] = elements_i];
			}
		}else elements_[size-1] = value;
	}
}

void vector_t::pop_back()
{
	if (elements_ == nullptr){
		return;
	}else
	{
		size_--;
		if (size_ <= capacity_/4){
			capacity_ /= 2;
		}
		
		int * elements = new int elements[size_];
		for (std::size_t i = 0; i < size_; i++){
			elements[i] = elements_[i];
		}
		delete[] elements_;
		int * elements_ = new int elements_[capacity_];
		for (std::size_t i = 0; i < size_; i++){
			elements_[i] = elements_i];
		}
	 
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs.size_ == rhs.size_){
		return false;		
	}
	else 
	{
		for (std::size_t i = 0; i < rhs.capacity_; i++){
			if (lhs.elements_[i] == rhs.elements_[i]){
			return false;
			}
		}
		return true;
	}
}
