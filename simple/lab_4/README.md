## A. Function ##

```res = mult (x, y);```

to multiply two integer numbers x and y (both >=0), and to return the result
__________________

## B. Function ##
```void d2b (int d, int *b, int *n);```

to convert the decimal number d, into a binary one (stored into the
array b) with n bits
__________________

## C. Function ##
```int catalan (int n);```

to compute and to return the Catalan number of order n

`C_0 = 1     for n=0
and
C_{n} = sum_{i=0}^{i=(n-1)} (C_i * C_{n-1-i})     for n>=1`
__________________

## D. Function ##
```int countSpaces (char *s);```

which counts and returns the number of white-space characters that
appear in a string s
__________________

## E. Function ##
```int isPalindrome (char *s, int l);```

that takes a string s and its length l as arguments and recursively
determines whether the string is palindrome. Returns 1 if the string is palindrome, 0 otherwise
__________________

## F. Function ##
```void triangle (int n, ...);```

that given and integer value n (and any other parameters considered as
necessary) prints-out a triangle containing increasing integer
numbers
__________________

## G. Implement the previous function ##
```void triangle (int n, ...);```

without using any iterative construct, i.e., using recursion
to "move" along both rows and columns of the triangle
