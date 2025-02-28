/*
#include "./includes/ft_printf.h"
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*mem_test;

	int mi_ret, orig_ret;
	printf("--- Gestión Simple de Conversiones ---\n");
	mi_ret = ft_printf("Carácter: %c\n", 'A');
	orig_ret = printf("Carácter: %c\n", 'A');
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Cadena: %s\n", "Hola");
	orig_ret = printf("Cadena: %s\n", "Hola");
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Entero: %d\n", -42);
	orig_ret = printf("Entero: %d\n", -42);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Sin signo: %u\n", 42);
	orig_ret = printf("Sin signo: %u\n", 42);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Hexadecimal: %x\n", 255);
	orig_ret = printf("Hexadecimal: %x\n", 255);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Puntero: %p\n", (void *)12345);
	orig_ret = printf("Puntero: %p\n", (void *)12345);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	printf("--- Pruebas Extensas ---\n");
	mi_ret = ft_printf("Mezcla: %d %s %c %x %u %p\n", 42, "prueba", 'Z', 255,
			420, (void *)42000);
	orig_ret = printf("Mezcla: %d %s %c %x %u %p\n", 42, "prueba", 'Z', 255,
			420, (void *)42000);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Idénticos: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	orig_ret = printf("Idénticos: %d %d %d %d %d\n", 1, 2, 3, 4, 5);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	// Pruebas adicionales
	printf("--- Pruebas Adicionales ---\n");
	// NULL en %s
	mi_ret = ft_printf("Cadena NULL: %s\n", (char *)NULL);
	orig_ret = printf("Cadena NULL: %s\n", (char *)NULL);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	// Valores extremos
	mi_ret = ft_printf("Mínimo int: %i, Máximo int: %i\n", -2147483648,
			2147483647);
	orig_ret = printf("Mínimo int: %li, Máximo int: %i\n", -2147483648L,
			2147483647);
	printf("Valores de retorno: ft_printf = %i, printf = %i\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Mínimo uint: %u, Máximo uint: %u\n", 0, 4294967295);
	orig_ret = printf("Mínimo uint: %u, Máximo uint: %lu\n", 0, 4294967295UL);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	mi_ret = ft_printf("Mínimo hex: %x, Máximo hex: %x\n", 0, 0xFFFFFFFF);
	orig_ret = printf("Mínimo hex: %x, Máximo hex: %x\n", 0, 0xFFFFFFFF);
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	// Cadenas con espacios y caracteres especiales
	mi_ret = ft_printf("Especial: \tHola\nNueva línea\n");
	orig_ret = printf("Especial: \tHola\nNueva línea\n");
	printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
		orig_ret);
	// Prueba de fuga de memoria (solo para chequeo manual con leaks o fsanitize)
	mem_test = malloc(50);
	if (mem_test)
	{
		sprintf(mem_test, "Prueba de memoria: %s", "ft_printf");
		mi_ret = ft_printf("%s\n", mem_test);
		orig_ret = printf("%s\n", mem_test);
		printf("Valores de retorno: ft_printf = %d, printf = %d\n\n", mi_ret,
			orig_ret);
		// free(mem_test); // Descomentar para evitar la fuga
	}
	return (0);
}
*/