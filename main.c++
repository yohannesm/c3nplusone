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
int v;

int maxLength(int n){
int ctr = 1;
while(n!=1){
   if(n%2==0){
	n = n/2; ctr++;	}
else{
n = 3*n+1; ctr++;
}
	}
return ctr;
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
int maxCycleLength = 0;
for(int a = i; a<=j; a++){
maxCycleLength  = maxLength(a);
if(maxCycleLength >v) v = maxCycleLength;
}
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
	/*cin >> i >> j;
eval();
cout << v << endl;
cout << maxLength(3);*/
    ios_base::sync_with_stdio(false);     // turn off synchronization with C I/O

    #ifdef TEST
        using namespace CppUnit;
        TextTestRunner tr;
        tr.addTest(TestCollatz::suite());
        tr.run();
    #else
        while (read(cin)) {
            eval();
            print(cout);}
    #endif // TEST

    return 0;}



