#include <stdio.h>

typedef enum { Continua, Vitoria, Velha } Estado;

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
  }
}

void ler_jogada(char casas[3][3], char turno) {
  int linha, coluna;

  do {
    scanf("%d%d", &linha, &coluna);
  } while ((linha < 0 || linha > 2) && (coluna < 0 || coluna > 2) && casas[linha][coluna] != ' ');

  casas[linha][coluna] = turno;
}

Estado validar_jogo(char casas[3][3]) {
  // horizontal
  for (int i = 0; i < 3; i++) {
    if (casas[i][0] == casas[i][1] && casas[i][0] == casas[i][2])
      return Vitoria;
  }

  // vertical
  for (int i = 0; i < 3; i++) {
    if (casas[0][i] == casas[1][i] && casas[0][i] == casas[2][i])
      return Vitoria;
  }

  // diagonal
  if (casas[0][0] == casas[1][1] && casas[0][0] == casas[2][2])
    return Vitoria;
  if (casas[2][0] == casas[1][1] && casas[2][0] == casas[0][2])
    return Vitoria;

  // velha
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (casas[i][j] == ' ')
        return Continua;
    }
  }

  return Velha;
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
    printf("Vez do jogador %c\n", turno);

    // mostrar tabuleiro
    mostrar_jogo(casas);

    // TODO
    // ler jogada do usuário (validar)
    // colocar na posição
    ler_jogada(casas, turno);

    // validar jogo (ver se houve vitória)
    estado_do_jogo = validar_jogo(casas);

    // se houver vitória, mostrar
    if (estado_do_jogo == Vitoria) {
      printf("Jogador %c venceu\n", turno);

      printf("Jogar novamente? [s/n]");
      scanf("%c", &continuar);

      if (continuar == 's') {
        estado_do_jogo = Continua;
        turno = 'X';
        continue;
      }
    }

    // se houver velha, mostrar
    if (estado_do_jogo == Velha) {
      printf("O jogo deu velha");

      printf("Jogar novamente? [s/n]");
      scanf("%c", &continuar);

      if (continuar == 's') {
        estado_do_jogo = Continua;
        turno = 'X';
        continue;
      }
    }

    // mudar turno
    turno = (turno == 'X') ? 'O' : 'X'; 
  }

  return 0;
}