typedef struct pila{
	Elem data;
	struct pila *rest;
}*Pila;

Pila empty() {return NULL;}

Pila push(Elem e, Pila p) {
	Pila q = (Pila) malloc(sizeof(struct pila));
	q->data = e;
	q->rest = p;
	return q;
}

int isEmpty(Pila p) {return p == NULL;}

Elem top(Pila p) {
	if(!isEmpty(p))
		return p->data;
	else
		puts("ERROR");
}

Pila pop(Pila p) {
	if(!isEmpty(p))
		return p->rest;
	else
		puts("ERROR");
}

