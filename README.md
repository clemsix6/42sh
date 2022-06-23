# 42Sh

### Introduction

Le 42sh est un des trois projets finalistes de l'année. Il est dans la continuité du Minishell1 et Minishell2. Il intègre des fonctionnalités plus avancées encore.



### Fonctionnalités

* Gestion des espaces ET des tabs
* Gestion de la variable $PATH et de l'environement
* Gestion des erreurs des commandes et des valeurs de retour
* Gestion des opérateurs de redirection
* Gestion des pipes
* Gestion des fonctions intégrés ("cd", "echo", "exit", "setenv", "unsetenv")
* Gestion des séparateurs

Le 42sh est donc capable de fonctionner avec des commandes complexes comme ci-dessous:

```bash
 cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo “OK”
```



#### Optionnel

Le projet implémente également des fonctionnalités optionnelles comme:

* L'opérateur inhibiteurs ("\\")
* Les opérateurs d'englobement ("\*", "?", "\[", "]")
* La gestion des tâches ("&", fg)
* Les parenthèses pour ajouter des priorités d'execution
* Les variables locales et env
* Alias



### Utilisation

Le 42sh s'utilise comme la plupart des autres shells avec des fonctionnalités tout aussi avancés. En partant des commandes les plus simples comme un "cat" jusqu'aux commandes complexes qui demande l'utilisation de variable d'environement ou encore des pipes tout est possible. Une gestion d'erreurs assure une parfaite stabilité du programme.

#### Exemple

```
$> error_test
error_test: Command not found.
$> ls
include  lib  Makefile  mysh  README.md  src  SUMMARY.md
$> cat SUMMARY.md
# Table of contents

* [Minishell2](README.md)
$> 
```
