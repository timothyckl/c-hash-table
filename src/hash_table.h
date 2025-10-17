typedef struct {
  char *key;
  char *value;
} ht_item;

typedef struct {
  int size;
  int count;
  ht_item **items;
} hash_table;

hash_table *ht_new();

void delete_hash_table(hash_table *table);
