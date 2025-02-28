/*#include <stdio.h>
#include "./includes/ft_printf.h"

int	main(void)
{
	char			*str;
	int				num;
	void			*ptr;
	char			*str1;
	char			*str2;
	char			c;
	unsigned int	u;
	int				num2;
	unsigned int	u_num;
	unsigned int	u_neg;

	// 1º TEST
	str = "Hola, mundo";
	num = 42;
	ptr = &num;
	printf("*****1ºTEST:*****\n");
	printf("Prueba 1: %s\n", str);
	ft_printf("Propio:   %s\n", str);
	printf("*****\n");
	printf("Prueba 2: %p\n", ptr);
	ft_printf("Propio:   %p\n", ptr);
	printf("*****\n");
	printf("Prueba 3: %d\n", num);
	ft_printf("Propio:   %d\n", num);
	printf("*****\n");
	printf("Prueba 4: %%\n");
	ft_printf("Propio:   %%\n");
	// 2º TEST
	str1 = "Hola, mundo";
	str2 = "¡Bienvenidos a 42!";
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
	c = 'A';
	u = 123456;
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
	printf("(original)Prueba 5: unsigned int seguido de string: %u, %s\n", u,
		str);
	ft_printf("(propio)Prueba 5: unsigned int seguido de string: %u, %s\n", u,
		str);
	printf("*****\n");
	printf("(original)Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
	ft_printf("(propio)Prueba 6: hexadecimal seguido de char: %x, %c\n", u, c);
	printf("*****\n");
	printf("(original)Prueba 7: múltiplos parámetros de diferentes tipos: %c,
		%d, %s, %x\n", c, num, str, u);
	ft_printf("(propio)Prueba 7: múltiplos parámetros de diferentes tipos: %c,
		%d, %s, %x\n", c, num, str, u);
	printf("*****\n");
	num2 = 42;
	u_num = 42;
	u_neg = -87;
printf("5ºTEST 1:\n");
printf("Prueba 1.1: Original con %%x: %x\n", u_num);
ft_printf("Prueba 1.1: Propio con %%x: %x\n", u_num);
printf("*****\n");
printf("Prueba 1.2: Original con %%X: %X\n", u_num);
ft_printf("Prueba 1.2: Propio con %%X: %X\n", u_num);
printf("*****\n");
printf("Prueba 2.1: Original con %%d: %d\n", num2);
ft_printf("Prueba 2.1: Propio con %%d: %d\n", num2);
printf("*****\n");
printf("Prueba 7.1: Original con %%u (unsigned int grande): %u\n", u_neg);
ft_printf("Prueba 7.1: Propio con %%u (unsigned int grande): %u\n", u_neg);
printf("*****\n");
printf("Prueba 9.1: Original con %%o: %o\n", u_num);
ft_printf("Prueba 9.1: Propio con %%o: %o\n", u_num);
printf("*****\n");
	return (0);
}
*/