/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef SERVICE_H_
#define SERVICE_H_

typedef struct {
	int id;
	char descripcion[50];
	char tipo[50]; //1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR
	float precioUnitario;
	int cantidad;
	float totalServicio;

} eServicio;

eServicio* servicio_new();
eServicio* servicio_newParametros(char *idStr, char *descripcion, char *tipo,
		char *precioUnitario, char *cantidad, char *totalServicio);
int servicio_newServicio(char *precioFinal);

int servicio_setId(eServicio *this, int id);
int servicio_getId(eServicio *this, int *id);

int servicio_setDescripcion(eServicio *this, char *descripcion);
int servicio_getDescripcion(eServicio *this, char *descripcion);

int servicio_settipo(eServicio *this, char *tipo);
int servicio_gettipo(eServicio *this, char *tipo);

int servicio_setprecioUnitario(eServicio *this, float precioUnitario);
int servicio_getprecioUnitario(eServicio *this, float *precioUnitario);

int servicio_setcantidad(eServicio *this, int cantidad);
int servicio_getcantidad(eServicio *this, int *cantidad);

int servicio_settotalServicio(eServicio *this, float totalServicio);
int servicio_getTipototalServicio(eServicio *this, float *totalServicio);

int servicio_listEntera(LinkedList *pArraylistaServicios);
void servicio_listaUno(eServicio *lecturaDeDato);
int servicio_idDisponible(LinkedList *pArraylistaServicios);

int servicio_descripcionComparados(void *descripcionA, void *descripcionB);
int primerFilter(void *servicio);
int segundoFilter(void *servicio);
int tercerFilter(void *servicio);
int servicio_mapeo(void *elemento);

int comparacionDeTipo(int tipo, char *tipoAux);

#endif /* SERVICE_H_ */
