#include "query_builder.h"
#include "database.h"

query_builder::query_builder() {
    db = database::instance();

    QString sql_command = "";
}
