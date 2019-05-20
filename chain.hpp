#pragma once

#include "range.hpp"
#include<type_traits>
#include <iostream>
#include <sstream>

namespace itertools{
		template<typename T,typename T2 >	
	
	class chain{
		
		public:
		T start;
		T2 e;
		 

		chain(T x,T2 y):start(x),e(y){}
		
		
		template<typename I1, typename I2>
		class iterator {

	  private:
	
		I1 m_pointer;
		I2 m2_pointer;
		bool flag= true;
		

	public:

		iterator(I1 ptr, I2 ptr2)
			: m_pointer(ptr), m2_pointer(ptr2){				
		}
		
				
		

		 decltype(*m_pointer) operator*() const {
			if(flag)
				return *m_pointer;
			return *m2_pointer;
		}

		iterator<I1,I2>& operator++() {
			
			if(flag)
				++m_pointer;
			else
				++m2_pointer;
			return *this;
		}

		
		bool operator==(const iterator& rhs)  {
			
			return m_pointer == rhs.m_pointer && m2_pointer == rhs.m2_pointer;
		} 

	
		bool operator!=(const iterator& rhs)  {
			if(flag && rhs.m_pointer== m_pointer)
			{
				flag = false;
				
			}
			 if(!flag)
				return m2_pointer!= rhs.m2_pointer;
			else
				return m_pointer != rhs.m_pointer;
		} 
	}; 
	auto begin() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin())>(start.begin(),e.begin());
	}
	
	auto end() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.end())>(start.end(), e.end());
	}	
		
	};
};