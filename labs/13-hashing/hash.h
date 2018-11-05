#ifndef hash_h
#define hash_h


#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* 1 char para primeira letra, 15 char para sobrenome e 1 char '\0'. */
#define MAX_CHAR_NAME 17
/* 16 char para cada um dos dois nomes, 1 char '\0'. */
#define MAX_CHAR_ENTRY 33
#define MAX_ENTRIES 2048
/* Numero primo e longe de potencia de dois. */
#define M 2017

typedef struct hash
{
    char v[MAX_ENTRIES][MAX_CHAR_ENTRY]; /* Tabela de valores da hash. */
} Hash;

typedef Hash * p_hash;

/* Cria tabela de hash. */
p_hash
create_hash_table();

/* Checa se existe entrada key na tabela h. */
int
exist_entry(p_hash h, char * key);

/* Adiciona entrada key para a tabela h caso ainda nao exista. */
void
add_entry(p_hash h, char * key);

/* Destroi estrutura h liberando memoria alocada dinamicamente. */
void
destroy_hash_table(p_hash h);

#endif
