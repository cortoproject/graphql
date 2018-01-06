
#ifndef GRAPHQL_API_H
#define GRAPHQL_API_H

#include <corto/corto.h>
#include <graphql/parser/parser.h>

#ifdef __cplusplus
extern "C" {
#endif

int16_t graphql_query(const char *query);

#ifdef __cplusplus
}
#endif

#endif /* GRAPHQL_API_H */
