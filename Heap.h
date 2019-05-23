typedef Arbin Heap;
/*Precondiciones
	altura(hi)-altura(hd) <= 1
	hi y hd SON HEAP Y COMPLETOS
*/
Heap hazHeap(Elem r, Heap hi, Heap hd) {
	if(esnuevoAB(hi) && esnuevoAB(hd))
		return consAB(r, hi, hd);
	else if(!esnuevoAB(hi) && esnuevoAB(hd))	
			if(EsMayor_o_Igual(r, raiz(hi)))
				return consAB(r, hi, hd);
			else
				return consAB(raiz(hi), consAB(r, nuevoAB(), nuevoAB()), hd);
	else if(esnuevoAB(hi) && !esnuevoAB(hd))
			if(EsMayor_o_Igual(r, raiz(hd)))
				return consAB(r, hi, hd);
			else
				return consAB(raiz(hd), consAB(r, nuevoAB(), nuevoAB()), hi);
		else if(EsMayor_o_Igual(raiz(hi), raiz(hd)))
				if(EsMayor_o_Igual(r, raiz(hi)))
					return consAB(r,hi,hd);
				else
					return consAB(raiz(hi), hazHeap(r, hijoI(hi), hijoD(hi)), hd);
			else if(EsMayor_o_Igual(r, raiz(hd)))
					return consAB(r,hi,hd);
				else
					return consAB(raiz(hd), hi, hazHeap(r, hijoI(hd), hijoD(hd)));
}

Heap consHeap(Arbin a) {
	if(esnuevoAB(a))
		return a;
	else
		return hazHeap(raiz(a), consHeap(hijoI(a)), consHeap(hijoD(a)));
}



