#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item *ht_new_item(const char *key, const char *value) {
  ht_item *item = malloc(sizeof(ht_item));

  item->key = strdup(key);
  item->value = strdup(value);

  return item;
}

hash_table *ht_new() {
  hash_table *table = malloc(sizeof(hash_table));

  table->size = 53;
  table->count = 0;
  table->items = calloc((size_t)table->size, sizeof(ht_item *));

  return table;
}

static void ht_del_item(ht_item *item) {
  free(item->key);
  free(item->value);
  free(item);
}

void delete_hash_table(hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    ht_item *item = table->items[i];
    if (item != NULL) {
      ht_del_item(item);
    }
  }

  free(table->items);
  free(table);
}
