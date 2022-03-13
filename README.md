# Working with File Input and Output
## (10 pts) Design & Implementation
In this lab, you will read and write to a file, as well as searching the information. Copy and paste the following into a file named "inputs.txt":

```
7
1 Bulbasaur Grass
4 Charmander Fire
7 Squirtle Water
25 Pikachu Electric
37 Vulpix Fire
54 Psyduck Water
133 Eevee Normal
```

The input file provides details for a Pokemon database in the following format:

```
Number_of_Pokemon 
Dex_Number Pokemon_Name Pokemon_Type
 …<repeats n number of times>… 
Dex_Number Pokemon_Name Pokemon_Type 
```

Your program will read specific information from the file and continue reading the contents of the body from the file until the EOF (end of file) character. You will write the following information to an output file:

- Search Pokemon by dex number
- Search Pokemon by type

Each section of information should be labeled in the output file in all capital letters. The Pokedex and Pokemon classes should be used to store and manipulate the file information between reading and writing the file. You must include the following three functions with the exact prototypes:

```
Pokedex::Pokedex(fstream &); //Read in the number of Pokemon and dynamically allocate memory for them

Pokedex::~Pokedex(); //Delete memory dynamically allocated for array of Pokemon

void Pokedex::get_pokemon_info(fstream &); //Read in Pokemon data from file into array

void Pokedex::search_by_dex_number(int); //Look through Pokemon array for one that matches the number passed in. If found, print to file. If not found, display an error message.

void Pokedex::search_by_type(string); //Look through Pokemon array for ones that match the type passed in. If found, print to file. If not found, display an error message.
```

Your main function needs to check to make sure the file you open exists before moving forward. If the file doesn’t exist, then you need to provide an error message and prompt the user to enter a file name that does exist.

fstream documentation: http://www.cplusplus.com/reference/fstream/fstream/ (Links to an external site.)

Implement the driver.cpp, pokemon.cpp/h, and pokedex.cpp/h files. Use the ones from last week's lab as the starting point. Create a Makefile to manage the compilation of all these files. You can adapt the Makefile below.

## (5 pts) Makefiles 
What if we had 1,000 implementation (.cpp) files? Manually compiling all of them together would take forever and have a high chance for error. Luckily, UNIX/Linux has a built in script that makes compiling multiple files together easy called a Makefile. Just type

```
vim Makefile
```

on the command line to create it. Now modify the file following the pattern shown below:

```
<target>:
     <compiler> <file1.cpp> <file2.cpp> -o <target>
```

Note that the leading whitespace MUST be a tab (you can't just use spaces). An example of what this could look like for this lab would be:

```
pokedex:
     g++ pokedex.cpp pokemon.cpp driver.cpp -o pokedex
```

Save and exit the file. You can type "make" in the terminal to run it.

One of the other benefits of makefiles is that you can add variables to it and make compiling happen in different stages by stopping g++ after compiling and before running it through the linker. This creates object files (.o files), which you can link together

```
CC = g++
exe_file = pokedex
$(exe_file): pokedex.o pokemon.o driver.o
     $(CC) pokedex.o pokemon.o driver.o -o $(exe_file)
pokedex.o: pokedex.cpp
     $(CC) -c pokedex.cpp
pokemon.o: pokemon.cpp
     $(CC) -c pokemon.cpp
driver.o: driver.cpp
     $(CC) -c driver.cpp
```

Try to make your program again. Notice all the stages. In addition, we usually add a target for cleaning up our directory:

```
clean:
     rm –f *.out *.o $(exe_file)
```

Now we can run the specific target by typing  "make <target>.

```
make clean
```

Makefiles are a useful way to automate and control the program building process as your projects grow in size.

## (5 pts) TAR Files
When you begin to have projects with multiple files, it becomes useful to have a way to group them together for uploading, emailing, or archiving. TAR files (also known as tarballs) are classic way to do this on Linux machines, and are what you will use for programming assignment submissions.

To create a tar file, use the tar command. There are multiple options that can be added, with examples and explanations at the reference material below. The ones included in the example below are -c, -v, and -f.

```
tar –cvf tarfile_name.tar file1 file2 ... filen
```
  
The -c option is used to create the tar file. The -f option is used to specify which tar file to use, followed by the filename (ending in .tar) that you specify. The -v option stands for "verbose", and prints the files being added to the tar file to the terminal as the tar command executes.

After the command, options, and chosen .tar filename, you must include all of the files that you want to be added, separated by a space.

To extract the files from a tarball, you can use the following command, where the -x option stands for "extract":

```
tar –xvf tarfile_name.tar
```

Prove to the TA that you can make a tarball with multiple files, and then extract the files from it. Make sure that when creating the tarball you specify the .tar filename, and to extract the files into a different directory than the original.

TAR Command Examples reference: https://www.rootusers.com/23-tar-command-examples-for-linux/
