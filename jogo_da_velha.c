#include <stdio.h>
#include <stdlib.h>

typedef enum { Continua, Vitoria, Empate } Estado;

void mostrar_jogo(char casas[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %c ", casas[i][j]);

      if (j == 2) {
        printf("\n");
      } else {
        printf("|");
      }
    }

    if (i != 2)
      printf("-----------\n");
  }
}

void ler_jogada(char casas[3][3], char turno) {
  int linha, coluna;

  // TODO: Mostrar uma mensagem quando o jogador digitar algo inválido
  do {
    scanf("%d%d", &linha, &coluna);
  } while (((linha < 0 || linha > 2) && (coluna < 0 || coluna > 2)) || (casas[linha][coluna] != ' '));

  casas[linha][coluna] = turno;
}

Estado validar_jogo(char casas[3][3]) {
  // horizontal
  for (int i = 0; i < 3; i++) {
    if (casas[i][0] == casas[i][1] && casas[i][0] == casas[i][2] && casas[i][0] != ' ')
      return Vitoria;
  }

  // vertical
  for (int i = 0; i < 3; i++) {
    if (casas[0][i] == casas[1][i] && casas[0][i] == casas[2][i] && casas[0][i] != ' ')
      return Vitoria;
  }

  // diagonal
  if (casas[0][0] == casas[1][1] && casas[0][0] == casas[2][2] && casas[0][0] != ' ')
    return Vitoria;
  if (casas[2][0] == casas[1][1] && casas[2][0] == casas[0][2] && casas[2][0] != ' ')
    return Vitoria;

  // empate
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (casas[i][j] == ' ')
        return Continua;
    }
  }

  return Empate;
}

void limpar(char casas[3][3]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      casas[i][j] = ' ';
}

int main() {
  char casas[3][3] = {
    { ' ', ' ', ' '},
    { ' ', ' ', ' '},
    { ' ', ' ', ' '}
  };
  Estado estado_do_jogo = Continua;
  char turno = 'X';
  char continuar;

  while (estado_do_jogo == Continua) {
    system("clear"); // Limpar terminal
    printf("Vez do jogador %c\n", turno);
    mostrar_jogo(casas);
    ler_jogada(casas, turno);
    estado_do_jogo = validar_jogo(casas);

    if (estado_do_jogo == Vitoria) {
      system("clear");
      mostrar_jogo(casas);
      printf("Jogador %c venceu\n", turno);

      printf("Jogar novamente? [s/n] ");
      getchar(); // Limpar buffer
      scanf("%c", &continuar);

      if (continuar == 's') {
        estado_do_jogo = Continua;
        turno = 'X';
        limpar(casas);
        continue;
      }
    }

    if (estado_do_jogo == Empate) {
      system("clear");
      mostrar_jogo(casas);
      printf("O jogo deu velha\n");

      printf("Jogar novamente? [s/n] ");
      getchar();
      scanf("%c", &continuar);

      if (continuar == 's') {
        estado_do_jogo = Continua;
        turno = 'X';
        limpar(casas);
        continue;
      }
    }

    turno = (turno == 'X') ? 'O' : 'X'; 
  }

  return 0;
}
