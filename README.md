# Proiect_PA

## Descriere
Acest program este conceput pentru a optimiza distribuția sarcinilor de citire a cărților între trei angajați într-o librărie, asigurându-se că fiecare angajat primește o sarcină de lucru cât mai echilibrată posibil. Utilizatorii au opțiunea de a introduce manual numărul de pagini pentru fiecare carte sau de a genera aceste numere în mod aleatoriu.

## Caracteristici
- **Input Flexibil**: Posibilitatea de a introduce manual numărul de pagini sau de a genera datele aleator.
- **Distribuție Echitabilă**: Algoritmul calculează distribuția optimă a paginilor pentru a minimiza diferența de sarcini între angajați.
- **Interfață Simplă**: Interfața utilizatorului este intuitivă, ghidând utilizatorul prin procesul de configurare și afișând rezultatele clar.

## Cerințe

Pentru a compila și rula acest proiect, veți avea nevoie de:

- Un compilator C (de exemplu, GCC)
- `make` utilitarul pentru a folosi Makefile-ul (opțional, dar recomandat pentru ușurința compilării)

## Instrucțiuni de Compilare

### Utilizând Makefile

1. Asigurați-vă că aveți `make` instalat pe sistemul dvs. Puteți verifica acest lucru rulând:
   ```sh
   make --version

2. Pentru a compila codul, navigați la directorul proiectului și rulați:

make

3. Pentru a curăța fișierele generate (fișierele obiect și executabilul), rulați:
   
make clean

### Compilare Manuală

Dacă nu doriți să utilizați Makefile, puteți compila manual codul utilizând gcc:

Compilați func.c și main.c într-un fișier obiect:

gcc -c func.c -o func.o
gcc -c main.c -o main.o

Linkuiți fișierele obiect pentru a crea executabilul:

gcc func.o main.o -o my_program

## Utilizare

După compilare, puteți rula programul executabil my_program:

./my_program

Programul vă va cere să alegeți una dintre cele două opțiuni:

Generarea unui șir aleatoriu
Introducerea unui șir de la tastatură

Urmați instrucțiunile afișate pentru a introduce lungimea șirului sau șirul dorit.
## Exemplu de Utilizare

Acest exemplu demonstrează cum să rulezi programul pentru a distribui sarcinile de citire a cărților între angajați într-un mod echitabil.

### Pasul 1: Lansarea Programului
Pentru a începe, rulați comanda următoare în terminal:
./distribution

### Pasul 2: Selectarea Modului de Introducere a Datelor
Programul va întreba dacă doriți să introduceți date manual sau să generați date aleatorii:
Choose the input method:

Enter data manually
1.Generate data randomly
2.Enter choice (1-2):
Introduceți `1` pentru date manuale sau `2` pentru date generate aleatoriu și apăsați `Enter`.

### Pasul 3: Introducerea Datelor
Dacă ați ales introducerea manuală, introduceți numărul de cărți și numărul de pagini pentru fiecare carte:
Enter the number of books: 5
Enter the number of pages for each book:
Book 1: 120
Book 2: 150
Book 3: 180
Book 4: 210
Book 5: 240

### Pasul 4: Vizualizarea Rezultatelor
După procesarea datelor, programul va afișa distribuția optimă a paginilor între angajați:
Employee 1: 120 pages: 120
Employee 2: 360 pages: 150 210
Employee 3: 420 pages: 180 240


