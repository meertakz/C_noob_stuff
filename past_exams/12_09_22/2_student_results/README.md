In a C program, the following struct is used to represent a student of the last Programming Techniques exam:
____________________________________
`
typedef struct {char matricola[7]; char name[30]; int score;} student;
`
____________________________________
A text file, whose name is passed as first argument from command line, contains records of a maximum of 100

students, in no specific order. Each line reports matricola, name and exam score (integer value between 0 and 30)

of a student, with spaces as separators. Assume that the matricola is a 6 digits number and the name does not

contain any spaces.

Consider the following fragment of code:
____________________________________
```

int main (int argc, char *argv[]) 
{

student listStudents[100], *selStudents[100];

int i, n = readStudents(listStudents, 100, argv[1]);

int threshold = 18;

int nSuff = selectStudents(listStudents, n, selStudents, threshold); printResults(selStudents,nSuff,argv[2]);

... // rest of the program (omitted)

return 0;

}

```
____________________________________
1) The function readStudents (omitted) reads the input file and stores the data of all the students that took the exam into the array listStudents, returning the number of read students to the caller.
2) The function selectStudents selects the students that obtained a score higher or equal to the threshold (in this case, 18). The pointers to the selected students are stored in the array selStudents, and the total number of selected students is returned to the caller.
3) The function printResults prints the results of the exam on an output file, whose name is passed as the second argument from the command line. The function prints the scores obtained by the selected students, one student per line, in the anonymized form: <identification_code> <score>. The identification code of a student is obtained by adding the value 100 to the original matricola number. (For example: matricola 123456 should become 123556).
____________________________________
  
You are required to implement only the functions selectStudents and printResults. The prototypes of the functions must be compatible with the corresponding function calls in the given code.
