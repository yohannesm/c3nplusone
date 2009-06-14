// --------------------------
// projects/c++/3n+1/main.c++
// Copyright (C) 2009
// Glenn P. Downing
// --------------------------

// To run the tests:
//     g++ -ansi -pedantic -lcppunit -ldl -Wall -DTEST main.c++ -o main.app
//     valgrind main.app

// To run the program:
//     g++ -ansi -pedantic -Wall main.c++ -o main.app
//     valgrind main.app < main.in > main.out

// To configure Doxygen:
//     doxygen -g
// That creates the file Doxyfile.
// Make the following edits:
//     EXTRACT_ALL            = YES
//     EXTRACT_PRIVATE        = YES
//     EXTRACT_STATIC         = YES
//     GENERATE_LATEX         = NO

// To document the program:
//     doxygen Doxyfile

#include <cassert>  // assert
#include <iostream> // cin, cout, endl, ios_base, istream, ostream

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

/**
 * input: don't change after reading
 */
int i;

/**
 * input: don't change after reading
 */
int j;

/**
 * output
 */
unsigned int v;

/**
 * cache : Intially stores the cycle lengths of integers between 1 and 10000. If values exceed 10000, then compute the cycle length and replace the least recetly used value in cache 
value of 1 maps to cache[0] so it will be off by one
generally the value of n maps to cache[n-1]
 */

/**
 * Length of the cache
 */
const unsigned int LENGTH_CACHE = 100001;

/**
 * An array used to store previously computed values of cyclelength from 1 to 65000 
 */
unsigned int cache[LENGTH_CACHE];


/**
* Prints the values in cache. This method was used to assist in debugging.
*/

void printCache() {
for(unsigned int val = 1; val < LENGTH_CACHE; val++)
    std::cout << "i= " << val << " maxL= " << cache[val] << " " << std::endl;
}


/**
 * Cyclelength function
 *computes the  length of the number N for 3n+1 problem
 *@param int n  
 *@return Cycle length of the integer n computed without a cache
 */
int CycleLength(unsigned int n){
assert(n>=1);
unsigned int ctr = 1;
while(n!=1){
  if((n&1)==0){
	n = (n >> 1); ctr++;}
else{
n = n + (n >> 1) + 1; ++++ctr;
}
	}
assert(ctr>=1);
return ctr;
}

/**
 * Cyclelength function
 *computes the  length of the number N for 3n+1 problem
 aided with a cache for faster computation
 *@param int n  
 *@return Cycle length of the integer n computed with the assistance of a cache  
 *@exception if n is greater than max_int then throw n
 */
int CycleLengthwithCache(unsigned int n){
if (n >= 2147483647) {
throw n; 
}
assert(n>=1);
unsigned int ctr = 1;
if(n < LENGTH_CACHE && n>0){    
    return cache[n];}
while(n!=1){
if(n < LENGTH_CACHE && n>0){	
     return ctr += (cache[n] - 1);}
  else if((n&1)==0){
	n = (n >> 1); ctr++;	}
else{
n = n + (n >> 1) + 1; ++++ctr;

}
	}
assert(ctr>=1);
return ctr;
}

/**
 * compute the values for the cache. 
 */
void computeCacheValues() {

for(unsigned int ind = 1; ind < LENGTH_CACHE; ind++){
    cache[ind] = CycleLength(ind); 
}

}
/**
 * reads an int into i and j
 * @return true if that succeeds, false otherwise
 */

bool read (std::istream& in) {
    if (!(in >> i))
        return false;
    in >> j;
    return true;}

/**
 * computes the max cycle length in the range [i, j]
 * and stores the result in v
 */
void eval () {

  v = 0;
unsigned int maxCycleLength = 0;

if(i<=j){
	for(int a = i; a<=j; a++){	
			maxCycleLength  = CycleLengthwithCache(a);
			if(maxCycleLength > v) v = maxCycleLength;
		}
	}
else{
	for(int a = j; a<=i; a++){		
		maxCycleLength  = CycleLengthwithCache(a);
		if(maxCycleLength > v) v = maxCycleLength;
		}
	}



assert(v>0);

}
/**
 * prints the values of i, j, and v
 */
void print (std::ostream& out) {
    out << i << " " << j << " " << v << std::endl;}

#ifdef TEST
    #include "cppunit/TestSuite.h"      // TestSuite
    #include "cppunit/TextTestRunner.h" // TestRunner

    #include "TestCollatz.h"
#endif // TEST

/**
 * either runs the tests or runs the program
 */
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);     // turn off synchronization with C I/O
    #ifdef TEST
        using namespace CppUnit;
	computeCacheValues();
        TextTestRunner tr;
        tr.addTest(TestCollatz::suite());
        tr.run();
    #else	
	computeCacheValues();	
        while (read(cin)) {
	    try{
            eval();
	    }
 	    catch (const int& e){
		std::cerr << "n exceeds the maximum value of int " << e << endl;
	}
	  
            print(cout);}

    #endif // TEST

		
    return 0;}



