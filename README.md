# Démineur
Flambard Audrey, Mareschal Guillaume

## 1. Qu'est ce qu'un démineur ?

Le Démineur est un jeu vidéo de réflexion dont le but est de localiser des mines cachées dans une grille représentant un champ de mines virtuel, avec pour seule indication le nombre de mines dans les zones adjacentes.

Pour ce projet en C++ nous devions créer le champ de mines du Démineur représenté par une grille.

## 2. Les étapes du projet

 - Dans un premier temps il faut créer un vecteur 2D avec les lignes et colonnes données par l'utilisateur,
 - Ensuite, nous allons créer des bombes aléatoires,
 - Après cela, il faut ajouter les chiffres autour des bombes,
 - Pour finir, il faudra afficher le plateau dans l'invite de commandes.

 ## 3. Minesweeper.h
 
 ![image](https://user-images.githubusercontent.com/70451979/118103318-1286d200-b3da-11eb-9804-420b2fb3a192.png)

Nous avons créé notre classe principale et les prototypes des méthodes. Maintenant nous allons passer aux méthodes dans Minesweeper.cpp

## 4. Minesweeper.cpp

### 1. Constructeur et destructeur
![image](https://user-images.githubusercontent.com/70451979/118103817-a193ea00-b3da-11eb-8ef4-2eb8c6545782.png)

Nous avons déclaré les constructeurs pour notre classe et initialisé les variables privées avec les valeurs données par l'utilisateur. Après ça, nous allons demander au programme d'exécuter les méthodes ci-dessous dans l'ordre.

### 2. Create_table
![image](https://user-images.githubusercontent.com/70451979/118104232-28e15d80-b3db-11eb-8491-3c47dfc5b681.png)

Maintenant il faut ajouter des bombes aléatoires.

### 3. Add_bombs
![image](https://user-images.githubusercontent.com/70451979/118104644-ae650d80-b3db-11eb-9329-6194aba4a8b0.png)

On crée un vecteur d'entiers qui a la même taille que le plateau. Imaginons que la taille est de 20 lignes * 10 colonnes = 200. Alors notre vecteur devrait ressembler à : [1, 2, 3, 4 ... 200]. <br/>
Après il faut mélanger ce vecteur avec la fonction shuffle. On amorce la fonction shuffle avec le système clock. Après le mélange imaginons que le vecteur est : [20, 32, 50, 120, 153 ... 1, 12] <br/>
Maintenant, imaginons que l'utilisateur a besoin de 3 bombes. Alors on prend les 3 premières valeurs du vecteur, qui sont ici [20, 32, 50]. Donc nous avons des bombes aux carrés numéro 20, 32 et 50.

### 4. Find_column/find_row
![image](https://user-images.githubusercontent.com/70451979/118107656-53cdb080-b3df-11eb-901f-4e95f8ce8901.png)

Nous devons d'abord trouver la colonne sinon nous ne pouvons pas trouver la ligne. <br/>
La formule find_column est le reste de (square/total_column). Mais si le carré est égal à total_column qui donnera l'output 0, alors nous définissons la colonne sur total_column. <br/>
La formule find_row est [(square-column)/total_column]+1

### 5. Add_numbers

![image](https://user-images.githubusercontent.com/70451979/118108882-d1de8700-b3e0-11eb-8a3a-7c7a23a13f73.png)
![image](https://user-images.githubusercontent.com/70451979/118110732-13703180-b3e3-11eb-8566-37a36195ec51.png)


Ici nous parcourons chacune des bombes dans le vecteur des bombes. Ensuite, nous calculons la ligne et la colonne de la bombe. Après cela, nous ajoutons +1 aux voisins de la bombe si le voisin n'est pas hors limites. 

### 6. Show_table
![image](https://user-images.githubusercontent.com/70451979/118109691-cfc8f800-b3e1-11eb-8ed0-5d87317d545f.png)

Dans cette méthode nous affichons le vecteur dans l'invite de commande en vérifiant si le carré est une bombre, un chiffre ou vide. Ensuite, nous affichons les emmplacements des bombes. <br/>
Maintenant nous sommes prêts à exécuter le programme avec main.cpp.

## Main.cpp
![image](https://user-images.githubusercontent.com/70451979/118110012-2f270800-b3e2-11eb-9be1-54359dea8ac6.png)

Nous faisons une boucle infinie avec 5 secondes de sleep time pour voir à chaque fois de nouveaux plateaux aléatoires.
