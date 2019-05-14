#pragma once

namespace itertools{
	  template<typename T>
	class range{
		
		public:
		//template<typename T>
		T start;
		T e;
		range(T x, T y){start=x; e=y;}
		range(range &x){start=x.start; e=x.e;}
		
		
		class iterator {

	  private:
	
		
		T* m_pointer= &current;

	public:
		T current;
		T last;
		iterator(T c, T e)
			: current(c),last(e) {
											//cout<< *m_pointer <<"ffff"<<endl;

			
		}
		iterator(T* ptr=nullptr)
		:m_pointer(ptr){}

		T operator*() const{
			

			return current;
		}

		T* operator->() const {
			return current;
		}

		// ++i;
		iterator& operator++() {
			if(current==last-1)
			{
				m_pointer=nullptr;
			}
			else{

				current++;

			}
			return *this;
		}

		bool operator==(const iterator& rhs) const {
			return m_pointer == rhs.m_pointer;
		}

		bool operator!=(const iterator& rhs) const {
			return m_pointer != rhs.m_pointer;
		} 
	}; 
	iterator begin() const{
		return iterator(start,e);
	}
	
	iterator end() const{
		return iterator(nullptr);
	}	
	};
};