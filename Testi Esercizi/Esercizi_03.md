# Esercizio 15: Classe Rational

Si implementi la classe `Rational` che consenta di rappresentare dei numeri razionali (es. 1/3, 3/4, ecc.). La classe deve avere le seguenti caratteristiche:

## Costruzione e Normalizzazione

- Deve essere possibile costruire un oggetto `Rational` specificando:
  - Solo il numeratore (numero intero);
  - Entrambi i valori (numeratore e denominatore);
- Quando viene costruito un oggetto `Rational`, il numero deve essere automaticamente normalizzato;
- Il segno deve essere sempre incluso solo nel numeratore;
- Se il costruttore viene invocato con denominatore `0`, il programma genera un'eccezione.

**Esempio:** Se venisse chiamato il costruttore `Rational r{24, -12}`, questo dovrebbe memorizzare il numero normalizzato `{-2, 1}`.

## Operatore di Output (`<<`)

Si implementi l'operatore di inserimento su stream (`<<`) per consentire la stampa di un numero razionale su `std::cout`, file o altri stream di output.

**Regole di formattazione:**
- Se il denominatore è 1, emettere solo il valore del numeratore (es. `5` anziché `5/1`)
- Altrimenti, visualizzare nel formato `<numeratore>/<denominatore>` (es. `3/4`, `-2/3`)

**Esempi di output:**
```cpp
Rational r1(5, 1);    // Output: 5
Rational r2(3, 4);    // Output: 3/4  
Rational r3(-7, 2);   // Output: -7/2
std::cout << r1 << " " << r2 << " " << r3;  // Output: 5 3/4 -7/2
```

**Implementazione:**
L'operatore deve essere implementato come funzione `friend` non-membro per permettere l'uso con stream diversi e la concatenazione. 


## Operazioni Aritmetiche

- **Addizione:**
  ```cpp
  Rational risultato = r1 + r2;
  r1 += r2;  // somma in-place
  ```

- **Sottrazione:**
  ```cpp
  Rational risultato = r1 - r2;
  r1 -= r2;  // sottrazione in-place
  ```

- **Moltiplicazione:**
  ```cpp
  Rational risultato = r1 * r2;
  r1 *= r2;  // moltiplicazione in-place
  ```

- **Divisione:**
  ```cpp
  Rational risultato = r1 / r2;
  r1 /= r2;  // divisione in-place
  ```

- **Operatori unari:**
  ```cpp
  Rational negativo = -r1;  // negazione
  Rational positivo = +r1;  // identità
  ```

## Operatori di Confronto

- Uguaglianza tra numeri razionali:
  ```cpp
  if (r1 == r2) { /* ... */ }
  ```
- Confronto tra numero intero e numero razionale:
  ```cpp
  if (1 == r2) { /* ... */ }
  if (r2 == 1) { /* ... */ }
  ```
- Confronti completi con numeri razionali e interi: `>`, `<`, `!=`, `<=`, `>=`

## Input/Output da File

- Deve essere possibile scrivere e leggere numeri razionali da file
- La lettura deve funzionare anche per i numeri interi
- Vedere il file `rational_numbers.txt` come esempio di formato

## Utilizzo con Contenitori STL

- Deve essere possibile definire una `unordered_map<Rational, int>`
- Esempio d'uso: contare quante volte un numero razionale compare in un vettore