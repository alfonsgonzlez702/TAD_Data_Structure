typedef Arbin DicBin;

DicBin InsOrdAB(Elem e, DicBin db) {
	if(esnuevoAB(db))
		return consAB(e, nuevoAB(), nuevoAB());
		
	else if(EsMenor(e, raiz(db))) 
		return consAB(raiz(db), InsOrdAB(e, hijoI(db)), hijoD(db));
		
	else
		return consAB(raiz(db), hijoI(db), InsOrdAB(e, hijoD(db)));
}

int estaEn(Elem e, DicBin db) {
	if(esnuevoAB(db))
		return 0;
	else if(EsIgual(e,raiz(db)))
			return 1;
		else if(EsMenor(e,raiz(db)))
				return estaEn(e, hijoI(db));
			else
				return estaEn(e, hijoD(db));
}

int MaxElem(DicBin db) {
	if(esnuevoAB(hijoI(db)) && esnuevoAB(hijoD(db)))
		return raiz(db);
	else if(esnuevoAB(hijoI(db)))
			return raiz(db);
		else
			return MaxElem(hijoD(db));
}

int MinElem(DicBin db) {
	if(esnuevoAB(hijoI(db)) && esnuevoAB(hijoD(db)))
		return raiz(db);
	else if(esnuevoAB(hijoD(db)))
			return raiz(db);
		else
			return MaxElem(hijoI(db));
}

DicBin borraElem(Elem e, DicBin db) {
	if(esnuevoAB(hijoI(db)) && esnuevoAB(hijoD(db)))
		return nuevoAB();
	else if(EsIgual(e,raiz(db))) 
			if(!esnuevoAB(hijoI(db)) && !esnuevoAB(hijoD(db)))
				return consAB(MaxElem(hijoI(db)), borraElem(MaxElem(hijoI(db)), hijoI(db)),hijoD(db));
			else if(esnuevoAB(hijoI(db)))
					return hijoD(db);
				else
					return hijoI(db);
		else if(EsMenor(e, raiz(db)))
				return consAB(raiz(db), borraElem(e, hijoI(db)), hijoD(db));
			else
				return consAB(raiz(db), hijoI(db), borraElem(e, hijoD(db)));
}
