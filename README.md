# mn2

## Commands

- **To compile:**
`gcc -Wall -ansi -std=c99 -c -pedantic program.c` 
- **To link:**
`gcc program.o -o program.exe -lm`
- **To execute with an output file:**
    - For (d):
    `./program.exe 0 6.283185307179586 100 0 0 3000 1e-10 > program100.out`
    - For (e);
    `./program.exe 0 6.283185307179586 1000 0 0 250000 1e-10 > program1000.out`
    - For (f):
    `./program.exe 0 6.283185307179586 100 0 0 30000 1e-10 'w' > sor30000_'w'.out`
    - For (g):
    `./program.exe 0 6.283185307179586 1000 0 0 300000 1e-10 'w' > sor300000_'w'.out`
where program is the name of the file and 'w' the chosen omega value.

### alternative:

If you have installed the cmake utility, you can compile the programs with:
- ```mkdir executables ; cd executables``` - create a specific directory for your executables and navigate to it
- ```cmake ../``` -create auxilary files
- ```cmake --build .``` -compile

Then you can execute as explained above.
