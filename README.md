# Reverse
This repository holds the source code for **reverse** project from OSTEP https://github.com/remzi-arpacidusseau/ostep-projects.

To compile: **make all**

The goal of the reversing program is to read in the data from the specified input file and reverse it; thus, the lines should be printed out in the reverse order of the input stream.

The program can be run with a single command-line argument(user supplies the input file, but the file should be printed to the screen), with two command-line arguments(the program should read from the input file the user supplies and write the reversed version of said file to the output file the user supplies), or without arguments(reversing program should read from **standard input** , which is the input that a user types in, and write to **standard output**).
## Footnotes
The full description of the details of **reverse** program and the set of tests https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-reverse.

If you are going to run tests, please read the instruction: https://github.com/remzi-arpacidusseau/ostep-projects#projects-for-an-operating-systems-class.

***Attention***: there are inconsistencies between the project description and the tests:

1) From description: If the input file and output file are the same file, you should print out an error message: **"Input and output file must differ"**.
Message from test: **"reverse: input and output file must differ"**.

2) From description: If the user specifies an input file or output file, and for some reason, when you try to open said file (e.g., input.txt) and fail, you should print out the following exact error message: **"error: cannot open file input.txt"**. Message from test: **"reverse: cannot open file input.txt"**.
