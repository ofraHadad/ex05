#pragma once

#include "range.hpp"
namespace itertools{
		template<typename T,typename T2 >	
	
	class zip{
		
		public:
		T start;
		T2 e;
		 

		zip(T x,T2 y):start(x),e(y){}
		
		
		template<typename I1, typename I2>
		class iterator {

	  private:
		//range::iterator start.iterator();
		I1 m_pointer;
		I2 m2_pointer;
		string * p;

	public:

		iterator(I1 ptr, I2 ptr2)
			: m_pointer(ptr), m2_pointer(ptr2) {
		}

		 string& operator*() const {
			return *p;
		}

		string* operator->() const {
			return p;
		}

		// ++i;
		iterator<I1,I2>& operator++() {
			//m_pointer++;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
		//	m_pointer= m_pointer->m_next;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return m_pointer == rhs.m_pointer;
		}

		bool operator!=(const iterator& rhs) const {
			return m_pointer != rhs.m_pointer;
		} 
	}; 
	auto begin() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin())>(start.begin(),e.begin());
	}
	
	auto end() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin())>(start.begin(),e.begin());
	}	
		
	};
};