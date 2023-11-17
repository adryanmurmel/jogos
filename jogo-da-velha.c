#include <stdio.h>
#include <stdlib.h>

char TABULEIRO[3][3];

//---------------------------------
void IMPRIMIR_TABULEIRO()
{
  int L, C;
  printf("\n   TABULEIRO\n");
  printf("=================\n");
  for (L = 0; L < 3; L++)
  {
    for (C = 0; C < 3; C++)
    {
      printf("%c\t", TABULEIRO[L][C]);
    }
    printf("\n");
  }
  printf("=================\n");
}
//---------------------------------
void INICIALIZA_TABULEIRO()
{
  int L, C;
  for (L = 0; L < 3; L++)
  {
    for (C = 0; C < 3; C++)
    {
      TABULEIRO[L][C] = '-';
    }
  }
}
//---------------------------------
void VERIFICA_TABULEIRO(int L, int C, char SIMBOLO_JOGADOR)
{
  if (TABULEIRO[L][C] == '-')
    TABULEIRO[L][C] = SIMBOLO_JOGADOR;
  else
  {
    printf("Posicao ocupada. Digite novamente\n");
    JOGADA(SIMBOLO_JOGADOR);
  }
}
//---------------------------------
void JOGADA(char SIMBOLO_JOGADOR) // X ou O
{
  int L, C;
  printf("\nJogador %c\n", SIMBOLO_JOGADOR);
  do
  {
    printf("Digite a posicao da linha:\n");
    scanf("%d", &L);
    if ((L < 0) || (L > 2))
      printf("Posicao invalida. Informe novamente:\n");
  } while ((L < 0) || (L > 2));
  do
  {
    printf("Digite a posicao da coluna:\n");
    scanf("%d", &C);
    if ((C < 0) || (C > 2))
      printf("Posicao invalida. Informe novamente:\n");
  } while ((C < 0) || (C > 2));
  VERIFICA_TABULEIRO(L, C, SIMBOLO_JOGADOR);
}
//---------------------------------
void VERIFICA_VENCEDOR(char SIMBOLO_JOGADOR)
{
  int L, C, CONT;
  for (L = 0; L < 3; L++)
  {
    CONT = 0;
    for (C = 0; C < 3; C++)
    {
      if (TABULEIRO[L][C] == SIMBOLO_JOGADOR)
        CONT++;
    }
    if (CONT == 3)
    {
      printf("Parabens %c voce ganhou!\n", SIMBOLO_JOGADOR);
      exit(0);
    }
  }
  // validar coluna

  // validacao diagonal principal
  CONT = 0;
  for (L = 0; L < 3; L++)
  {
    for (C = 0; C < 3; C++)
    {
      if ((L == C) && (TABULEIRO[L][C] == SIMBOLO_JOGADOR))
        CONT++;
    }
    if (CONT == 3)
    {
      printf("Parabens %c voce ganhou!\n", SIMBOLO_JOGADOR);
      exit(0);
    }
  }
  // validacao diagonal secundaria
  CONT = 0;
  for (L = 0; L < 3; L++)
  {
    for (C = 0; C < 3; C++)
    {
      if ((L + C == 2) && (TABULEIRO[L][C] == SIMBOLO_JOGADOR))
        CONT++;
    }
    if (CONT == 3)
    {
      printf("Parabens %c voce ganhou!\n", SIMBOLO_JOGADOR);
      exit(0);
    }
  }
}
//---------------------------------
int main()
{
  int CONT;
  INICIALIZA_TABULEIRO();
  IMPRIMIR_TABULEIRO();
  for (CONT = 1; CONT <= 9; CONT++) // jogada
  {
    if (CONT % 2 == 0) // O
    {
      JOGADA('O');
      IMPRIMIR_TABULEIRO();
      if (CONT >= 5)
        VERIFICA_VENCEDOR('O');
    }
    else // X
    {
      JOGADA('X');
      IMPRIMIR_TABULEIRO();
      if (CONT >= 5)
        VERIFICA_VENCEDOR('X');
    }
  }
  system("pause");
  return 0;
}
