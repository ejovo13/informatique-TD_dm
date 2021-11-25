### Permutations

L'idée c'est d'avoir une fonction récursif qui execute une boucle for qui itère tout au long
du tableau pour choisir un premier élément. Prenons {1, 2 3}

On considere deux permutations se forme avec premier élélement 1:
1 2 3
1 3 2
===== 1 perm({2, 3})

Ou les deux derieres éléments de l'itération s'exprime en termes des permutations de {2, 3}, ce qui est le tableau originale sans le premier élément.

De meme avec le deuxieme élément, 2:
2 1 3
2 3 1
===== 2 perm{1, 3}

3 1 2
3 2 1
===== 3 perm({1, 2})

D'ou vient la première boucle dans le code, et l'execution récursif de `print_perm`.

Cette logique est solide. Considérons le `output` de cet algorithme sans le partie nommé "black magic":
```
1 2 3
3 2

2 1 3
3 1

3 1 3
2 1
```

Conceptuellement, le programme marche, mais on peut l'améliorer pour que ca deviennet plus lisible
pour l'humain. On change les paramètres pour accepter le tableau originale afin de pouvoir mettre un "1" dans la deuxieme ligne de l'exemple precédent. Il faut une certaine manière de savoir le tableau appelé dans les itérations précedents, du coup on passe le tableau originale et encore un entier pour transmettre plus des infos. On aurait pu utilisé des variables globaux ou autrement mais j'ai choisi de tout simplement augmenter le nombre de parametres.

Apres tester plusiers combinaisons (muni avec un peu de reflexxion) j'ai finis par trouver celui de la magie noire.
