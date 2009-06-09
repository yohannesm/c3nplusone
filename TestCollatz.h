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
        i =  1;
        j = 10;
        v = 20;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "100 200 125\n");}

    void test_print2 () {
        i =  1;
        j = 10;
        v = 20;
        std::ostringstream out;
        print(out);
        CPPUNIT_ASSERT(out.str() == "201 210 89\n");}

    void test_print3 () {
        i =  1;
        j = 10;
        v = 20;
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
    CPPUNIT_TEST(test_eval1);
    CPPUNIT_TEST(test_eval2);
    CPPUNIT_TEST(test_eval3);
    CPPUNIT_TEST(test_eval4);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST_SUITE_END();};

#endif // TestCollatz_h
