#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "service.h"

#include "string.h"
#include "ctype.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicioFromText(FILE *pFile, LinkedList *pArraylistaServicios) {
	eServicio *nuevo;

	char idAux[30];
	char descAux[30];
	char tipoAux[30];
	char precioAux[30];
	char cantAux[30];
	char totalAux[30];

	int r;
	int validar = 0;

	if (pFile == NULL) {
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do {
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,
				descAux, tipoAux, precioAux, cantAux, totalAux);
		if (r == 6) {
			nuevo = servicio_newParametros(idAux, descAux, tipoAux, precioAux,
					cantAux, totalAux);
			if (nuevo != NULL) {
				ll_add(pArraylistaServicios, nuevo);
				validar = 1;
			}

		}

	} while (!feof(pFile));

	fclose(pFile);

	return validar;

}

