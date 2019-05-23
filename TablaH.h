/*
	PRECONDICIONES:
	1) Se requiere de la definición en el ELEM del tipo de dato cardinal. dicho tipo de dato será sometido al hashing 
	   para obtener la posición en la tabla hash (revise README).
	2) La tabla tiene una dimensión fija cuyo número es primo
	3) Antes de usar recuperaTH:TablaH th, Cardinal a->Elem es necesario haber buscado el elemento primero y verificar que si
	   se encuentra en la tabla de dispersión hash
*/
typedef struct tablah {
	int m;
	Lista* fila;
}*TablaH;

TablaH vaciaTH(int n) {
	int i;
	TablaH temp = (TablaH)malloc(sizeof(struct tablah));
	temp->m = n;
	temp->fila = (Lista*)malloc(n * sizeof(Lista));
	for (i = 0; i < n; i++)
		temp->fila[i] = vacia();

	return temp;
}

int NumCol(TablaH th) {
	return th->m;
}

Lista Fila(TablaH th, int pos) {
	return th->fila[pos];
}

int esvaciaTH(TablaH th) {
	int i;
	for (i = 0; i < NumCol(th); i++) {
		if (!esvacia(Fila(th, i))) return 0;
	}
	return 1;
}

TablaH insertaTH(TablaH th, Cardinal a, Elem e) {
	int pos = hashing(a, NumCol(th));
	th->fila[pos] = cons(e, Fila(th, pos));
	return th;
}

int estaenTH(TablaH th, Cardinal a) {
	Lista aux = Fila(th, hashing(a, NumCol(th)));

	if (!esvacia(aux)) {
		while(!esvacia(aux)) {
			if(EsIgualCard(a, cabeza(aux)))
				return 1;
			aux =resto(aux);
		}
	}
	return 0;
}

Elem recuperaTH(TablaH th, Cardinal a) {
	Lista aux = Fila(th, hashing(a, NumCol(th)));

	if (!esvacia(aux)) {
		while (!esvacia(aux)) {
			if (EsIgualCard(a, cabeza(aux)))
				return cabeza(aux);
			aux = resto(aux);
		}
	}
	return cabeza(aux);
}
