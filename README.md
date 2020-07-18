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

- La commande `clear` permet de réinitialiser la calculatrice, aussi bien le terminal que la stack utilisée.
- La commande `quit` permet de fermer la calculatrice.
- La commande `help` affiche une aide permettant de lister toutes les commandes disponibles.

## Bonus

Une commande a été rajouté :

- La commande `language` permet de changer la langue d'affichage de la calculatrice (entre français et anglais).

## Language de programmation
Utilisation d'un language de programmation orienté objet, le C++, avec une compilation via un Cmakelist.

## Build
Commande pour lancer la calculatrice : 

`mkdir build; cd build; cmake ..;make ; ./bin/RPN-Calculator`

Le binaire se trouvera dans le dossier `build/bin/`.

## Test Unitaire

Test unitaire rédigé via Gtest (Google Test, étant une bibliothèque de tests unitaires pour le langage de programmation C++).

Si vous souhaitez acceder au test unitaire mise en place, veuillez d'abord installer la librairie Gtest (presente dans le dossier `lib/googletest-master`)

Ainsi que décommenter la derniere ligne du CmakeLists.txt, de la racine.

Installation pour les utilisateurs OS X : 
 - `cd lib/googletest-master `
 - `mkdir install ` (le supprimer si il existe)
 - `cd install `
- `cmake ../`
- `make`
- `sudo make install #installs Google Test`
- `echo "export CPLUS_INCLUDE_PATH=/usr/local/include" >> ~/.bash_profile`
- `echo "export LIBRARY_PATH=/usr/local/lib" >> ~/.bash_profile`
 
 Installation pour les utilisateurs Linux : 
 - `cd lib/googletest-master `
 - `mkdir install ` (le supprimer si il existe)
 - `cd install `
 - `cmake ../`
 - `make`
 - `sudo make install`
 
 
source ~/.bash_profile

Commande pour lancer les tests : 

`mkdir build; cd build; cmake ..; make; ./bin/RPN-Calculator_test`

## Exemples

Les expressions doivent être constituées : d'opérandes ainsi que d'opérateures.

Exemples d’expressions RPN valides :

`Expression RPN` => `Resultat`

20 5 /             => 4

4 2 + 3 -          => 3

3 5 8 * 7 + *      => 141

12 3 - 3 /         => 3

-2 3 11 + 5 - *    => -18

## UML

Class diagram :
![alt text](https://raw.githubusercontent.com/SufyanKerboua/RPN-Calculator/UML/RPN-Calculator_Class_Diagram.png?raw=true)
