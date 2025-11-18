#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROM_NAME_LENGTH 21

/** Representa um node de uma árvore binaria, como também uma sala da mansão. */
typedef struct Rom
{
    char name[ROM_NAME_LENGTH];
    struct Rom * left;
    struct Rom * right;
} Rom;

/**
 * @brief Faz a criação de um node que representa uma sala da mensão.
 * @param name Constante contendo o nome da sala.
 */
Rom * createRom(char * name)
{
    Rom * rom = (Rom *) malloc(sizeof(Rom));
    if (rom == NULL) exit(1);

    strncpy(rom->name, name, ROM_NAME_LENGTH - 1);
    rom->name[ROM_NAME_LENGTH] = '\0';
    rom->right = NULL;
    rom->left = NULL;
    return rom;
}

/**
 * @brief Faz um percuso de pós-ordem na árvore binaria que representa a mansão, sempre questionando a próxima direção que o usuário deseja seguir.
 * @param rom Ponteiro para uma sala.
 */
void exploreRom(Rom * rom)
{
    if (rom)
    {
        char user_option = 's';
        printf("> voce esta em : %s\n", rom->name);
        printf("> para qual direcao deseja seguir? (l, r, s): ");
        scanf("%c", &user_option);
        getchar();
    
        if (user_option == 'l') return exploreRom(rom->left);
        if (user_option == 'r') return exploreRom(rom->right);
    
        printf("\n> voce escolheu sair, ate mais!");
        return;
    }
    printf("> voce chegou a uma sala sem saida!");
}

/** Fluxo principal do programa. */
int main(void)
{
    //Criando as salas da mansão.
    Rom * mansion = createRom("Hall de entrada");
    
    mansion->left = createRom("Corredor");
    mansion->left->left = createRom("Quarto 01");
    mansion->left->right = createRom("Quarto 02");

    mansion->right = createRom("Sala de estar");
    mansion->right->left = createRom("Jardim");
    mansion->right->right = createRom("Banheiro");

    exploreRom(mansion);
    return 0;
}
