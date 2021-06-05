#include <iostream>

#include "database.h"

int main() {
    Database d("new");
    Table* t=new Table("test_table");
    d.checkTableNameUniqueAndInsertTable(t);
    t->insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Name", false));
    Table* t1=new Table("a");
    d.printTablesInfo();

    return 0;
}
