/*
Luiggy gosta de fazer amizades e sempre está expandindo sua lista de amigos na rede social ListBook. O ListBook permite que você inclua seus novos amigos em sua 
lista de amizade e os indique também para outros amigos da sua rede, tudo isso dinamicamente, sem limites de amigos na sua rede. Como Luiggy é seu amigo, ele pediu
 que você criasse um programa para facilitar a vida dele com esta tarefa. Para isso, Luiggy teve a seguinte ideia:

O programa deverá ler a lista atual de amigos de Luiggy;
O programa deverá ler a nova lista de amigos de Luiggy;
O programa deverá ler o nome do amigo atual que receberá a nova lista como indicação de amigos.

Entrada
Você deve ler em uma única linha a lista de amigos de Luiggy L, contendo somente o primeiro nome e separados por um espaço em branco. Na segunda linha deve ser 
informada a nova lista de amigos N. Na última linha, o nome do amigo S da rede que deseja indicar também essa nova lista de amigos N. Caso não queira indicar para 
ninguém a nova lista de amigos, basta digitar na última linha a palavra “nao”.

Jones Pedro Carlos Lucas
Juca Valdineia Jovander
Carlos

Jones Pedro Carlos Lucas
Juca Valdineia Jovander
nao

Saída
Seu programa deverá exibir a nova lista de amigos de Luiggy atualizada. Se houver indicação de um amigo da lista, os novos amigos deverão ser inseridos antes do 
nome do amigo indicado. Caso não haja indicação, os novos nomes deverão ser inseridos no fim da lista de amigos de Luiggy.

Jones Pedro Juca Valdineia Jovander Carlos Lucas

Jones Pedro Carlos Lucas Juca Valdineia Jovander

*/


#include <stdio.h>
#include <string.h>

int main() {
    char listaL[200][50], listaN[200][50], indicação[50];
    int qtdL = 0, qtdN = 0;
    char c;

    while (scanf("%s%c", listaL[qtdL++], &c) && c != '\n');

    while (scanf("%s%c", listaN[qtdN++], &c) && c != '\n');

    scanf("%s", indicação);

    int pos = -1;
    if (strcmp(indicação, "nao") != 0) {
        for (int i = 0; i < qtdL; i++) {
            if (strcmp(listaL[i], indicação) == 0) {
                pos = i;
                break;
            }
        }
    }

    if (pos != -1) {
        for (int i = 0; i < pos; i++) printf("%s ", listaL[i]);
        for (int i = 0; i < qtdN; i++) printf("%s ", listaN[i]);
        for (int i = pos; i < qtdL; i++) printf("%s%s", listaL[i], (i == qtdL - 1 ? "" : " "));
    } else {
        for (int i = 0; i < qtdL; i++) printf("%s ", listaL[i]);
        for (int i = 0; i < qtdN; i++) printf("%s%s", listaN[i], (i == qtdN - 1 ? "" : " "));
    }
    
    printf("\n");
    return 0;
}