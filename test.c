/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:48:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/11 15:57:35 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include "includes/ft_printf.h"

// 1º TEST
/*
int main(void)
{
    char *str = "Hola, mundo";
    int num = 42;
    void *ptr = &num;

    // Prueba 1: %s (string)
    printf("Original: %s\n", str);
    ft_printf("Propio:   %s\n", str);

    // Prueba 2: %p (puntero)
    printf("Original: %p\n", ptr);
    ft_printf("Propio:   %p\n", ptr);

    // Prueba 3: %d (entero decimal)
    printf("Original: %d\n", num);
    ft_printf("Propio:   %d\n", num);

    // Prueba 4: %% (porcentaje)
    printf("Original: %%\n");
    ft_printf("Propio:   %%\n");

    return 0;
}
*/

// 2º TEST : 
/*
int main(void)
{
    char *str1 = "Hola, mundo";
    char *str2 = "¡Bienvenidos a 42!";
    int num = 42;

    // Prueba 1: Múltiples %s en un solo printf
    ft_printf("Strings: %s, %s\n", str1, str2);

    // Prueba 2: Múltiples %d en un solo printf
    ft_printf("Numeros: %d, %d, %d\n", num, num + 1, num + 2);

    // Prueba 3: Combinación de %s y %d
    ft_printf("Texto y numeros: %s, %d, %s\n", str1, num, str2);

    return 0;
}
*/

// 3ª TEST:
/*
int main(void)
{
    // Prueba con %i
    printf("Original (printf) con %%i: %i, %i\n", 42, -42);
    ft_printf("Propio (ft_printf) con %%i: %i, %i\n", 42, -42);

    // Prueba con %o (octal)
    printf("Original (printf) con %%o: %o\n", 42);
    ft_printf("Propio (ft_printf) con %%o: %o\n", 42);

    // Prueba con %u (entero sin signo)
    printf("Original (printf) con %%u: %u\n", 42);
    ft_printf("Propio (ft_printf) con %%u: %u\n", 42);

    // Prueba con %u (número negativo como sin signo)
    printf("Original (printf) con %%u (número negativo): %u\n", -42);  // Debería imprimir 4294967254
    ft_printf("Propio (ft_printf) con %%u (número negativo): %u\n", -42);

    // Prueba con %x (hexadecimal en minúsculas)
    printf("Original (printf) con %%x: %x\n", 42);  // Debería imprimir 2a
    ft_printf("Propio (ft_printf) con %%x: %x\n", 42);

    // Prueba con %X (hexadecimal en mayúsculas)
    printf("Original (printf) con %%X: %X\n", 42);  // Debería imprimir 2A
    ft_printf("Propio (ft_printf) con %%X: %X\n", 42);

    // Prueba con %c (carácter)
    printf("Original (printf) con %%c: %c\n", 'A');  // Debería imprimir A
    ft_printf("Propio (ft_printf) con %%c: %c\n", 'A');
    printf("Original (printf) con %%c: %c\n", 65);  // Debería imprimir A
    ft_printf("Propio (ft_printf) con %%c: %c\n", 65);  // 65 es el valor ASCII de 'A'

    return 0;
}
*/

