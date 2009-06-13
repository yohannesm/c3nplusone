// -------------------------------
// projects/c++/3n+1/TestCollatz.h
// Copyright (C) 2009
// Glenn P. Downing
// -------------------------------

#ifndef TestCollatz_h
#define TestCollatz_h

// --------
// includes
// --------

#include <sstream> // istringtstream, ostringstream
#include <string>  // ==

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END

using namespace CppUnit;

// -----------
// TestCollatz
// -----------

struct TestCollatz : TestFixture {
    // ----
    // read
    // ----

    void test_read () {
        std::istringstream in("1 10\n");
        bool b = read(in);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}
    void test_read1 () {
        std::istringstream in("1 100\n");
        bool b = read(in);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   100);}
    void test_read2 () {
        std::istringstream in("201 210\n");
        bool b = read(in);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    201);
        CPPUNIT_ASSERT(j ==   210);}
    void test_read3 () {
        std::istringstream in("5 999\n");
        bool b = read(in);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    5);
        CPPUNIT_ASSERT(j ==   999);}


    
// ----
    // CycleLength
    // ----

    void test_maxLength1 () {
        int res = 6;
        int act = CycleLength(5);
        CPPUNIT_ASSERT(res ==  act);}
   void test_maxLength2 () {
        int res = 16;
        int act =CycleLength(22);
        CPPUNIT_ASSERT(res ==  act);}
 void test_maxLength3 () {
        int res = 20;
        int act = CycleLength(9);
        CPPUNIT_ASSERT(res ==  act);}
 void test_maxLength4 () {
        int res = 17;
        int act = CycleLength(7);
        CPPUNIT_ASSERT(res ==  act);}

    // CycleLength
    // ----

    void test_maxLengthW1 () {
        int res = 6;
        int act = CycleLengthwithCache(5);
        CPPUNIT_ASSERT(res ==  act);}
   void test_maxLengthW2 () {
        int res = 16;
        int act = CycleLengthwithCache(22);
        CPPUNIT_ASSERT(res ==  act);}
 void test_maxLengthW3 () {
        int res = 20;
        int act = CycleLengthwithCache(9);
        CPPUNIT_ASSERT(res ==  act);}
 void test_maxLengthW4 () {
        int res = 17;
        int act = CycleLengthwithCache(7);
        CPPUNIT_ASSERT(res ==  act);}
void test_maxLengthW5 () {
        int res = 50;
        int act = CycleLengthwithCache(999);
        CPPUNIT_ASSERT(res ==  act);}

    // ----
    // eval
    // ----
    
    void test_eval1 () {
        i =  1;
        j = 10;
        v =  0;
        eval();
        CPPUNIT_ASSERT(v == 20);}

    void test_eval2 () {
        i = 100;
        j = 200;
        v =   0;
        eval();
        CPPUNIT_ASSERT(v == 125);}

    void test_eval3 () {
        i = 201;
        j = 210;
        v =   0;
        eval();
        CPPUNIT_ASSERT(v == 89);}

    void test_eval4 () {
        i =  900;
        j = 1000;
        v =    0;
        eval();
        CPPUNIT_ASSERT(v == 174);}

    void test_eval5 () {
        i =  200;
        j = 20000;
        v =    0;
        eval();
        CPPUNIT_ASSERT(v == 279);}

    void test_eval6 () {
        i = 1;
        j = 1;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 1);}

    void test_eval7 () {
        i = 123;
        j = 12345;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 268);}

    void test_eval8 () {
        i = 999;
        j = 1000;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 112);}

    void test_eval9 () {
        i = 784;
        j = 1899;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 182);}

    void test_eval10 () {
        i = 468;
        j = 79833;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 351);}

    void test_eval11 () {
        i = 10000;
        j = 10001;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 180);}

    void test_eval12 () {
        i = 100000;
        j = 100001;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 129);}

    void test_eval13 () {
        i = 99999;
        j = 99999;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 227);}

    void test_eval14 () {
        i = 999999;
        j = 999999;
        v = 0;
        eval();
        CPPUNIT_ASSERT(v == 259);}




    // -----
    // print
    // -----

    void test_print () {
        i =  1;
        j = 10;
        v = 20;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "1 10 20\n");}

    void test_print1 () {
        i =  100;
        j = 200;
        v = 125;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "100 200 125\n");}

    void test_print2 () {
        i =  201;
        j = 210;
        v = 89;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "201 210 89\n");}

    void test_print3 () {
        i =  900;
        j = 1000;
        v = 174;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "900 1000 174\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read1);
    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_maxLength1);
    CPPUNIT_TEST(test_maxLength2);
    CPPUNIT_TEST(test_maxLength3);
    CPPUNIT_TEST(test_maxLength4);
    CPPUNIT_TEST(test_maxLengthW1);
    CPPUNIT_TEST(test_maxLengthW2);
    CPPUNIT_TEST(test_maxLengthW3);
    CPPUNIT_TEST(test_maxLengthW4);
    CPPUNIT_TEST(test_maxLengthW5);
    CPPUNIT_TEST(test_eval1);
    CPPUNIT_TEST(test_eval2);
    CPPUNIT_TEST(test_eval3);
    CPPUNIT_TEST(test_eval4);
    CPPUNIT_TEST(test_eval5);
    CPPUNIT_TEST(test_eval6);
    CPPUNIT_TEST(test_eval7);
    CPPUNIT_TEST(test_eval8);
    CPPUNIT_TEST(test_eval9);
    CPPUNIT_TEST(test_eval10);
    CPPUNIT_TEST(test_eval11);
    CPPUNIT_TEST(test_eval12);
    CPPUNIT_TEST(test_eval13);
    CPPUNIT_TEST(test_eval14);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST_SUITE_END();};

#endif // TestCollatz_h
