#include <stdio.h>

#include "hash_table.h"

int main() {
  hash_table *table = ht_new();
  delete_hash_table(table);
  printf("Done!\n");
  return 0;
}
