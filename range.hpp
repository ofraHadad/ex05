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
	
		
		
	public:
		T current;
	

		iterator(T c)
			: current(c) {
				
			
		}
		
		T operator*() const{
			
		
			return current;
		}


		iterator& operator++() {
			

				current++;

		
			return *this;
		}

	bool operator==(const iterator& rhs) const {
			
			return current< rhs.current+1 && current> rhs.current-1;
		} 

		bool operator!=(const iterator& rhs) const {
			
			return current>= rhs.current+1 || current<= rhs.current-1;
		} 
	}; 
	iterator begin() const{
		return iterator(start);
	}
	
	iterator end() const{
		return iterator(e);
	}	
	};
};