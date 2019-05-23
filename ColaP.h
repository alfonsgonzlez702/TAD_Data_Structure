typedef Cola ColaP;

ColaP nuevaP() { return nueva(); }

int esnuevaP(ColaP p) { return esnueva(p); }

Elem primeroP(ColaP p) { return primero(p); }

ColaP desformarP(ColaP p) { return desformar(p); }

ColaP formarP(ColaP p, Elem e) {
	ColaP t = nuevaP();
	if(esnuevaP(p))
		return formar(p,e);

	else if(esMayor(e,primeroP(p))){	
		t = formar(t,e);
		while(!esnuevaP(p)) {
			t = formar(t,primeroP(p));
			p = desformarP(p);
			
		}	
	}
	else {
		if(esIgual(e,primeroP(p))){
			while(!esnuevaP(p) && esIgual(e,primeroP(p))) {
				t = formar(t,primeroP(p));
				p = desformarP(p);
			}
			t = formar(t,e);
			
			if(!esnuevaP(p)) {
				while(!esnuevaP(p)) {
					t = formar(t,primeroP(p));
					p = desformarP(p);
				}
			}
		}
		else
			t = formarP(formarP(desformar(p), e), primeroP(p));
	}

	return t;
}
/*
ColaP formarP(ColaP p, Elem e) {
	ColaP t = nuevaP();
	if(esnuevaP(p))
		return formar(p,e);

	else if(esMayor(e,primeroP(p))){
		t = formar(t,e);
		while(!esnuevaP(p)) {
			t = formar(t,primeroP(p));
			p = desformarP(p);
		}
	}
	else
		t = formarP(formarP(desformar(p), e), primeroP(p));

	return t;
}
*/
 void ImpColaP(ColaP p) {
 	ImpCola(p);
 }