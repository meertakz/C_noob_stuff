Assume that a text file contains a list of alphabetical strings of maximum 20 characters each,

separated by either spaces or newlines (no punctuations). The total number of the strings is not known.
______________
`
int textStats(char* filename)
`
______________
Write a function that receives the name of the input file and prints on the screen the following:

- The occurrence of words of each possible length (1 character, 2 characters, ... 20 characters)
- The percentage of strings that have all capital letters
______________
The function should return to the caller the total number of strings in the text file.
______________
Example:

Content of the file: 

`
viVa la VIDA loca
`
______________
Output of the function:

```
1 string/s with length 2

3 string/s with length 4

25.00% with all capital letters Value returned by the function: 4
```
