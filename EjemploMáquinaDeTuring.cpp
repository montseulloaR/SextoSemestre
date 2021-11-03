#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/* Longitud maxima + 1. */
#define MAX_LONG 256

/* Declaracion de variables globales. */
char *estadoActual;
char *funcion = "0^{n}1^{n} | n >= 0";
int i, longitudW;

void estado_q0(char*, int);
void estado_q1(char*, int);
void estado_q2(char*, int);
void estado_q3(char*, int);
void stop(bool);
void addBlankL(char *w);
void addBlankR(char *w);
void salidaTrue();
void salidaFalse();
void printLog(char *w, char *ea, int i, char x, char m, char *e);
void stop(bool resultado);
int linea(int s);
void printTablaMT();

int main(int argc, char *argv[]) {

	/* Se asigna memoria para la cadena w. */
	char *w = malloc(MAX_LONG);

	printf("Introduce una cadena: ");

	/* Guarda la cadena w, con limite de longitud. */
	fgets(w, MAX_LONG, stdin);

	/* Se obtiene la logitud de la cadena de entrada,
	 * sin tener en cuanta el salto de linea. */
	longitudW = strlen(w) - 1;

	/* Elimina salto de linea del final, si existiera. */
	if ((longitudW + 1 > 0) && (w[longitudW] == '\n')) {
		w[longitudW] = '\0';
	}

	/* Primera condicion es que la cadena debe ser par */
	if (strlen(w) % 2 != 0) {
		salidaFalse();
	} else if(strlen(w) == 0){
		/* Acepta la cadena vacia. */
		salidaTrue();
	} else {
		printTablaMT();

		/* Se incorpora un blanco por la izquierda
		 * y otro por la derecha de la cadena w. */
		addBlankL(w);
		addBlankR(w);

		/* Le digo a la maquina de Turing que empiece
		 * por el caracter w[1] en el estado q0 */
		estado_q0(w, 1);
	}

	/* Se libera la memoria reservada para la daena w. */
	free(w);

	return 0;
}

void addBlankL(char *w) {
	/* Recorro el array de derecha a izquierda y desplazo
	 * los caracteres una posicion a la derecha */
	for (i = strlen(w); i > 0; i--) {
		w[i] = w[i - 1];
	}

	/* Concateno la cadena w con un blanco por la izquierda. */
	w[i] = '_';
}

void addBlankR(char *w) {
	/* Concateno la cadena w con un blanco por la derecha. */
	strcat(w, "_");
}

void salidaTrue() {
	printf("\n\nEnhorabuena! se cumple que %s\n\n", funcion);
}

void salidaFalse() {
	printf("\n\nNo se cumple que %s\n\n", funcion);
}

void printLog(char *w, char *ea, int i, char x, char m, char *e) {
	printf(
			"\nw es: \"%s\". Estoy en %s, leo \"%c\", lo cambio por \"%c\", me muevo a la %c y me voy al estado %s.",
			w, ea, w[i], x, m, e);
}

void estado_q0(char *w, int i) {
	estadoActual = "q0";

	// Si leo 0
	if (w[i] == '0') {

		printLog(w, estadoActual, i, 'X', 'R', "q1");

		// lo cambio por X
		w[i] = 'X';

		// me muevo a la derecha (R) y me voy al estado q1.
		estado_q1(w, i += 1);

		// Si leo 1, X o un blanco (_)
	} else if (w[i] == '1' || w[i] == 'X' || w[i] == '_') {

		// se para la maquina de Turing con un resultado false.
		stop(false);

		// Si leo Y
	} else if (w[i] == 'Y') {

		printLog(w, estadoActual, i, 'Y', 'R', "q3");

		// dejo Y sin cambiar, me muevo a la derecha (R) y me voy al estado q3.
		estado_q3(w, i += 1);
	}
}

