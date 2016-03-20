In this part, you will implement a hash table containing integers. The hash table has 10,000 buckets. An important part of a hash table 
is collision resolution. In this assignment, we want you to use chaining with a linked list to handle a collision. This means that if 
there is a collision at a particular bucket then you will maintain a linked list of all values stored at that bucket. More information 
about chaining can be found at http://research.cs.vt.edu/AVresearch/hashing/ openhash.php.
For this problem, you have to use following hash function: key modulo the number of buckets.
Input format: This program takes a file name as argument from the command line. The file is either blank or contains successive lines of 
input. Each line contains a character, either ‘i’ or ‘s’, followed by a tab and then an integer, the same format as in the Second Part. 
For each of the lines that starts with ‘i’, your program should insert that number in the hash table if it is not present. If the line 
starts with a ‘s’, your program should search the hash table for that value.
Output format: For each line in the input file, your program should print the status/result of that operation. For an insert, the program
should print “inserted” if the value is inserted or “duplicate” if the value is already present. For a search, the program should print
”present” or “absent” based on the outcome of the search. Your program should print “error” (and nothing else) if the file does not exist.
The program should also print “error” for input lines with improper structure.
Example Execution:
Lets assume we have 2 text files with the following contents: “file1.txt” is empty
file2.txt:
i 10
i 12
s 10
c5
i 10
s 5 The the results will be:
$./third file1.txt
$./third file2.txt
inserted
inserted
present
error
duplicate
absent
$./third file3.txt
error
