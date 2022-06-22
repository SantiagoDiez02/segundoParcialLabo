#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "service.h"

/// @fn int Passenger_setId(Passenger*, int)
/// @brief setea el id
///
/// @param this
/// @param id
/// @return
int servicio_setId(eServicio *this, int id) {
	int retorno = 0;
	this->id = id;
	if (this->id != id) {

		retorno = 1;
	}
	return retorno;
}
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief obtiene el id
///
/// @param this
/// @param id
/// @return
int servicio_getId(eServicio *this, int *id) {
	*id = this->id;
	if (*id != this->id) {
		return 1;
	}
	return 0;
}
/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief setea el nombre
///
/// @param this
/// @param nombre
/// @return
int servicio_setDescripcion(eServicio *this, char *descripcion) {
	int retorno = 1;
	if (descripcion != NULL && this != NULL) {
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}
	return retorno;

}
/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief obtiene el nombre
///
/// @param this
/// @param nombre
/// @return
int servicio_getDescripcion(eServicio *this, char *descripcion) {
	strcpy(descripcion, this->descripcion);
	if (!(strcmp(descripcion, this->descripcion))) {
		return 1;
	}
	return 0;
}
/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief setea el apellido
///
/// @param this
/// @param apellido
/// @return
int servicio_settipo(eServicio *this, char *tipo) {
	int retorno = 1;

	if (tipo != NULL && this != NULL) {
		strcpy(this->tipo, tipo);
		retorno = 0;
	}
	return retorno;
}
/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief obtiene el apellido
///
/// @param this
/// @param apellido
/// @return
int servicio_gettipo(eServicio *this, char *tipo) {
	strcpy(tipo, this->tipo);
	if (!(strcmp(tipo, this->tipo))) {
		return 1;
	}
	return 0;
}
/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief setea el codigo
///
/// @param this
/// @param codigoVuelo
/// @return

int servicio_setprecioUnitario(eServicio *this, float precioUnitario) {
	int retorno = 0;
	this->precioUnitario = precioUnitario;
	if (this->precioUnitario != precioUnitario) {

		retorno = 1;
	}
	return retorno;
}
/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief obtiene el precio
///
/// @param this
/// @param precio
/// @return
int servicio_getprecioUnitario(eServicio *this, float *precioUnitario) {
	*precioUnitario = this->precioUnitario;
	if (*precioUnitario != this->precioUnitario) {
		return 1;
	}
	return 0;
}
/// @fn int Passenger_setId(Passenger*, int)
/// @brief setea el id
///
/// @param this
/// @param id
/// @return
int servicio_setcantidad(eServicio *this, int cantidad) {
	int retorno = 0;
	this->cantidad = cantidad;
	if (this->cantidad != cantidad) {

		retorno = 1;
	}
	return retorno;
}
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief obtiene el id
///
/// @param this
/// @param id
/// @return
int servicio_getcantidad(eServicio *this, int *cantidad) {
	*cantidad = this->cantidad;
	if (*cantidad != this->cantidad) {
		return 1;
	}
	return 0;
}
int servicio_settotalServicio(eServicio *this, float totalServicio) {
	int retorno = 0;
	this->totalServicio = totalServicio;
	if (this->totalServicio != totalServicio) {

		retorno = 1;
	}
	return retorno;
}
/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief obtiene el precio
///
/// @param this
/// @param precio
/// @return
int servicio_getTipototalServicio(eServicio *this, float *totalServicio) {
	*totalServicio = this->totalServicio;
	if (*totalServicio != this->totalServicio) {
		return 1;
	}
	return 0;
}

/// @fn Passenger Passenger_new*()
/// @brief abre la memoria dinamica de la lista y vacia todos los datos
///
/// @return retorna el pasajero vacio
eServicio* servicio_new() {
	eServicio *nuevoServicio = NULL;
	nuevoServicio = (eServicio*) malloc(sizeof(eServicio));

	if (nuevoServicio != NULL) {
		nuevoServicio->id = 0;
		strcpy(nuevoServicio->descripcion, " ");
		strcpy(nuevoServicio->tipo, " ");
		nuevoServicio->precioUnitario = 0;
		nuevoServicio->cantidad = 0;
		nuevoServicio->totalServicio = 0;
	}

	return nuevoServicio;

}
int servicio_newServicio(char *totalServicio) {
	eServicio *nuevoServicio = servicio_new();
	float totalServicioAux;
	int validar = 0;

	totalServicioAux = atof(totalServicio);
	if (nuevoServicio != NULL) {
		if (servicio_settotalServicio(nuevoServicio, totalServicioAux) == 0) {

			validar = 1;
		}
	}
	if (validar != 1) {
		free(nuevoServicio);
		nuevoServicio = NULL;
	}
	return validar;
}
/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// @brief carga los datos obtenidos en el pasajero vacio
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param tipoPasajeroStr
/// @param precioStr
/// @param flycodeStr
/// @param estadoDeVuelo
/// @return retorna el pasajero cargado con los datos
eServicio* servicio_newParametros(char *idStr, char *descripcion, char *tipo,
		char *precioUnitario, char *cantidad, char *totalServicio) {
	eServicio *nuevoServicio = servicio_new();
	int idAux;
	int tipoAux;
	char tipoChar[30];
	float precioAux;
	int cantidadAux;
	float totalServicioAux;

	idAux = atoi(idStr);
	tipoAux = atoi(tipo);
	comparacionDeTipo(tipoAux, tipoChar);
	precioAux = atof(precioUnitario);
	cantidadAux = atoi(cantidad);
	totalServicioAux = atof(totalServicio);

	int validacion = 0;

	if (nuevoServicio != NULL) {

		if (servicio_setId(nuevoServicio, idAux) == 0) {

			if (servicio_setDescripcion(nuevoServicio, descripcion) == 0) {

				if (servicio_settipo(nuevoServicio, tipoChar) == 0) {

					if (servicio_setprecioUnitario(nuevoServicio, precioAux)
							== 0) {

						if (servicio_setcantidad(nuevoServicio, cantidadAux)
								== 0) {

							if (servicio_settotalServicio(nuevoServicio,
									totalServicioAux) == 0) {

								validacion = 1;
							}

						}
					}
				}
			}
		}
		if (validacion != 1) {
			free(nuevoServicio);
			nuevoServicio = NULL;
		}
	}
	return nuevoServicio;
}

