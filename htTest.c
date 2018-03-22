#include <glib.h> //Only on linux...

GHashTable* table = g_hash_table_new(g_str_hash(), g_str_equal());
char key[] = "Hallo";
char value[] = "Welt";

g_hash_table_insert(table, key, value);