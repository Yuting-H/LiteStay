#include "query.h"
#include "database.h"

query::query() {
    database *db = database::instance();
}
