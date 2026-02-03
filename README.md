# ProjectEuler0014
My work on

problem #14 of projecteuler.net:

Longest Collatz Sequence

The following iterative sequence is defined for the set of positive integers:

* $n \to n/2$ ($n$ is even)
* $n \to 3n + 1$ ($n$ is odd)

Using the rule above and starting with $13$, we generate the following sequence:

$$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$

It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.

Which starting number, under one million, produces the longest chain? 

**NOTE:** Once the chain starts the terms are allowed to go above one million.

Completed on Wed, 24 Feb 2021, 22:29

#######################################################################################
Please note: Project Euler's policy allows publication of solutions for the first 100 problems,
that's why I am sharing my work here for reference and educational purposes.
#######################################################################################

The Python solution here is just a brute force, running the sequences and checking their length.
Since it is just basic loops and conditionals, running the code with pypy improves the speed
enormously, it finishes in 0.4 sec. However the traditional python slogs for 25 sec.

And, of course, it is easy to see that running it like that is a huge waste of time.
For example, Collatz($13$) as shown in the text is equal to 10. But Collatz($26$)
would jump to 13 in the first step, however we have to repeat all the steps of Collatz(13)
to get the value that is higher just by 1. 

And in general, it is easy to see that when $n$ is even, then: 

* Collatz($n$) = Collatz($n/2$) + 1.

For the powers of $2$ we can immediately see, that Collatz($2$) = $2$, Collatz($4$) = $3$,
Collatz($8$) = $4$, and so on. 

It seems that matters are also very simple with odd values, because for them $3n + 1$ is even,
and then in the next step we get to the rule for even $n$, so we can write:

* Collatz($n$) = Collatz($(3n+1)/2$) + 2.

This is true, but it does not help us much: while even values lead to smaller $n$, odd ones
can grow up really quickly (in fact I have discovered that they often cross above the max
for int in C++, so the corresponding variables must be declared at least as long). And because
of that the recursive formula for odd values does not offer any advantages.

What I did, in odd cases I propagated the sequence directly, counting steps, if the values were
higher than some reasonable threshold.  

So in C++ version I went the extra mile. I created an old school C-style global array for memoisation,
and cashed values of Collatz(n) when they were first calculated. I also used recursion where possible.

Since the code was intended for Hackerrank, where a number of different limiting numbers were supposed
to be tested, I created an index of all the max values, which would allow to immediately look up
the max sequence for a given limiting number.

As a result, it runs with an excellent time of 100 ms.

Another property I have not used: since Collatz($n$) always larger than Collatz($n/2$),
for every number below $N/2$ (where $N$ is the starting limit, $1000000$ in this case) there
is a counterpart above $N/2$ that is larger at least by 1. So for some algorithms this can
save time by searching only above $N/2$.