/// @fn int Passenger_listEntera(LinkedList*)
/// @brief muestra toda la lista mediante un for
///
/// @param pArrayListPassenger
/// @return
int servicio_listEntera(LinkedList *pArraylistaServicios) {
	Node *indice = pArraylistaServicios->pFirstNode;
	eServicio *leer;

	printf(
			"\nID:||descripcion: || tipo:  ||  precioUnitario:|| cantidad:||totalServicio:\n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;
		servicio_listaUno(leer);

	}
	printf(
			"\n-----------------------------------------------------------------------\n");
	return 1;
}
/// @fn int Passenger_idDisponible(LinkedList*)
/// @brief busca el largo de la lista para devolver la ultima posicion, si no se cargo nada el largo va a ser 0
///
/// @param pArrayListPassenger
/// @return retorna el id que se usara (1 si no hay datos, es decir el primero. El largo de la lista + 1)
int servicio_idDisponible(LinkedList *pArraylistaServicios) {
	Node *indice = pArraylistaServicios->pFirstNode;
	eServicio *ultimo;
	int devolver = 0;

	if (ll_len(pArraylistaServicios) == 0) {
		devolver = 1;
	} else {
		for (; indice != NULL; indice = indice->pNextNode) {
			ultimo = indice->pElement;
		}
		devolver = ultimo->id + 1;
	}

	return devolver;
}

/// @fn void Passenger_listaUno(Passenger*)
/// @brief lista todos los datos una vez
///
/// @param lecturaDeDato
void servicio_listaUno(eServicio *lecturaDeDato) {
	if (lecturaDeDato != NULL) {
		printf("%d ||  ", lecturaDeDato->id);
		printf(lecturaDeDato->descripcion);
		printf("  ||  ");
		printf(lecturaDeDato->tipo);
		printf("  ||  ");
		printf("%.2f ||  ", lecturaDeDato->precioUnitario);
		printf("%d  ||  ", lecturaDeDato->cantidad);
		printf("%.2f", lecturaDeDato->totalServicio);
		printf("\n");
	}

}
int servicio_descripcionComparados(void *descripcionA, void *descripcionB) {
	int validar;
	char descripcionAuxA[50];
	char descripcionAuxB[50];

	eServicio *a;
	eServicio *b;

	a = (eServicio*) descripcionA;
	b = (eServicio*) descripcionB;

	servicio_getDescripcion(a, descripcionAuxA);
	servicio_getDescripcion(b, descripcionAuxB);

	if (strcmp(descripcionAuxA, descripcionAuxB) == 0) {
		validar = 0;
	} else {
		if (strcmp(descripcionAuxA, descripcionAuxB) > 0) {
			validar = 1;
		} else {
			validar = -1;
		}
	}
	return validar;
}
int primerFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Minorista") == 0) {
		retorno = 1;
	}
	return retorno;
}

int segundoFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Mayorista") == 0) {
		retorno = 1;
	}
	return retorno;
}
int tercerFilter(void *servicio) {
	int retorno = 0;
	eServicio *filtrando = servicio;

	if (strcmp(filtrando->tipo, "Exportar") == 0) {
		retorno = 1;
	}
	return retorno;
}

int servicio_mapeo(void *elemento) {
	eServicio *precioFinal;
	precioFinal = elemento;
	float precioAPasar;

	precioAPasar = precioFinal->precioUnitario * precioFinal->cantidad;
	servicio_settotalServicio(precioFinal, precioAPasar);

	return 0;
}
int comparacionDeTipo(int tipo, char *tipoAux) {

	switch (tipo) {
	case 1:
		strcpy(tipoAux, "Minorista");
		break;
	case 2:
		strcpy(tipoAux, "Mayorista");
		break;
	case 3:
		strcpy(tipoAux, "Exportar");
		break;
	}

	return 0;
}

