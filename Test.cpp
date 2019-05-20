/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		
		cout<< "range test"<<endl;
		int  ansInt[]={5,6,7,8};
		int  ansInt2[]={-100,-99,-98,-97,-96,-95,-94,-93};
		
		int j=0;
		testcase.setname("int input");
		for (int i: range(5,9)){
			
			testcase.CHECK_EQUAL(i==ansInt[j],true);
			j++;
		}
		j=0;
		for (int i: range(-100,-92)){
			
			testcase.CHECK_EQUAL(i==ansInt2[j],true);
			j++;
		}
		
		
		double  ansDouble[]={5.4,6.4,7.4,8.4};
		double  ansDouble2[]={-100.11,-99.11,-98.11,-97.11,-96.11,-95.11,-94.11,-93.11};
		
		 j=0;
		testcase.setname("duoble input");
		for (double i: range(5.4,9.4)){
			
			testcase.CHECK_EQUAL(i==ansDouble[j],true);
			j++;
		}
		j=0;
		for (double i: range(-100.11,-92.11)){
			
			testcase.CHECK_EQUAL(i==ansDouble2[j],true);
			j++;
		}
		
		
		char  ansChar[]={'h','i','j','k','l','m','n','o','p'};
		char  ansString[]={'s','h','i','r','a'};
		
		 j=0;
		testcase.setname("char and string input");
		for (char i: range('h','q')){
			
			testcase.CHECK_EQUAL(i==ansChar[j],true);
			j++;
		}
		j=0;
		for (char i: string("shira")){
			
			testcase.CHECK_EQUAL(i==ansString[j],true);
			j++;
		}
		
		cout<< "chain test"<<endl;
		
		int twoRangesInt[]= {1,2,3,4,5,10,11,12,13};
		int twoRangesInt2[]= {-10,-9,-8,-7,-6,4,5,6,7,8};
		j=0;
		testcase.setname("int ranges");
		for (int i: chain(range(1,6), range(10,14))){
			testcase.CHECK_EQUAL(i==twoRangesInt[j],true);
			j++;   
		}
		
		j=0;
		for (int i: chain(range(-10,-5), range(4,9))){
			
			testcase.CHECK_EQUAL(i==twoRangesInt2[j],true);
			j++;   
		}
		
		
		char twoChars[]= {'a','b','g','h','i'};
		char charString[]= {'c','d','h','e','l'};
		j=0;
		testcase.setname("chars");
		for (char i: chain(range('a','c'), range('g','j'))){
			testcase.CHECK_EQUAL(i==twoChars[j],true);
			j++;   
		}
		
		j=0;
		for (int i: chain(range('c','e'), string("hel"))){
			testcase.CHECK_EQUAL(i==charString[j],true);
			j++;   
		}
		
		
		cout<< "zip test"<<endl;
		
		string twoRanges22[]= {"1,a","2,b","3,c"};
		string twoZip[]= {"1,a,h,w","2,b,e,o","3,c,l,r"};
		string twoChains[]= {"1,a","2,b","3,c","4,g","9,h","10,i","11,j"};
		string zipChain[]= {"1,a,-1","2,b,0","3,c,1","4,d,20", "5,e,21"};
		j=0;
		testcase.setname("zip ranges");
		for (string i: zip(range(1,4), range('a','d'))){
			testcase.CHECK_EQUAL(i==twoRanges22[j],true);
			j++;   
		}
		
		j=0;
		for (string i: zip(zip(range(1,4), range('a','d')), zip(string("hel"),string("wol")))){
			testcase.CHECK_EQUAL(i==twoZip[j],true);
			j++;   
		}
		
		j=0;
		for (string i: zip(chain(range(1,5), range('a','d')),chain(range(9,12), range('g','k')))){
			testcase.CHECK_EQUAL(i==twoChains[j],true);
			j++;   
		}
		
		j=0;
		for (string i: zip(zip(range(1,6), range('a','f')),chain(range(-1,2), range(20,22)))){
			testcase.CHECK_EQUAL(i==twoChains[j],true);
			j++;   
		}
		
		
		
		cout<< "product test"<<endl;
		
		string twoRanges[]= {"1,h",  "1,e",  "1,l",  "1,l",  "1,o",  "2,h",  "2,e",  "2,l",  "2,l",  "2,o" , "3,h" , "3,e",  "3,l",  "3,l",  "3,o"};
		string twoRanges2[]= {"-3.5,o",  "-3.5,f",  "-3.5,r",  "-3.5,a"};
		
		j=0;
		testcase.setname("product ranges");
		for (string i: product(range(1,4), string("hello"))){
			
			testcase.CHECK_EQUAL(i==twoRanges[j],true);
			j++;   
		}
		
		j=0;
		for (string i: product(range(-3.5,-2.5), string("ofra"))){
			testcase.CHECK_EQUAL(i==twoRanges2[j],true);
			j++;   
		}
		
		
		cout<< "powerset test"<<endl;
		
		string chain1[]= {"{}","{a}","{b}","{a,b}","{x}","{a,x}","{b,x}","{a,b,x}","{y}","{a,y}","{b,y}","{a,b,y}","{x,y}","{a,x,y}","{b,x,y}","{a,b,x,y}"};
		string range1[]= {"{}","{1}","{2}","{1,2}","{3}","{1,3}","{2,3}","{1,2,3}"};
		string product1[]={"{}","{s,1.5}","{h,1.5}","{i,1.5}","{r,1.5}","{s,1.5,h,1.5}","{i,1.5,r,1.5}","{s,1.5,i,1.5}","{i,1.5,h,1.5}"
		,"{h,1.5,r,1.5}","{s,1.5,i,1.5,r,1.5}","{s,1.5,i,1.5,h,1.5}","{r,1.5,i,1.5,h,1.5}","{r,1.5,s,1.5,h,1.5}","{r,1.5,s,1.5,h,1.5,i,1.5}"};
		
		
		j=0;
		testcase.setname("product ranges");
		for (string i: powerset(range(1,4))){
			testcase.CHECK_EQUAL(i==range1[j],true);
			j++;   
		}
		
		j=0;
		for (string i: powerset(chain(range('a','c'),range('x','z')))){
			testcase.CHECK_EQUAL(i==chain1[j],true);
			j++;   
		}
		
		j=0;
		for (string i: powerset(product(string("shir"),range(1,2)))){
			testcase.CHECK_EQUAL(i==chain1[j],true);
			j++;   
		}
		
		
		
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}