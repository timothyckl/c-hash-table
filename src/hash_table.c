#include "hash_table.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }

  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

static int ht_hash(const char *string, const int alpha, const int num_buckets) {
  const int len_str = strlen(string);

  if (!is_prime(alpha) || alpha < len_str) {
    fprintf(stderr, "Error: alpha must be a prime number greater than the "
                    "string length.\n");
    exit(EXIT_FAILURE);
  }

  long hash = 0;

  for (int i = 0; i < len_str; i++) {
    hash += (long)pow(alpha, len_str - (i + 1)) * string[i];
    hash = hash % num_buckets;
  }

  return (int)hash;
}
