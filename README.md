# TAD_Data_Structure
Lista de TDA de las distintas  estructuras de datos

El tipo de dato Elem requiere su propio archivo .h para poder ser implementado con las demás.
EJEMPLO:


	#include<string.h>

	typedef char * Cardinal;
	typedef char* Cadena;
	typedef struct elem{
		Cadena Esp, Eng, key;
	}*Elem;

	Elem creaElem(Cadena espagnol, Cadena ingles) {
		Elem e = (Elem)malloc(sizeof(struct elem));
			e->Eng = ingles;
			e->Esp = espagnol;
			e->key = ingles;
		return e;
	}

	void ImpElem(Elem e) {
		printf("[%s, %s], ",e->Esp, e->Eng);
	}

	Cadena getEsp(Elem e) {
		return e->Esp;
	}

	Cadena getKey(Elem e) {
		return e->key;
	}

	void ImpEsp(Elem e) {
		printf("\n[%s]",e->Esp);
	}

	int hashing(Cadena str, int m) {
		int codhash = 1, i;
		for (i = 0; i < strlen(str); i++) {
			codhash = codhash * (str[i]);
		}
		if (codhash < 0) codhash = -codhash;
		printf("Cardinal: %s --> %d", str, codhash % m);
		getchar();
		return codhash % m;
	}

	int EsIgual(Elem e1, Elem e2) { 
		return strcmp(e1->Eng,e2->Eng); 
	}

	int EsIgualCard(Cardinal a, Elem e) {
		printf("Comparando %s & %s", a, e->Eng);
		if (strcmp(e->Eng, a) == 0)
			return 1;
		else
			return 0;
	}
	int EsMenor(Elem e1, Elem e2) { return e1 < e2; }
	int EsMayor_o_Igual(Elem e1, Elem e2) { return e1 >= e2; }
