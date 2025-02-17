#include <stdio.h>
#include "./includes/ft_printf.h"

int main(void)
{
    // 1º TEST
    char *str = "Hola, mundo";
    int num = 42;
    void *ptr = &num;
    printf("*****1ºTEST:*****\n");

    printf("Prueba 1: %s\n", str);
    ft_printf("Propio:   %s\n", str);
    printf("*****\n");
    
    printf("Prueba 2: %p\n", ptr);//0x16f30f18c
    ft_printf("Propio:   %p\n", ptr);//[ERROR]->
    printf("*****\n");
    
    printf("Prueba 3: %d\n", num);
    ft_printf("Propio:   %d\n", num);
    printf("*****\n");

    printf("Prueba 4: %%\n");
    ft_printf("Propio:   %%\n");

    // 2º TEST
    char *str1 = "Hola, mundo";
    char *str2 = "¡Bienvenidos a 42!";
    printf("*****2ºTEST:*****\n");
    
    printf("(original)Strings: %s, %s\n", str1, str2);
    ft_printf("(propio)Strings: %s, %s\n", str1, str2);
    printf("*****\n");

    printf("(original)Numeros: %d, %d, %d\n", num, num + 1, num + 2);
    ft_printf("(propio)Numeros: %d, %d, %d\n", num, num + 1, num + 2);
    printf("*****\n");
    
    printf("(original)Texto y numeros: %s, %d, %s\n", str1, num, str2);
    ft_printf("(propio)Texto y numeros: %s, %d, %s\n", str1, num, str2);
    printf("*****\n");

    // 3º TEST
    printf("*****3ºTEST :*****\n");

    printf("Original con %%i: %i, %i\n", 42, -42);
    ft_printf("Propio con %%i: %i, %i\n", 42, -42);
    printf("*****\n");
    
    printf("Original con %%o: %o\n", 42);
    ft_printf("Propio con %%o: %o\n", 42);
    printf("*****\n");
    
    printf("Original con %%u: %u\n", 42);
    ft_printf("Propio con %%u: %u\n", 42);
    printf("*****\n");
    
    printf("Original con %%u (número negativo): %u\n", -42);
    ft_printf("Propio con %%u (número negativo): %u\n", -42);
    printf("*****\n");
    
    printf("Original con %%x: %x\n", 42);
    ft_printf("Propio con %%x: %x\n", 42);
    printf("*****\n");
    
    printf("Original con %%X: %X\n", 42);
    ft_printf("Propio con %%X: %X\n", 42);
    printf("*****\n");
    
    printf("Original con %%c: %c\n", 'A');
    ft_printf("Propio con %%c: %c\n", 'A');
    printf("*****\n");
    
    printf("Original con %%c: %c\n", 65);
    ft_printf("Propio con %%c: %c\n", 65);

    // 4º TEST
    char c = 'A';
    unsigned int u = 123456;
    printf("*****4ºTEST :*****\n");

    printf("(original)Prueba 1: char seguido de int: %c, %d\n", c, num);
    ft_printf("(propio)Prueba 1: char seguido de int: %c, %d\n", c, num);
    printf("*****\n");

    printf("(original)Prueba 2: int seguido de char: %d, %c\n", num, c);
    ft_printf("(propio)Prueba 2: int seguido de char: %d, %c\n", num, c);
    printf("*****\n");

    printf("(original)Prueba 3: int seguido de string: %d, %s\n", num, str);
    ft_printf("(propio)Prueba 3: int seguido de string: %d, %s\n", num, str);
    printf("*****\n");

    printf("(original)Prueba 4: string seguido de int: %s, %d\n", str, num);
    ft_printf("(propio)Prueba 4: string seguido de int: %s, %d\n", str, num);
    printf("*****\n");

    printf("(original)Prueba 5: unsigned int seguido de string: %u, %s\n", u, str);
    ft_printf("(propio)Prueba 5: unsigned int seguido de string: %u, %s\n", u, str);
    printf("*****\n");

    printf("(original)Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
    ft_printf("(propio)Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
    printf("*****\n");

    printf("(original)Prueba 7: múltiplos parámetros de diferentes tipos: %c, %d, %s, %x\n", c, num, str, u);
    ft_printf("(propio)Prueba 7: múltiplos parámetros de diferentes tipos: %c, %d, %s, %x\n", c, num, str, u);
    printf("*****\n");

    // 5º TEST
    
    int num2 = 42;
    unsigned int u_num = 42;
    unsigned int u_neg = 4294967254;
    
    printf("5ºTEST 1:\n");

    printf("Prueba 1.1: Original con %%#x: %x\n", u_num);
    ft_printf("Prueba 1.1: Propio con %%#x: %x\n", u_num);
    printf("*****\n");


    printf("Prueba 1.2: Original con %%#X: %X\n", u_num);
    ft_printf("Prueba 1.2: Propio con %%#X: %X\n", u_num);
    printf("*****\n");


    printf("Prueba 2.1: Original con %%0d: %0d\n", num2);
    ft_printf("Prueba 2.1: Propio con %%0d: %0d\n", num2);
    printf("*****\n");


    printf("Prueba 3.1: Original con %%-5d: %-5d\n", num2);
    ft_printf("Prueba 3.1: Propio con %%-5d: %-5d\n", num2);
    printf("*****\n");


    printf("Prueba 4.1: Original con %%+d: %+d\n", num2);
    ft_printf("Prueba 4.1: Propio con %%+d: %+d\n", num2);
    printf("*****\n");


    printf("Prueba 5.1: Original con %% d: % d\n", num2);
    ft_printf("Prueba 5.1: Propio con %% d: % d\n", num2);
    printf("*****\n");


    printf("Prueba 6.1: Original con %%10d: %10d\n", num2);
    ft_printf("Prueba 6.1: Propio con %%10d: %10d\n", num2);
    printf("*****\n");


    printf("Prueba 7.1: Original con %%u (unsigned int grande): %u\n", u_neg);
    ft_printf("Prueba 7.1: Propio con %%u (unsigned int grande): %u\n", u_neg);
    printf("*****\n");


    printf("Prueba 8.1: Original con %%05d: %05d\n", num2);
    ft_printf("Prueba 8.1: Propio con %%05d: %05d\n", num2);
    printf("*****\n");


    printf("Prueba 9.1: Original con %%#o: %#o\n", u_num);
    ft_printf("Prueba 9.1: Propio con %%#o: %#o\n", u_num);
    printf("*****\n");


    printf("Prueba 10.1: Original con %%010x: %010x\n", u_num);
    ft_printf("Prueba 10.1: Propio con %%010x: %010x\n", u_num);
    printf("*****\n");

    
    return 0;
}
