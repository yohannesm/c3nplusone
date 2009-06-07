<html>
<head>
  <title>TestCollatz.h</title>
</head>
<body bgcolor="#ffffff" text="#000000">
<pre>
<font color="#444444">// -------------------------------</font>
<font color="#444444">// projects/c++/3n+1/TestCollatz.h</font>
<font color="#444444">// Copyright (C) 2009</font>
<font color="#444444">// Glenn P. Downing</font>
<font color="#444444">// -------------------------------</font>

<font color="0000ff"><strong>#ifndef TestCollatz_h</strong></font>
<font color="0000ff"><strong>#define TestCollatz_h</strong></font>

<font color="#444444">// --------</font>
<font color="#444444">// includes</font>
<font color="#444444">// --------</font>

<font color="0000ff"><strong>#include <font color="#008000">&lt;sstream&gt;</font> <font color="#444444">// istringtstream, ostringstream</font></strong></font>
<font color="0000ff"><strong>#include <font color="#008000">&lt;string&gt;</font>  <font color="#444444">// ==</font></strong></font>

<font color="0000ff"><strong>#include <font color="#008000">&quot;cppunit/TestFixture.h&quot;</font>             <font color="#444444">// TestFixture</font></strong></font>
<font color="0000ff"><strong>#include <font color="#008000">&quot;cppunit/extensions/HelperMacros.h&quot;</font> <font color="#444444">// CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END</font></strong></font>

<strong>using</strong> <strong>namespace</strong> <font color="#2040a0">CppUnit</font><font color="4444FF">;</font>

<font color="#444444">// -----------</font>
<font color="#444444">// TestCollatz</font>
<font color="#444444">// -----------</font>

