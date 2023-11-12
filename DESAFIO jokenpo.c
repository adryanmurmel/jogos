#include <stdio.h>
#include <stdlib.h>

int main()
{
    int humano, computador, i;

    printf("****Jogo pedra, papel, tesoura, lagarto e Spock*****\n");
    printf("Humano escolha a sua jogada:\n");
    printf("0 -> Pedra\n");
    printf("1 -> Papel\n");
    printf("2 -> Tesoura\n");
    printf("3 -> Lagarto\n");
    printf("4 -> Spock\n");
    printf("A escolha foi: ");
    scanf("%d", &humano);

    if (humano < 0 || humano > 4)
    {
    }

    // Gera um numero aleatorio
    for (i = 0; i < 1; i++)
    {
        srand(time(NULL));
        computador = rand() % 5;

        if (computador == 0)
        {
            printf("O computador escolheu Pedra\n");
        }

        else if (computador == 1)
        {
            printf("O computador escolheu Papel\n");
        }

        else if (computador == 2)
        {
            printf("O computador escolheu Tesoura\n");
        }

        else if (computador == 3)
        {
            printf("O computador escolheu Lagarto\n");
        }

        else if (computador == 4)
        {
            printf("O computador escolheu Spock\n");
        }
    }

    // Caso haja um empate
    if (humano == computador)
        printf("FOI UM EMPATE!!\n");

    // Condicao de vitoria de tesoura sobre papel
    else if (humano == 2 && computador == 1 || computador == 2 && humano == 1)
    {
        if (humano == 2)
            printf("Tesoura corta Papel, O humano venceu");
        else
            printf("Tesoura corta Papel, O computador venceu");
    }

    // Condicao de vitoria de papel sobre pedra
    else if (humano == 1 && computador == 0 || computador == 1 && humano == 0)
    {
        if (humano == 1)
            printf("Papel cobre Pedra, O humano venceu");
        else
            printf("Papel cobre Pedra, O computador venceu");
    }

    // Condicao de vitoria de pedra sobre lagarto
    else if (humano == 0 && computador == 3 || computador == 0 && humano == 3)
    {
        if (humano == 0)
            printf("Pedra esmaga Lagarto, o humano venceu");
        else
            printf("Pedra esmaga Lagarto, o computador venceu");
    }

    // Condicao de vitoria de lagarto sobre spock
    else if (humano == 3 && computador == 4 || computador == 3 && humano == 4)
    {
        if (humano == 3)
            printf("Lagarto envena Spock, o humano venceu");
        else
            printf("Lagarto envena Spock, o computador venceu");
    }

    // Condicao de vitoria de spock sobre tesoura
    else if (humano == 4 && computador == 2 || computador == 4 && humano == 2)
    {
        if (humano == 4)
            printf("Spock esmaga Tesoura, o humano venceu");
        else
            printf("Spock esmaga Tesoura, o computador venceu");
    }

    // Condicao de vitoria de tesoura sobre lagarto
    else if (humano == 2 && computador == 3 || computador == 2 && humano == 3)
    {
        if (humano == 2)
            printf("Tesoura decapita Lagarto, o humano venceu");
        else
            printf("Tesoura decapita Lagarto, o computador venceu");
    }

    // Condicao de vitoria de lagarto sobre papel
    else if (humano == 3 && computador == 1 || computador == 3 && humano == 1)
    {
        if (humano == 3)
            printf("Lagarto come Papel, o humano venceu");
        else
            printf("Lagarto come Papel, o computador venceu");
    }

    // Condicao de vitoria de papel sobre spock
    else if (humano == 1 && computador == 4 || computador == 1 && humano == 4)
    {
        if (humano == 3)
            printf("Papel refuta Spock, o humano venceu");
        else
            printf("Papel refuta Spock, o computador venceu");
    }

    // Condicao de vitoria de spock sobre pedra
    else if (humano == 4 && computador == 0 || computador == 4 && humano == 0)
    {
        if (humano == 4)
            printf("Spock vaporiza Pedra, o humano venceu");
        else
            printf("Spock vaporiza Pedra, o computador venceu");
    }

    // Condicao de vitoria de pedra sobre tesoura
    else if (humano == 0 && computador == 2 || computador == 0 && humano == 2)
    {
        if (humano == 4)
            printf("Pedra amassa tesoura, o humano venceu");
        else
            printf("Pedra amassa tesoura, o computador venceu");
    }
}
