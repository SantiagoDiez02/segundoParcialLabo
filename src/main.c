#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "service.h"

int main() {
	setbuf(stdout, NULL);
	int flagMenu = 0;
	int flagCaseUno = 0;
	int flagGuardar = 0;

	char path[30];
	int opcion = 0;

	LinkedList *listaServicio = ll_newLinkedList();

	do {
		printf("\n------------MENU------------\n"
				"\n{- Ingrese la opcion deseada -}\n"
				"1. Cargar archivo\n"
				"2. Imprimir lista\n"
				"3. Asignar totales\n"
				"4. Filtrar por tipo\n"
				"5. Mostrar servicios\n"
				"6. Guardar servicios\n"
				"7. Salir\n\n");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			if (flagCaseUno == 0) {
				flagCaseUno = 1;
				printf("como se llama el archivo que desea abrir?");
				fflush(stdin);
				gets(path);
				controller_loadFromText(path, listaServicio);
				flagMenu = 1;

			} else {
				printf("los datos solo pueden ser cargados una vez\n");
			}
			break;
		case 2:
			if (flagMenu == 0) {
				printf("primero debe ingresar a la opcion 1");
			} else {
				controller_ListServicio(listaServicio);
			}
			break;
		case 3:
			if (flagMenu == 0) {
				printf("primero debe ingresar a la opcion 1");
			} else {
				controller_addservicio(listaServicio);

			}
			break;
		case 4:
			if (flagMenu == 0) {
				printf("primero debe ingresar a la opcion 1");
			} else {
				controller_filter(listaServicio);
			}
			break;
		case 5:
			if (flagMenu == 0) {
				printf("primero debe ingresar a la opcion 1");
			} else {
				controller_sortdescripcion(listaServicio);
				controller_ListServicio(listaServicio);
			}
			break;
		case 6:
			if (flagMenu == 0) {
				printf("primero debe ingresar a la opcion 1");
			} else {
				printf("como se llama el archivo que desea abrir?");
				fflush(stdin);
				gets(path);
				controller_saveAsText(path, listaServicio);
				flagGuardar = 1;
			}

			break;
		case 7:
			if (flagGuardar == 0) {
				printf(
						"\nno cierre el programa si antes no guardo los datos, o los perdera PARA SIEMPRE.\n");
			} else {
				printf("\nSaliendo del menu.\n"
						"\n\n\tMUCHAS GRACIAS!!!\n"
						"\nSantiago Diez");
			}
			break;
		default:
			printf("opcion no valida\n");
			break;

		}
	} while (opcion != 7 || flagGuardar != 1);
	return 0;
}
