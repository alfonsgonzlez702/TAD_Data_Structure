typedef struct Nodo {
	Elem dato;
	struct nodo *sig, *ant;
} *ApNodo;

typedef struct BNodo {
	ApNodo izquierda;
	ApNodo derecha;
} *Bicola;

Bicola nuevaB() {
	Bicola t = (Bicola)malloc(sizeof(struct BNodo));
	t->izquierda = t->derecha = NULL;
	return t;
}

int esnuevaB(Bicola b) {
	return (b->izquierda == NULL) && (b->derecha == NULL);
}

Bicola formarD(Bicola b, Elem e) {
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
		t->dato = e;
		t->sig = t->ant = NULL;
	
	if(esnuevaB(b))
		b->derecha = b->izquierda = t;
	else {
		t->ant = b->derecha;
		b->derecha->sig = t;
		b->derecha = t;
	}
	return b;
}

Bicola formarI(Elem e, Bicola b) {
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
		t->dato = e;
		t->sig = t->ant = NULL;
	
	if(esnuevaB(b))
		b->izquierda = b->derecha = t;
	else {
		t->sig = b->izquierda;
		b->izquierda->ant = t;
		b->izquierda =t;
	}
	return b;
}

Elem derecho(Bicola b) { return b->derecha->dato; }

Elem izquierdo(Bicola b) { return b->izquierda->dato; }

Bicola desformarD(Bicola b) {
	Bicola t = nuevaB();
	if(b->derecha == b->izquierda) 
		return t;
		
	else {
		t->derecha = b->derecha->ant;
		t->izquierda = b->izquierda;
		return t;
	}
}

Bicola desformarI(Bicola b) {
	Bicola t = nuevaB();
	if(b->derecha == b->izquierda) 
		return t;
		
	else {
		t->izquierda = b->izquierda->sig;
		t->derecha = b->derecha;
		return t;
	}
}

Bicola RotarI(Bicola b) {
	b = formarD(b, izquierdo(b));
	b = desformarI(b);
	return b;
}

Bicola RotarD(Bicola b) {
	b = formarI(derecho(b), b);
	b = desformarD(b);
	return b;
}

void ImpBicolaI(Bicola b) {
	Bicola t = nuevaB();
		t->izquierda = b->izquierda; 
		t->derecha = b->derecha;
	while(!esnuevaB(t)) {
		ImpElem(izquierdo(t));
		t = desformarI(t);
	}
}

/*
void ImpBicolaI(Bicola b) {
	ApNodo cent = b->izquierda;
	
	do {
		ImpElem(cent->dato);
		cent = cent->sig;
	}while(cent->sig != NULL);
}

void ImpBicolaD(Bicola b) {
	ApNodo cent = b->derecha;
	
	do {
		ImpElem(cent->dato);
		cent = cent->ant;
	}while(cent->sig != NULL);
	
}
*/
