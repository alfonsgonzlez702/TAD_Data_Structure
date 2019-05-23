typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *ColaC;

ColaC nuevaC() {return NULL;}

int esnuevaC(ColaC c) {return c == nuevaC();}

ColaC formarC(ColaC c, Elem e) {
	ColaC t = (ColaC) malloc(sizeof(struct Nodo));
	t->dato = e;
	if(esnuevaC(c))
		t->sig = t;
	else {
		t->sig = c->sig;
		c->sig = t;
	}
	return t;
}

Elem primeroC(ColaC c) {return c->sig->dato;}

ColaC desformarC(ColaC c) {
	ColaC t;
	if(t == t->sig)
		return nuevaC();
	else {
		t = c->sig;
		c->sig = c->sig->sig;
		free(t);
		return c;
	}
}

ColaC rotar(ColaC c) {return c->sig;}

void ImpColaC(ColaC q) {
	Elem z = primeroC(q);
	ImpElem(primeroC(q));
	q = rotar(q);
	while(z!=primeroC(q)) {
		ImpElem(primeroC(q));
		q = rotar(q);
	}
}
