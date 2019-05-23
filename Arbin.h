typedef struct NodoAB {
	Elem r;
	struct NodoAB *izq;
	struct NodoAB *der;
} *Arbin;

Arbin nuevoAB() { return NULL; }

Arbin consAB(Elem r, Arbin i, Arbin d) {
	Arbin t = (Arbin)malloc(sizeof(struct NodoAB));
		t->r = r;
		t->izq = i;
		t->der = d;
	return t;	
}

int esnuevoAB(Arbin a) { return a == NULL; }

Elem raiz(Arbin a) {
	return a->r;
}

Arbin hijoI(Arbin a) {
	return a->izq;
}

Arbin hijoD(Arbin a) {
	return a->der;
}

void ImpIn(Arbin a) {
	if(!esnuevoAB(a)) {
		ImpIn(hijoI(a));
		ImpElem(raiz(a));
		ImpIn(hijoD(a));
	}
}
//Altura de un arbol: El numero de aristas del camino mas largo entre la raiz y una hoja.
int alturaAB(Arbin a) {
	if(esnuevoAB(a))
		return 0;
	else
	 return (1+max(alturaAB(hijoI(a)), alturaAB(hijoD(a))));
}

int max(int i, int d) {
	if(i > d || i == d) return i;
	else return d;
}

int numNodos(Arbin a) {
	if(esnuevoAB(a))
		return 0;
	else
		return (1+numNodos(hijoI(a))+numNodos(hijoD(a)));
}

void ImpNivelAB(Arbin a, int nivel, int tab) {
	int i;
	if(esnuevoAB(a))
		printf("()\t\t");
	else if (nivel == 1) {
		for (i = tab; i > 0; i--) {
			printf("\t");
		}
		ImpElem(raiz(a));
	}
		
	else if(nivel > 1) {
		ImpNivelAB(hijoI(a), nivel-1, tab);
		ImpNivelAB(hijoD(a), nivel-1, tab);
	}
}

void ImpArbin(Arbin a) {
	int i, h = alturaAB(a), j;
	for(i = 0; i <= h; i++) {
		j = h - (i);
		ImpNivelAB(a, i, j);
		printf("\n");
	}
}

int EsCompleto(Arbin a) {
	if(esnuevoAB(a))
		return 1;
	else if(alturaAB(hijoI(a)) == alturaAB(hijoD(a)))
			if(EsCompleto(hijoD(a)) && EsLleno(hijoI(a)))
				return 1;
		else if(alturaAB(hijoI(a)) - alturaAB(hijoD(a)) <= 1 && alturaAB(hijoI(a)) - alturaAB(hijoD(a)) >= 0)
			return EsCompleto(hijoI(a)) && EsLleno(hijoD(a));
	else
		return 0;
}

int EsLleno(Arbin a) {
	if(esnuevoAB(a))
		return 1;
		else if(alturaAB(hijoI(a)) == alturaAB(hijoD(a)) && EsLleno(hijoI(a)) && EsLleno(hijoD(a)))
				return 1;
			else 
				return 0;
}

Arbin consCompleto(Elem e, Arbin a) {
	if(esnuevoAB(a))
		return consAB(e, nuevoAB(), nuevoAB());
	else if(EsLleno(a) || !EsLleno(hijoI(a)))
			return consAB(raiz(a), consCompleto(e, hijoI(a)), hijoD(a));
	else
		return consAB(raiz(a), hijoI(a), consCompleto(e, hijoD(a)));
}

int esHoja(Arbin a) {
	return (esnuevoAB(hijoI(a)) && esnuevoAB(hijoD(a)));
}

Elem masDerecho(Arbin a) {
	if (esHoja(a))
		return raiz(a);
	else
		if (alturaAB(hijoI(a)) == alturaAB(hijoD(a)))
			return masDerecho(hijoD(a));
		else
			return masDerecho(hijoI(a));
}

Arbin elimina(Arbin a) {
	if (esHoja(a))
		return nuevoAB();
	else if (alturaAB(hijoI(a)) == alturaAB(hijoD(a)))
		return consAB(raiz(a), hijoI(a), elimina(hijoD(a)));
	else
		return consAB(raiz(a), elimina(hijoI(a)), hijoD(a));
}
void ImpArbinHorizontal(Arbin a, int n) {
	int i;
	if (esnuevoAB(a))
		return;
	ImpArbinVertical(hijoD(a), n + 1);
	for (i = 0; i < n; i++)
		printf("	");

	ImpElem(raiz(a)); printf("\n");
	ImpArbinVertical(hijoI(a), n + 1);
}
