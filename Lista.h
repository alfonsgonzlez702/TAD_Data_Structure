typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Lista;

Lista vacia() {return NULL;}

Lista cons(Elem e, Lista l) {
	Lista t = (Lista) malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = l;
	return t;
}

int esvacia(Lista l) {return l == NULL;}

Elem cabeza(Lista l) {return l->dato;}

Lista resto(Lista l) {return l->sig;}

int NumElem(Lista l) {
	if(esvacia(l)) return 0;
	else return (1 + NumElem(resto(l)));
}

Lista PegaListas(Lista l, Lista m) {
	if(esvacia(l)) return m;
	else return cons(cabeza(l),PegaListas(resto(l),m));
}

void ImpLista(Lista l, FILE *a) {
	if(!esvacia(l)) {
		ImpElem(cabeza(l), a);
		ImpLista(resto(l), a);
	}
}

Lista InvLista(Lista l) {
	if(esvacia(l)) return vacia();
	else return PegaListas(InvLista(resto(l)),cons(cabeza(l),vacia()));
}

Lista InsOrd(Elem e, Lista l) {
	if(esvacia(l)){
		return cons(e,vacia());
	}
	else{
		if(EsMenor(e,cabeza(l)))
			return cons(e,l);
		else
			return cons(cabeza(l), InsOrd(e,resto(l)));
	}
}
Lista OrdenaA(Lista l) {
	if(esvacia(l)) 
		return l;
	else
		return InsOrd(cabeza(l),OrdenaA(resto(l)));
}
Lista OrdenaD(Lista l) {
	return InvLista(OrdenaA(l));
}

int EncElem(Elem e, Lista l) {
	if(esvacia(l))
		return 0;
	else if(!EsIgual(e,cabeza(l)))
		return EncElem(e,resto(l));
	else
		return EsIgual(e,cabeza(l));
}
