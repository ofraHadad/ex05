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
		
		
		template<typename I1, typename I2, typename C>
		class iterator {

	  private:
	
		I1 m_pointer;
		I2 m2_pointer;
		I1 m_end;
		I2 m2_end;
		int x;
		C current;
		 
		
		int* pointer= &x;
		bool flag=true;
		

	public:

		iterator(I1 ptr, I2 ptr2, C c, I1 pend, I2 p2end)
			: m_pointer(ptr), m2_pointer(ptr2),current(c), m_end(pend), m2_end(p2end) {				
		}
			iterator(int* ptr,C c)
		:pointer(ptr),current(c){
		}
				
		

		 C operator*()  {
			return current;
		}

		I1* operator->()  {
			return current;
		}

		// ++i;
		iterator<I1,I2,C>& operator++() {
			
			if(++m_pointer!=m_end&& current!= *m_pointer){
				const C temp = *m_pointer;
				
				current= temp;
				
			}
			else if(flag){
				current= *m2_pointer;
				flag= false;
			}
			
			else if(++m2_pointer!=m2_end && current!=*m2_pointer){
			
				
				current= *m2_pointer;
				
			}
			else{
			
				pointer= nullptr;
			
			}
			return *this;
		}

		

		bool operator==(const iterator& rhs) const {
			return pointer == rhs.pointer;
		}

		bool operator!=(const iterator& rhs) const {
			return pointer != rhs.pointer;
		} 
	}; 
	auto begin() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin()),typename std::remove_const<decltype(*(start.begin()))>::type >(start.begin(),e.begin(),*(start.begin()),start.end(),e.end());
	}
	
	auto end() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.end()),typename std::remove_const<decltype(*(start.begin()))>::type >(nullptr,*(start.begin()));
	}	
		
	};
};