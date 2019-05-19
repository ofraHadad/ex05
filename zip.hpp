#pragma once

#include "range.hpp"
#include <string> 
#include <typeinfo>
using namespace std;
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
		
		I1 m_pointer;
		I2 m2_pointer;
		string  p="";

	public:

		iterator(I1 ptr, I2 ptr2)
			: m_pointer(ptr), m2_pointer(ptr2) {
			
			p=toString(*m_pointer)+","+toString(*m2_pointer);
			
		}

		 string operator*() const {
			return p;
		}

	
		iterator<I1,I2>& operator++() {
			++m_pointer;
			++m2_pointer;
		
		
		p=toString(*m_pointer)+","+toString(*m2_pointer);
			return *this;
		}

	
		bool operator!=(const iterator& rhs) const {
			return *m_pointer != *rhs.m_pointer;
		} 
		
	string toString(char a)
	{
		string x(1,a);
		return x;
	}
	
	string toString(string a)
	{
		return a;
	}
	
	string toString(int a)
	{
		//cout <<"int"<<endl;
		return to_string(a);
	}
	
	string toString(double a)
	{
		return to_string(a);
	}
	}; 
	auto begin() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin())>(start.begin(),e.begin());
	}
	
	auto end() const{
		return iterator<decltype(this->start.begin()),decltype(this->e.begin())>(start.end(),e.end());
	}

	
	
	
		
	};
};