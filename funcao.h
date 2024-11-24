//
// Created by Marcos on 05/10/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef FUNCAO_H
#define FUNCAO_H

//Variaveis
struct referencia {
    int ref;
    char fault;
};

struct pagina {
    int *processo;
    int ref_processo;
    bool r;
};

extern struct referencia *referencia;
extern struct pagina *pagina;


// Definition of functions
void inicializar();
void entrada ();
void sair();
void executar();
void inicia_paginas();
bool falta_pagina();
void rodar_pagina();
void imprimir();
void reiniciar();

#endif //FUNCAO_H
