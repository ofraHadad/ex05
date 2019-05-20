#pragma once

#include "range.hpp"
#include <string> 
#include <typeinfo>
using namespace std;
namespace itertools{
		template<typename T,typename T2 >	
	
	class product{
		
		public:
		T start;
		T2 e;
		 

		product(T x,T2 y):start(x),e(y){}
		
		
		template<typename I1, typename I2>
		class iterator {

	  private:
		//range::iterator start.iterator();
		I1 m_pointer;
		I2 m2_pointer;
		I2 temp;
		bool flag= true;
		string  p;
		bool first=true;
	public:

		iterator(I1 ptr, I2 ptr2)
			: m_pointer(ptr), m2_pointer(ptr2), temp(ptr2) {
				//temp= m2_pointer;
				//p= toString(*m_pointer)+","+toString(*temp);
		}

		 string operator*() const {
			return p;
		}

		
		iterator<I1,I2>& operator++() {
			
			if(!flag)
				++m_pointer;
			
			p=toString(*m_pointer)+","+toString(*temp);
		    ++temp;
			return *this;
		}

		

		
		bool operator!=(const iterator& rhs) {
			
			if((*temp== *rhs.m2_pointer)||(*temp< *rhs.m2_pointer+1 && *temp > *rhs.m2_pointer-1))
			{
				flag=false;
				temp = m2_pointer;
				//p= toString(*m_pointer)+","+toString(*temp);
			}
			return (m_pointer != rhs.m_pointer) /*|| (*m_pointer>= *rhs.m_pointer+1 || *m_pointer<= *rhs.m_pointer-1)*/;
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