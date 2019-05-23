typedef struct Nodo {
	Elem dato;
	struct Nodo *sig;
} *ApNodo;

typedef struct CNodo {
	ApNodo prim;
	ApNodo ult;
} *Cola;

Cola nueva() {
	Cola t = (Cola)malloc(sizeof(struct CNodo));
	t->prim = t->ult = NULL;
	return t;
}

int esnueva(Cola q) {
	return (q->prim == NULL) && (q->ult == NULL);
}

Cola formar(Cola q, Elem e) {
	ApNodo t = (ApNodo)malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = NULL;
	if(esnueva(q))
		q->prim = q->ult = t;
	else {
		q->ult->sig=t;
		q->ult =t;
	}
	return q;
}

Elem primero(Cola q) { return q->prim->dato; }

/*
Cola desformar(Cola q) {
	if(q->prim==q->ult)
		q->prim =q->ult=NULL;
	else
		q->prim=q->prim->sig;	
}
*/

Cola desformar(Cola q) {
	Cola t = nueva();
	t->prim = q->prim;
	t->ult = q->ult;
	if(t->prim == t->ult)
		t->prim = t->ult=NULL;
	else
		t->prim=q->prim->sig;	
}

void ImpCola(Cola q) {
	if(!esnueva(q)) {
		ImpElem(primero(q));
		ImpCola(desformar(q));
	}
	
}
