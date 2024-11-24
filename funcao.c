
#include "funcao.h"


int page = 0, size = 20, indice = 0, clock = 0, roda_pagina = 0, controle = 0;
bool executado, page_fault;

struct referencia *referencia = NULL;
struct pagina *pagina = NULL;

void inicializar() {
    referencia= malloc(size*sizeof(struct referencia));
}


void resize(){
    size += size/2;
    struct referencia *aux = malloc(size * sizeof(referencia));

    for (int i = 0; i<indice; i++){
        aux[i] = referencia[i];
    }
    free(referencia);
    referencia = aux;
}

void entrada() {
    printf("Digite o numero de paginas:\t");
        scanf("%d",&page);
    printf("Digite os numeros de referencias, para sair digite -1\n");
        while(referencia[indice].ref != -1) {
            if (indice == size){resize();}
            scanf("%d",&referencia[indice].ref);
            if(referencia[indice].ref != -1){indice++;}
        }
    inicia_paginas();
}

void inicia_paginas() {
    pagina = malloc(size*sizeof(pagina));
    for (int i = 0; i<page; i++) {
        pagina[i].processo = malloc(size*sizeof(pagina->processo));
        pagina[i].r = false;
        pagina[i].ref_processo = 0;
            for (int j = 0; j<indice; j++) {
                pagina[i].processo[j] = 0;
            }
    }
}

void executar(){
    while((indice) != clock) {
        executado = false;
        page_fault = false;
        if(falta_pagina() && controle < page) {
            pagina[roda_pagina].ref_processo = referencia[clock].ref;
            pagina[roda_pagina].processo[clock] = pagina[roda_pagina].ref_processo;
            rodar_pagina();
            controle++;
            executado = true;
            page_fault = true;
        }else if(falta_pagina() && !pagina[roda_pagina].r) {
            pagina[roda_pagina].ref_processo = referencia[clock].ref;
            pagina[roda_pagina].processo[clock] = pagina[roda_pagina].ref_processo;
            rodar_pagina();
            executado = true;
            page_fault = true;
        }else if(falta_pagina() && pagina[roda_pagina].r) {
            pagina[roda_pagina].r = false;
            rodar_pagina();
        }else {
            for(int i = 0; i<page; i++) {
                if(referencia[clock].ref == pagina[i].ref_processo) {
                     pagina[i].r = true;
                }
                executado = true;
            }
        }
        if(executado) {
            if(page_fault) {
                referencia[clock].fault = 'S';
            }else {
                referencia[clock].fault = '_';
            }
            clock++;
        }
    }
    imprimir();
    reiniciar();
}

bool falta_pagina() {
    for (int i = 0; i<page; i++) {
        if(pagina[i].ref_processo == referencia[clock].ref) {
            return false;
        }
    }
    return true;
}

void rodar_pagina() {
    if(roda_pagina == page-1) {
        roda_pagina = 0;
    }else {
        roda_pagina++;
    }
}

void imprimir() {
    printf("\nRef.|  ");
    for (int i = 0; i<indice; i++) {
        printf("%d  |  ", referencia[i].ref);
    }
    printf("\n");
    for (int i = 0; i<indice; i++) {
        printf("-------");
    }
    printf("\n");

    for(int i = 0; i<page; i++) {
        printf("Fm%d.|  ", i+1);
        for(int j = 0; j<indice; j++) {
                if(pagina[i].processo[j] != 0) {
                    printf("%d  |  ", pagina[i].processo[j]);
                }else if(pagina[i].processo[j] == 0 && j ==0) {
                    printf("%d  |  ", pagina[i].processo[j]);
                }else {
                    pagina[i].processo[j] = pagina[i].processo[j-1];
                    printf("%d  |  ", pagina[i].processo[j-1]);
                }
        }
        printf("\n");
        for(int j = 0; j<indice; j++) {
            printf("-------");
        }
        printf("\n");
    }
    printf("Fau.|  ");
    for (int i = 0; i<indice; i++) {
        printf("%c  |  ", referencia[i].fault);
    }
}

void reiniciar() {
    page = 0;
    indice = 0;
    clock = 0;
    roda_pagina = 0;
    controle =0;
    size =20;
    struct referencia *referencia = NULL;
    struct pagina *pagina = NULL;
    inicializar();
}

void sair() {
    free(referencia);
    free(pagina);
}