// 4º TEST: 
/*
#include <stdio.h>
#include "./includes/ft_printf.h"

int main(void)
{
    char c = 'A';
    int i = 42;
    char *str = "Hola, mundo";
    unsigned int u = 123456;

    // Prueba 1: char seguido de int
    printf("Prueba 1: char seguido de int: %c, %d\n", c, i);
    ft_printf("Prueba 1: char seguido de int: %c, %d\n", c, i);
    printf("*****\n");

    // Prueba 2: int seguido de char
    printf("Prueba 2: int seguido de char: %d, %c\n", i, c);
    ft_printf("Prueba 2: int seguido de char: %d, %c\n", i, c);
    printf("*****\n");

    // Prueba 3: int seguido de string
    printf("Prueba 3: int seguido de string: %d, %s\n", i, str);
    ft_printf("Prueba 3: int seguido de string: %d, %s\n", i, str);
    printf("*****\n");

    // Prueba 4: string seguido de int
    printf("Prueba 4: string seguido de int: %s, %d\n", str, i);
    ft_printf("Prueba 4: string seguido de int: %s, %d\n", str, i);
    printf("*****\n");

    // Prueba 5: unsigned int seguido de string
    printf("Prueba 5: unsigned int seguido de string: %u, %s\n", u, str);
    ft_printf("Prueba 5: unsigned int seguido de string: %u, %s\n", u, str);
    printf("*****\n");

    // Prueba 6: hexadecimal seguido de char
    printf("Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
    ft_printf("Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
    printf("*****\n");

    // Prueba 7: múltiples parámetros de diferentes tipos
    printf("Prueba 7: múltiplos parámetros de diferentes tipos: %c, %d, %s, %x\n", c, i, str, u);
    ft_printf("Prueba 7: múltiplos parámetros de diferentes tipos: %c, %d, %s, %x\n", c, i, str, u);
    printf("*****\n");

    return 0;
}


//Test 5º:
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"  // Asumiendo que tienes un ft_printf.h para la función ft_printf

int main(void)
{
    // Inicializamos las variables para las pruebas
    int num = 42;             // Un número entero para las pruebas
    unsigned int u_num = 42;  // Un número entero sin signo para las pruebas
    unsigned int u_neg = 4294967254; // Un número negativo en formato unsigned

    //1. Prueba con la bandera #
    printf("Prueba 1.1: Original con %%#x: %x\n", u_num);
    ft_printf("Prueba 1.1: Propio con %%#x: %x\n", u_num);
    printf("\n");

    printf("Prueba 1.2: Original con %%#X: %X\n", u_num);
    ft_printf("Prueba 1.2: Propio con %%#X: %X\n", u_num);
    printf("\n");
    
    
    // 2. Prueba con la bandera 0
    printf("Prueba 2.1: Original con %%0d: %0d\n", num);
    ft_printf("Prueba 2.1: Propio con %%0d: %0d\n", num);
    printf("\n");
    
    // 3. Prueba con la bandera -
    printf("Prueba 3.1: Original con %%-5d: %-5d\n", num);
    ft_printf("Prueba 3.1: Propio con %%-5d: %-5d\n", num);
    printf("\n");

    //4. Prueba con la bandera +
    printf("Prueba 4.1: Original con %%+d: %+d\n", num);
    ft_printf("Prueba 4.1: Propio con %%+d: %+d\n", num);
    printf("\n");
    
    // 5. Prueba con la bandera espacio
    printf("Prueba 5.1: Original con %% d: % d\n", num);
    ft_printf("Prueba 5.1: Propio con %% d: % d\n", num);
    printf("\n");
    
    // 6. Ancho de campo
    printf("Prueba 6.1: Original con %%10d: %10d\n", num);
    ft_printf("Prueba 6.1: Propio con %%10d: %10d\n", num);
    printf("\n");

    // 7. Prueba con la variable u_neg
    printf("Prueba 7.1: Original con %%u (unsigned int grande): %u\n", u_neg);
    ft_printf("Prueba 7.1: Propio con %%u (unsigned int grande): %u\n", u_neg);
    printf("\n");
    
    // 8. Ancho de campo con ceros
    printf("Prueba 8.1: Original con %%05d: %05d\n", num);
    ft_printf("Prueba 8.1: Propio con %%05d: %05d\n", num);
    printf("\n");

    // 9. Prueba con número octal con bandera #
    printf("Prueba 9.1: Original con %%#o: %#o\n", u_num);
    ft_printf("Prueba 9.1: Propio con %%#o: %#o\n", u_num);
    printf("\n");

    // 10. Número en hexadecimal con ceros
    printf("Prueba 10.1: Original con %%010x: %010x\n", u_num);
    ft_printf("Prueba 10.1: Propio con %%010x: %010x\n", u_num);
    printf("\n");
   
    return 0;
}
*/