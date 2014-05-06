#RNG

This program is a random number generator that uses the random number generation algorithm
"Real Version 2" from the paper ["Random Numbers: Good Ones are Hard to Find"](http://www.cems.uwe.ac.uk/~irjohnso/coursenotes/ufeen8-15-m/p1192-parkmiller.pdf) by Park and Miller.
The "Real Version 2" algorithm in the paper on page 3 is presented in Pascal code. In essence this
program is the C++ version of "Real Version 2" algorithm written originally in Pascal.

##System manual
To produce random numbers, first, the program needs a seed. Function `randomize()` intializes a seed. If no arguments are passed to `randomize()` the seed is set to the clock time of the system. After the seed is initialized one can run `my_rand_0_1()` which will produce a random number between zero and 1. Function `my_rand_int()` produces a random integer between 1 and 16807. Example of producing k random numbers is in the main program code block. The output looks like this:
```
Random numbers          Random integers between
between 0 and 1         1 and MY_RAND_MAX

0.264                    15075
0.819                    12154
0.935                     2505
0.500                     9577
0.476                      390
0.913                    14732
0.885                    12680
0.784                    11123
0.621                    15655
0.867                     2432
0.392                    12738
```

The code works in XCode and Microsoft Visual Studio.
