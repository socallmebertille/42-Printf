# Ft_printf

Because printf() was too mainstream.

## Step 1 : understand the subject

L'objectif de ce projet est de recréer une version simplifiée de la fonction `printf()` de la librairie standard en C. Cette fonction permet d'afficher du texte formaté en gérant plusieurs types de conversions (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`). Il est important de noter aussi que la fonction `printf()` retourne un int qui correspond au nombre de caractere qui est affiche.

Le challenge principal est de manipuler les arguments de façon dynamique tout en gérant les spécificateurs de format et l'affichage.

## Step 2 : argument managment

Pour interpréter les arguments passés à `ft_printf()`, on utilise `va_list`, une structure permettant de récupérer un nombre variable d'arguments.

### Step 2.1 : initialisation

Avant toute récupération des arguments, on initialise notre liste avec :

```c
va_list args;
va_start(args, format);
```

### Step 2.2 : retrieval and display

On parcourt la chaîne de format et, à chaque `%`, on détermine le type de conversion à appliquer :

| Spécificateur | Signification              |
| ------------- | -------------------------- |
| `%c`          | Caractère                  |
| `%s`          | Chaîne de caractères       |
| `%p`          | Pointeur                   |
| `%d` ou `%i`  | Nombre entier (base 10)    |
| `%u`          | Nombre non signé (base 10) |
| `%x`          | Hexadécimal minuscule      |
| `%X`          | Hexadécimal majuscule      |
| `%%`          | Affichage du caractère `%` |

Pour chaque spécificateur, on récupère la valeur correspondante avec `va_arg()` et on l'affiche avec la bonne conversion.

Une fois l'affichage terminé, on termine la gestion des arguments avec `va_end(args);`.

## Step 3 : implementation of conversions

Chaque conversion doit être gérée séparément. Une bonne approche est de créer une fonction pour chaque type de conversion :

- `int	ft_putchar(char c)`
- `int	ft_putstr(char *str)`
- `int	ft_print_ptr(char *base, void *ptr, size_t len)`
- `int	ft_putnbr(int nbr)`
- `int	ft_putnbr_base(char *base, int nbr, int len)`
- etc.

Ces fonctions doivent afficher la valeur et retourner le nombre de caractères affichés afin de pouvoir compter correctement la sortie de `ft_printf()`.

## Step 4 : mise en forme du code

Globalement, une fois ces fonctions centrales implementees, on ptu se retrouver avec quelque chose comme :

| Spécificateur | Corresponding function     |
| ------------- | -------------------------- |
| `%c`          | `ft_putchar(va_arg(args, int)` |
| `%s`          | `ft_putstr(va_arg(args, char *)` |
| `%p`          | `ft_print_ptr(HEX_BASE_MIN, va_arg(args, void *), 16)` |
| `%d` ou `%i`  | `ft_putnbr(va_arg(args, int)` |
| `%u`          | `ft_putnbr_base(DEC_BASE, va_arg(args, int), 10)` |
| `%x`          | `ft_putnbr_base(HEX_BASE_MIN, va_arg(args, int), 16)` |
| `%X`          | `ft_putnbr_base(HEX_BASE_MAJ, va_arg(args, int), 16)` |
| `%%`          | `ft_putchar('%')` |


