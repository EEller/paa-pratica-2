#include <iostream>
#include <vector>

bool isPossible(std::vector<std::vector<int> > & t, int N, int l, int c)  {
  int i, j;

  for (i = 0; i < N; i++) {
    if (t[l][i] == 1)
      return false;
  }

  for (i = 0; i < N; i++) {
    if (t[i][c] == 1)
      return false;
  }

  for (i = l, j = c;  i >= 0 && j >= 0; i--, j--) {
    if (t[i][j] == 1)
      return false;
  }
  for (i = l, j = c; i < N && j < N; i++, j++) {
    if (t[i][j] == 1)
      return false;
  }

  for (i = l, j = c;  i >= 0 && j < N; i--, j++) {
    if (t[i][j] == 1)
      return false;
  }
  for (i = l, j = c; i < N && j >=0; i++, j--) {
    if (t[i][j] == 1)
      return false;
  }

  return true;
}

void execute(std::vector<std::vector<int> >& t, int N, int c) {
  if(c == N) {
    std::cout << "Solução " << std::endl;
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        std::cout << t[x][y] << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
    return;
  }

  for (int i=0; i<N; i++) {
    if(isPossible(t, N, i, c)) {
      t[i][c] = 1;
      execute(t, N, c + 1);
      t[i][c] = 0;
    }
  }
}

void nQueens() {
  int N = 8;

  std::vector<std::vector<int> > tab;

  for (int i=0; i < N; i++) {
    std::vector<int> linha(N);
    tab.push_back(linha);
  }

  execute(tab, N, 0);
}