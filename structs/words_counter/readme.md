A text of unknown length, but whose rows are limited to ```1000
characters```, is stored in a file.

Write a C application able to evaluate the absolute frequency of all
strings which appear in the file.

```Program has to:```
* Receive on the command line two file names (the input and the output
  file, respectively).
* Read the input file and store all words in a list.
  Each node of the list must contain the string and its absolute
  frequency within the input file.
  Capital and small letters have to be considered as equivalent
  (i.e., "WORD", "Word", and "word" are the same string).
* Store the list into the output file.