void estado_q1(char *w, int i) {
	estadoActual = "q1";

	// Si leo 0
	if (w[i] == '0') {

		printLog(w, estadoActual, i, '0', 'R', "q1");

		// dejo 0 sin cambiar, me muevo a la derecha (R) y sigo en el estado q1.
		estado_q1(w, i += 1);

		// Si leo 1
	} else if (w[i] == '1') {

		printLog(w, estadoActual, i, 'Y', 'L', "q2");

		// lo cambio por Y
		w[i] = 'Y';

		// me muevo a la izquierda (L) y me voy al estado q2.
		estado_q2(w, i -= 1);

		// Si leo X o un blanco (_)
	} else if (w[i] == 'X' || w[i] == '_') {

		// se para la maquina de Turing con un resultado false.
		stop(false);

		// Si leo Y
	} else if (w[i] == 'Y') {

		printLog(w, estadoActual, i, 'Y', 'R', "q1");

		// dejo Y sin cambiar, me muevo a la derecha (R) y me voy al estado q1.
		estado_q1(w, i += 1);
	}
}

void estado_q2(char *w, int i) {
	estadoActual = "q2";

	// Si leo 0
	if (w[i] == '0') {

		printLog(w, estadoActual, i, '0', 'L', "q2");

		// dejo 0 sin cambiar, me muevo a la izquierda (L) y sigo en el estado q2.
		estado_q2(w, i -= 1);

		// Si leo 1 o un blanco (_)
	} else if (w[i] == '1' || w[i] == '_') {

		// se para la maquina de Turing con un resultado false.
		stop(false);

		// Si leo X
	} else if (w[i] == 'X') {

		printLog(w, estadoActual, i, 'X', 'R', "q0");

		// dejo X sin cambiar, me muevo a la derecha (R) y me voy al estado q0.
		estado_q0(w, i += 1);

		// Si leo Y
	} else if (w[i] == 'Y') {

		printLog(w, estadoActual, i, 'Y', 'L', "q2");

		// dejo Y sin cambiar, me muevo a la izquierda (L) y me voy al estado q2.
		estado_q2(w, i -= 1);
	}
}

void estado_q3(char *w, int i) {
	estadoActual = "q3";

	// Si leo 0, 1 o X
	if (w[i] == '0' || w[i] == '1' || w[i] == 'X') {

		// se para la maquina de Turing con un resultado false.
		stop(false);

		// Si leo Y
	} else if (w[i] == 'Y') {

		printLog(w, estadoActual, i, 'Y', 'R', "q3");

		// dejo Y sin cambiar, me muevo a la derecha (R) y sigo en el estado q3.
		estado_q3(w, i += 1);

		// Si leo un blanco (_)
	} else if (w[i] == '_') {

		printLog(w, estadoActual, i, '_', 'R', "STOP");

		// se para la maquina de Turing con un resultado true.
		stop(true);
	}
}

void stop(bool resultado) {
	if (resultado) {
		salidaTrue();
	} else {
		salidaFalse();
	}
}

int linea(int s) {
	fprintf(stdout,"+");
	for (int i = 0; i <= s; i++) {
		fprintf(stdout,"-");
	}
	fprintf(stdout,"+\n");
	return 0;
}

void printTablaMT(){
	printf("\nMaquina de Turing para %s\n\n", funcion);
	linea(62);
	printf("|%-5.5s      %-5.5s      %-5.5s      %-5.5s      %-5.5s   %-10.10s |\n", " ", "0", "1", "X", "Y", "    _");
	linea(62);
	printf("|%-5.5s   %-8.8s   %-8.8s   %-8.8s   %-8.8s   %-10.10s |\n", " q0", "(X,R,q1)", "   -", "   -", "(Y,R,q3)", "    _");
	printf("|%-5.5s   %-8.8s   %-8.8s   %-8.8s   %-8.8s   %-10.10s |\n", " q1", "(0,R,q1)", "(Y,L,q2)", "   -", "(Y,R,q1)", "    _");
	printf("|%-5.5s   %-8.8s   %-8.8s   %-8.8s   %-8.8s   %-10.10s |\n", " q2", "(0,L,q2)", "   -", "(X,R,q0)", "(Y,L,q2)", "    _");
	printf("|%-5.5s   %-8.8s   %-8.8s   %-8.8s   %-8.8s   %-10.10s |\n", " q3", "   -", "   -", "   -", "(Y,R,q3)", "(#,R,STOP)");
	linea(62);
}
