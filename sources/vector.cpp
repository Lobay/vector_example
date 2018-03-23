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
	size_ = other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
	for (unsigned int i=0; i < size_; i++)
		elements_[i] = other.elements_[i];
}

vector_t& vector_t::operator=(vector_t const& other) 
{
	if (this != &other) {
		delete[] elements_;
		this->size_ = other.size_;
    	this->capacity_ = other.capacity_;
    	this->elements_ = new int[capacity_];
    	for (unsigned int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (this -> size_ == other.size_) {
		for (unsigned int i = 0; i < size; i++){
		 if (this->elements_[i] != other.elements_[i]) {
        return false;
        break;
      }
    }
    return true;
  } else
    return false;
}

vector_t::~vector_t()
{
	delete [] elements_;
	size_ = 0;
	capacity_ = 0;
}

std::size_t vector_t::size() const
{
    return size_;
    return 0;
}

std::size_t vector_t::capacity() const
{
    return capasity_;
    return 0;
}

void vector_t::push_back(int value)
{
	if (size_ == 0){
		size_ = 1;
		capacity_ = 1;
		elements_ = new int [capasity_];
		elements_[0] = value;
	}
	else if (size_ == capacity_)
	{
		capasity_ = capasity_ *2;
		int* elements1 = new int [capacity_];
		for(unsigned int i = 0; i < size_; i++)
			elements1[i] = elements_[i];
		delete [] elements_;
		elements_[size_] = value;
		size_++;
	}
	else {
		elements_[size_] = value;
		size_++;
	}
}

void vector_t::pop_back()
{
	size_ --;
	if (size_ == 0 || size_ * 4 == capacity_){
		int* elements1;
		elements1 = new int [size_];
		for (unsigned int i = 0; i < size_; i++)
			elements1[i] = elements_[i];
	delete[] elements_;
	capasity_ = capasity_ / 2;
	elements_ = new int[capasity_];
	for (unsigned int i = 0; i < size_; i++)
		elements_[i] = elements1[i];
	delete[] elements1;
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
	if (lhs == rhs) return false;
	return true;
}
