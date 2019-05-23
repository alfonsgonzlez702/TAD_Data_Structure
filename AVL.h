typedef DicBin AVL;

int esAVL(AVL a) {
	if(esnuevoAB(a))
		return 1;
	else if(abs(alturaAB(hijoI(a))-alturaAB(hijoD(a))) <= 1 && esAVL(hijoI(a)) && esAVL(hijoD(a)))
		return 1;
	else
		return 0;
}

int abs(int n) {
	if(n > 0) return n;
	else return (-n);
}

AVL rotarD(DicBin db) {
	return consAB(raiz(hijoI(db)), hijoI(hijoI(db)), consAB(raiz(db), hijoD(hijoI(db)), hijoD(db)));
}

AVL rotarI(DicBin db) {
	return consAB(raiz(hijoD(db)), consAB(raiz(db), hijoI(db), hijoI(hijoD(db))), hijoD(hijoD(db)));
}

AVL rotarDaI(DicBin db) {
	return rotarD(consAB(raiz(db), rotarI(hijoI(db)), hijoD(db)));
}

AVL rotarIaD(DicBin db) {
	return rotarD(consAB(raiz(db), hijoI(db), rotarD(hijoD(db))));
}

int factBal(DicBin db) {
	return alturaAB(hijoI(db))-alturaAB(hijoD(db));
}

AVL hazAVL(DicBin a) {
	if(esAVL(hijoI(a)) && esAVL(hijoD(a))) {
		if(factBal(a)>0) {
			if(factBal(hijoI(a)) > 0)
				return rotarD(a);
			else
				return rotarI(a);
		}
		else if(factBal(hijoD(a)) < 0)
				return rotarI(a);
		else 
			rotarIaD(a);
	}
	else if(esAVL(hijoI(a)))
		return consAB(raiz(a), hijoI(a), hazAVL(hijoD(a)));
	else
		return consAB(raiz(a), hazAVL(hijoI(a)), hijoD(a));
		
}

AVL consAVL(Elem e, AVL a) {
	a = InsOrdAB(e, a);
	if(esAVL(a))
		return a;
	else
		return hazAVL(a);
}

AVL borraElemAVL(Elem e, AVL a) {
	a = borraElem(e, a);
	if(esAVL(a))
		return a;
	else
		return hazAVL(a);
}

	
/*Conceptos clave
	
	Node Height: La altura de un nodo es el numero de aristas que hay en un camino entre nodo y una hoja;
			la altura de raiz es uno y las hojas carecen de altura.
	Numero de nodos:
	Hojas: 		
	Camino: Secuencia de nodos que conectan, mediante aristas, con sus descendentes.

*/
