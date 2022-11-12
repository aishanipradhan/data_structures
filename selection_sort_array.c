#include <stdio.h>

int main()
{
  int array[10] = {4, 5, 72, 823, 3, 230, 38, 238, 487, 78};
  int x, y, t, position, new_pos;

  for (x = 0; x < 9; x++)
  {
    position = x;

    for (y = x + 1; y < 10; y++)
    {
      if (array[position] > array[y])
        position = y;
    }
    if (position != x)
    {
      new_pos = array[x];
      array[x] = array[position];
      array[position] = new_pos;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (x = 0; x < 10; x++)
    printf("%d\n", array[x]);

  return 0;
}
