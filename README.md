# ProjectEuler0014
My work on

problem #14 of projecteuler.net:

Longest Collatz Sequence

The following iterative sequence is defined for the set of positive integers:

* $n \to n/2$ ($n$ is even)
* $n \to 3n + 1$ ($n$ is odd)

Using the rule above and starting with $13$, we generate the following sequence:

$$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$

It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.

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

And in general, it is easy to see that when $n$ is even, then Collatz($n$) = Collatz($n/2$) + 1.
For the powers of $2$ we can immediately see, that Collatz($2$) = $2$, Collatz($4$) = $3$,
Collatz($8$) = $4$, and so on. 
