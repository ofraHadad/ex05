#pragma once

#include "range.hpp"
namespace itertools{
		template<typename T >	
	
	class powerset{
		
		public:
		T start;
		
		 

		powerset(T x):start(x){}
		
		
		template<typename I1>
		class iterator {

	  private:
		//range::iterator start.iterator();
		I1 m_pointer;
		
		string * p;

	public:

		iterator(I1 ptr)
			: m_pointer(ptr) {
		}

		 string& operator*() const {
			return *p;
		}

		string* operator->() const {
			return p;
		}

		// ++i;
		iterator<I1>& operator++() {
		//	m_pointer++;
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
		return iterator<decltype(this->start.begin())>(start.begin());
	}
	
	auto end() const{
		return iterator<decltype(this->start.begin())>(start.begin());
	}	
		
	};
}