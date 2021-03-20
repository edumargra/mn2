# mn2

## Commands

- **To compile:**
`gcc -Wall -ansi -std=c99 -c -pedantic program.c` 
- **To link:**
`gcc program.o -o program.exe -lm`
- **To execute:**
    - For (d):
    `./program.exe 0 6.283185307179586 100 0 0 3000 1e-10 > program100.out`
    - For (e);
    `./program.exe 0 6.283185307179586 1000 0 0 250000 1e-10 > program1000.out`
    - For (f):
    `./program.exe 0 6.283185307179586 1000 0 0 30000 1e-10 'w' > sor30000_'w'.out`
    - For (g):
    `./program.exe 0 6.283185307179586 1000 0 0 300000 1e-10 'w' > sor300000_'w'.out`
where program is the name of the file and 'w' the chosen omega value.

## (h)

Si p(x) = 0, llavors $A = {a_{ij}}$ es simetrica amb tots els elements de la diagonal inferior i superior igual a $-1/2$. Per tant, A es **diagonal dominant per files en sentit estricte** ja que $a_{ii} = 1 + e^x$ amb $x \in {0,2PI}$, per tant, $a_{ii} > 1$, per tant, $\sum_{i,j=1}_{j\neqi}|aij| \seq 1/2 + 1/2 = 1 < a_{ii}$.

Amb la qual cosa, per la proposicio 1.2.2 i 1.2.3, el metode de Jacobi i el de Gauss-Seidel, respectivament, convergeixen.
