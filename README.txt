Task1:

se citeste de la tastatura instructiune (inst), si se sifteaza de 29 ori + 1 ca sa se obtina primii 3 biti (n).

pentru urmatorii biti facem un loop in for unde in dependenta de codul operatiei (00, 01, 10, 11), se printeaza operatiile +, -, *, /.

pentru ca sa se afle si sa se printeze dim, se shifteaza instructiunea de 29 ori (unde e n-ul), minus marimea operatiilor (n*2), si minus 4 (bitii pentru dim), dupa care se face operatia SI logic cu 1111, apoi se aduna 1.

output-ul va fi in formatul: 

n op1 op2 op3 .. dim

8 / + + * - * / * 2

Task2:

la fel ca in taskul precedent, aflam n-ul dupa ce citim instructiunea de la tastatura prin shiftari de biti.

apoi, introducem intr-un vector bitii unei operatii pe fiecare pozitie i.

aflam prin aceeasi metoda din taskul 1 dim-ul.

folosim formula de pe ocw, o rotunjim la numarul de sus prin ceil si apoi o castam la int pentru ca sa obtinem numarul de numere ce vor fi citite de la tastatura pentru crearea vectorului de operanzi.

in variabila amount pastram marimea unui operand pe biti (1/2/4/8/16). in loop-ul for se parcurg numerele de la tastatura si se introduc in vectorul vecOperanzi. 

In ultimul for se fac operatiile intre primul(i) si al doilea operand (i+1), si prima operatie (i), si se parcurge pana cand i < n.