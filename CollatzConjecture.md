This article describes a possible approach to solving the Collatz conjecture for numbers between 1 to 1000000.

## Introduction ##

Collatz conjecture is an unsolvable problem posed by L. Collatz in 1937 (http://mathworld.wolfram.com/CollatzProblem.html). However, the problem is known to terminate for all integers n such that n is an integer between 1 and 1000000 (http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36).
For a given input of i and j, the objective of the problem is to determine the maximum cycle length for numbers between i and j (including i and j).


## Algorithm to determine the cycle length ##

For a given input n, determine whether n is even or odd. If n is even, divide n by 2 and if n is odd,  n = 3\*n+1. Continue this process until n is one.

For example, consider the cycle length computation of 5.

5,
5\*3 + 1 = 16,
16/2 = 8,
8/2 = 4,
4/2 = 2,
2/2 = 1

Hence, the cycle length of 5 is 6.

## Implementation ##
In order to optimize the algorithm, we used shifting for division and multiplication. When checking for odd or even number, we used the bitwise AND operator to check if the least significant bit was a 1 or a 0 instead of a modulus operation.

We used a global non-static array of size 65001 as an eager cache to compute the cycle lengths of numbers from 1 to 65000. This cache was used to assist the computation of cycle lengths of higher numbers.