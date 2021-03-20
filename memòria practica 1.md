a) -

b) -

c) -

d) 

**Jacobi:**

**Gauss-Seidel:**

e) 

**Jacobi:**

**Gauss-Seidel:**

f)

Sense haver d'executar el programa ja podem assegurar que per a ω = -5 i ω = 5 el mètode no convergirà, doncs de teoria tenim el resultat de que per a que SOR convergeixi 0≤ω≤2. Tot i així hem executat el programa per aquests valors i, evidenment, hem vist que no convergeix.

| ω    | Convergència? | Num iteracions |
| ---- | ------------- | -------------- |
| -5   | No            | -              |
| 0.1  |               |                |
| 0.2  |               |                |
| 0.3  |               |                |
| 1    |               |                |
| 1.8  |               |                |
| 1.9  |               |                |
| 5    | No            | -              |

g)

Sense haver d'executar el programa ja podem assegurar que per a ω = -5 i ω = 5 el mètode no convergirà, doncs de teoria tenim el resultat de que per a que SOR convergeixi 0≤ω≤2. Tot i així hem executat el programa per aquests valors i, evidenment, hem vist que no convergeix.

| ω    | Convergència? | Num iteracions |
| ---- | ------------- | -------------- |
| -5   | No            | -              |
| 0.1  |               |                |
| 0.2  |               |                |
| 0.3  |               |                |
| 1    |               |                |
| 1.8  |               |                |
| 1.9  |               |                |
| 5    | No            | -              |

h) Si p(x)=0 llavors la matriu és tridiagonal dominant per files. 

És molt fàcil de veure, recordem la matriu que estem iterant:



![image-20210319223337594](C:\Users\Albert\AppData\Roaming\Typora\typora-user-images\image-20210319223337594.png)

![image-20210319223357513](C:\Users\Albert\AppData\Roaming\Typora\typora-user-images\image-20210319223357513.png)

Amb p(x)=0 tenim que ai=-1/2, ci=-1/2 bi>1, doncs q(x) és l'exponencial, que sempre és positiva diferent de zero i h^2 també ho és. Llavors és directe que bi>ai+ci per tant és tridiagonal dominant per files en sentit estricte. 

De la proposició 1.2.2 dels apunts de JCTatjer, amb aquesta hipòtesi en tenim prou per a concloure la convergència del mètode de Jacobi.

De la proposició 1.2.3 dels apunts de JCTatjer, amb aquesta hipòtesi en tenim prou per a concloure la convergència del mètode de Gauss-Seidel.

