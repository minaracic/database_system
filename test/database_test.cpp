#include "database.h"
#include "gtest/gtest.h"
#include "table/table.h"
#include "column_data_info/column_data_info.h"
#include "data_types/data_types.h"
#include <memory>

class DatabaseTest : public testing::Test{
protected:
    void SetUp() override{
        Table test_table1 = Table("test_table1");
        Table test_table2 = Table("test_table2");

        test_table1.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Height", false));
        test_table1.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Profile", false));

        test_table2.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Height", false));
        test_table2.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Last name", false));
        test_table2.insertColumn(ColumnDataInfo(DataType::VARCHARN, "First name", false));

        test_database.insertTable(std::move(test_table1));
        test_database.insertTable(std::move(test_table2));
    }

    Database test_database = Database("test_database");
};


TEST(TestTable, createNewTableAndCheckSetName) {
    Table t = Table("test_table");
    ASSERT_EQ(t.getTableName(), "test_table");
}

TEST_F(DatabaseTest, addDataInTable) {

    Table table{"test_table"};
    table.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Height", false));
    table.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Profile", false));
    //bool inserted = table.insertData({new DOUBLE(20.3), new VARCHARN("Profile1")});
    //ASSERT_TRUE(inserted);
}

TEST_F(DatabaseTest, addTableWithSameNameError) {
    try{
        Database test_database = Database("test_database");
        test_database.insertTable(Table("test_table1"));
    }catch (NotUniqueTableName n){
        ASSERT_EQ("Table with this name already exists!", n.what());
    }
}

TEST(TestTable, addOneColumnAndCheckIfAddedCorrectly) {
    Table t = Table("test_table");
    t.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Name", false));
    ASSERT_EQ(t.getColumnsInfo().size(), 2);
}

TEST(TestTable, addTwoColumnsAndCheckIfAddedCorrectly) {
    Table t = Table("test_table");
    t.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Name", false));
    t.insertColumn(ColumnDataInfo(DataType::FLOAT, "Weight", false));
    ASSERT_EQ(t.getColumnsInfo().size(), 3);
}

// TEST(TestTable, addDataAndCheckIfAddedCorrectly) {
//     Table t = Table("test_table");
//     t.insertColumn(ColumnDataInfo(DataType::VARCHARN, "Name", false));
//     t.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Weight", false));
//
//     std::vector<DataValue*> data = {new VARCHARN("Mina"), new DOUBLE(30.3)};
//     bool added_correctly = t.insertData(data);
//     ASSERT_EQ(added_correctly, true);
//     t.printTable();
// }

TEST(DataValue, TestDataValue) {
    DataValue temp_column = DOUBLE(2.0);
    ASSERT_EQ(get<DOUBLE>(temp_column), 2.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}