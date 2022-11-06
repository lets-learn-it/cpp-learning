#include <iostream>
using namespace std;

int main() {
  int rows = 0, columns = 0;

  cin >> rows >> columns;

  // row length is constant at compile time
  int (*p1)[5] = new int[rows][5]();

  for(int i=0;i<rows;i++) {
    for (int j = 0; j < 5; j++)
    {
      cout << p1[i][j] << " ";
    }
    cout << endl;
  }

  // row length is not constant at compile time
  int **p2 = new int*[rows];
  for(int i=0;i<rows;i++)
    p2[i] = new int[columns];

  for(int i=0;i<rows;i++) {
    for (int j = 0; j < columns; j++)
    {
      cout << p2[i][j] << " ";
    }
    cout << endl;
  }

  delete []p1;
  for(int i=0;i<rows;i++)
    delete []p2[i];
  delete []p2;
  return 0;
}