#include  <stdio.h>
#include  "funcao.h"


int main() {
    inicializar();
    int OP = 0;

    enum{
        INSERIR = 1,
       EXECUTAR,
       SAIR
       };
do {
    printf("\n\nMenu:\n\n");
    printf("1- Inserir dados\n2- Executar segunda chance\n3- Sair\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d",&OP);

    switch (OP) {
        case INSERIR:
            entrada();
        break;

        case EXECUTAR:
           executar();
        break;

        case SAIR:
            sair();
        break;

        default:
            printf("Opcao nao encontrada");
        break;
    }

}while(OP!=3);

}