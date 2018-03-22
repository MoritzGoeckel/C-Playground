//g++ htTest.c -pthread -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include  -Wl,--export-dynamic -pthread -lgmodule-2.0 -lglib-2.0 -o htTest.o

#include <glib.h>
#include <gmodule.h>
#include <stdio.h>

int main(){
        GHashTable* table = g_hash_table_new(g_str_hash, g_str_equal);
        char key[] = "Hallo";
        char value[] = "Welt";

        g_hash_table_insert(table, key, value);

        char* found = (char *) g_hash_table_lookup (table, key);
        printf("\n++ %s ++\n\n", found);

        g_hash_table_destroy(table);

        return 0;
}