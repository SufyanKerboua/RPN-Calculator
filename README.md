# RPN-Calculator
Création d'une calculatrice RPN (Reverse Polish Notation – Notation Polonaise Inverse).

## Objectif

Développer une application en mode console permettant d’évaluer des expressions.

Les expressions seront saisies par l’utilisateur au prompt de l’application et seront évaluées lors de l’appui de la touche <Entrée>.

Le prompt de l’application sera représenté ainsi :
`RPN Calculator >`

La calculatrice prendra en charge quatre opérations de base :

`+` : ajouter

`-` : soustraire

`*` : multiplier

`/` : diviser

La calculatrice prendra en charge quelques commandes spéciales :

- La commande `clear` permettra de réinitialiser la calculatrice.
- La commande `quit` permettra de quitter la calculatrice.
- La commande `help` affichera une aide en ligne de la liste des commandes disponibles.

## Language de programmation
Utilisation d'un language de programmation orienté objet, le C++, avec une compilation via un Cmakelist.

## Build
Commande pour lancer la calculatrice : 

`mkdir build; cd build; make ..; ./bin/RPN-Calculator`

## Test Unitaire
Test unitaire rédigé via Gtest (Google Test, étant une bibliothèque de tests unitaires pour le langage de programmation C++).

Installation pour les utilisateurs OS X : 
- `cd googletest `
- `mkdir install `
- `cd install `
- `cmake ../`
- `make`
- `sudo make install #installs Google Test`
- `echo "export CPLUS_INCLUDE_PATH=/usr/local/include" >> ~/.bash_profile`
- `echo "export LIBRARY_PATH=/usr/local/lib" >> ~/.bash_profile`
 
source ~/.bash_profile

## Exemples

Les expressions doivent être constituées : d'opérandes ainsi que d'opérateures.

Exemples d’expressions RPN valides :

`Expression RPN` => `Resultat`

20 5 / => 4

4 2 + 3 - => 3

12 3 - 3 / => 3

-2 3 11 + 5 - * => -18