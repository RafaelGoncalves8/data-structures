#ifndef hash_h
#define hash_h

/* 
 * For each name 1 char for first letter, 15 char for last name and 1 char for '\0'. */
#define MAX_CHAR 34
#define MAX_ENTRIES 2048

typedef struct hash
{
    char v[MAX_ENTRIES][MAX_CHAR];  /* Tabela de valores da hash. */
} Hash;

typedef Hash * p_hash;

#endif