<strong>struct</strong> <font color="#2040a0">TestCollatz</font> <font color="4444FF">:</font> <font color="#2040a0">TestFixture</font> <font color="4444FF"><strong>{</strong></font>
    <font color="#444444">// ----</font>
    <font color="#444444">// read</font>
    <font color="#444444">// ----</font>

    <strong>void</strong> <font color="#2040a0">test_read</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">istringstream</font> <font color="#2040a0">in</font><font color="4444FF">(</font><font color="#008000">&quot;1 10<font color="#77dd77">\n</font>&quot;</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <strong>bool</strong> <font color="#2040a0">b</font> <font color="4444FF">=</font> <font color="#2040a0">read</font><font color="4444FF">(</font><font color="#2040a0">in</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">b</font> <font color="4444FF">=</font><font color="4444FF">=</font> <strong>true</strong><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">i</font> <font color="4444FF">=</font><font color="4444FF">=</font>    <font color="#FF0000">1</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">j</font> <font color="4444FF">=</font><font color="4444FF">=</font>   <font color="#FF0000">10</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <font color="#444444">// ----</font>
    <font color="#444444">// eval</font>
    <font color="#444444">// ----</font>

    <strong>void</strong> <font color="#2040a0">test_eval1</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">i</font> <font color="4444FF">=</font>  <font color="#FF0000">1</font><font color="4444FF">;</font>
        <font color="#2040a0">j</font> <font color="4444FF">=</font> <font color="#FF0000">10</font><font color="4444FF">;</font>
        <font color="#2040a0">v</font> <font color="4444FF">=</font>  <font color="#FF0000">0</font><font color="4444FF">;</font>
        <font color="#2040a0">eval</font><font color="4444FF">(</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">v</font> <font color="4444FF">=</font><font color="4444FF">=</font> <font color="#FF0000">20</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <strong>void</strong> <font color="#2040a0">test_eval2</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">i</font> <font color="4444FF">=</font> <font color="#FF0000">100</font><font color="4444FF">;</font>
        <font color="#2040a0">j</font> <font color="4444FF">=</font> <font color="#FF0000">200</font><font color="4444FF">;</font>
        <font color="#2040a0">v</font> <font color="4444FF">=</font>   <font color="#FF0000">0</font><font color="4444FF">;</font>
        <font color="#2040a0">eval</font><font color="4444FF">(</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">v</font> <font color="4444FF">=</font><font color="4444FF">=</font> <font color="#FF0000">125</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <strong>void</strong> <font color="#2040a0">test_eval3</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">i</font> <font color="4444FF">=</font> <font color="#FF0000">201</font><font color="4444FF">;</font>
        <font color="#2040a0">j</font> <font color="4444FF">=</font> <font color="#FF0000">210</font><font color="4444FF">;</font>
        <font color="#2040a0">v</font> <font color="4444FF">=</font>   <font color="#FF0000">0</font><font color="4444FF">;</font>
        <font color="#2040a0">eval</font><font color="4444FF">(</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">v</font> <font color="4444FF">=</font><font color="4444FF">=</font> <font color="#FF0000">89</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <strong>void</strong> <font color="#2040a0">test_eval4</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">i</font> <font color="4444FF">=</font>  <font color="#FF0000">900</font><font color="4444FF">;</font>
        <font color="#2040a0">j</font> <font color="4444FF">=</font> <font color="#FF0000">1000</font><font color="4444FF">;</font>
        <font color="#2040a0">v</font> <font color="4444FF">=</font>    <font color="#FF0000">0</font><font color="4444FF">;</font>
        <font color="#2040a0">eval</font><font color="4444FF">(</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">v</font> <font color="4444FF">=</font><font color="4444FF">=</font> <font color="#FF0000">174</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <font color="#444444">// -----</font>
    <font color="#444444">// print</font>
    <font color="#444444">// -----</font>

    <strong>void</strong> <font color="#2040a0">test_print</font> <font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF"><strong>{</strong></font>
        <font color="#2040a0">i</font> <font color="4444FF">=</font>  <font color="#FF0000">1</font><font color="4444FF">;</font>
        <font color="#2040a0">j</font> <font color="4444FF">=</font> <font color="#FF0000">10</font><font color="4444FF">;</font>
        <font color="#2040a0">v</font> <font color="4444FF">=</font> <font color="#FF0000">20</font><font color="4444FF">;</font>
        <font color="#2040a0">std</font><font color="4444FF">:</font><font color="4444FF">:</font><font color="#2040a0">ostringstream</font> <font color="#2040a0">out</font><font color="4444FF">;</font>
        <font color="#2040a0">print</font><font color="4444FF">(</font><font color="#2040a0">out</font><font color="4444FF">)</font><font color="4444FF">;</font>
        <font color="#2040a0">CPPUNIT_ASSERT</font><font color="4444FF">(</font><font color="#2040a0">out</font>.<font color="#2040a0">str</font><font color="4444FF">(</font><font color="4444FF">)</font> <font color="4444FF">=</font><font color="4444FF">=</font> <font color="#008000">&quot;1 10 20<font color="#77dd77">\n</font>&quot;</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font>

    <font color="#444444">// -----</font>
    <font color="#444444">// suite</font>
    <font color="#444444">// -----</font>

    <font color="#2040a0">CPPUNIT_TEST_SUITE</font><font color="4444FF">(</font><font color="#2040a0">TestCollatz</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_read</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_eval1</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_eval2</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_eval3</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_eval4</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST</font><font color="4444FF">(</font><font color="#2040a0">test_print</font><font color="4444FF">)</font><font color="4444FF">;</font>
    <font color="#2040a0">CPPUNIT_TEST_SUITE_END</font><font color="4444FF">(</font><font color="4444FF">)</font><font color="4444FF">;</font><font color="4444FF"><strong>}</strong></font><font color="4444FF">;</font>

<font color="0000ff"><strong>#endif <font color="#444444">// TestCollatz_h</font></strong></font>

</pre>
<hr>
syntax highlighted by <a href="http://www.palfrader.org/code2html">Code2HTML</a>, v. 0.9.1
</body>
</html>
