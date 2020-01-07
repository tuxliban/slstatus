/*	Librerías que se cargarán	*/

#include <fcntl.h>			// Biblioteca para la gestión de opciones de control de archivos
#include <unistd.h>			// Biblioteca  de constantes simbólicas y tipos estándar
#include <stdio.h>			// Biblioteca de utilidades generales estándar de C

#include "../util.h"

/* Función principal (se ejecutará todo lo que está dentro de las llaves) */
const char *
clima(void)
{
	int fd;				// Definir variable de tipo entero (file descriptor)
	char buf[2048];			// Almacenar como máximo 2048 bytes en el buffer

	fd = open ("/tmp/weather", O_RDONLY);	// Abrir archivo en sólo lectura

	if(fd == -1)		// Si no se puede abrir el archivo
	{
		bprintf ("n/a");
	}
	else
	{
		read(fd, buf, 9);	// Leer los dígitos especificados del file descriptor almacenados en el buffer
		close(fd);		// Cerrar fichero que se ha abierto para leer

		return bprintf ("%s", buf);	// Regresar el valor almacenado en el buffer
	}
	return 0;
}
