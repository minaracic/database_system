#include "database.h"
#include "gtest/gtest.h"
#include "table/table.h"
#include "column_data_info/column_data_info.h"
#include "data_types/data_types.h"

class DatabaseTest : public testing::Test{
protected:
    void SetUp() override{
        try{
            test_database.insertTable(&test_table1);
            test_database.insertTable(&test_table1);
            test_database.insertTable(&test_table2);
        }catch(NotUniqueTableName n){
            std::cout << n.what();
        }

        test_table1.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Height", false));
        test_table1.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Profile", false));

        test_table2.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Height", false));
        test_table2.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Last name", false));
        test_table2.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "First name", false));
    }

    Database test_database = Database("test_database");
    Table test_table1 = Table("test_table1");
    Table test_table2 = Table("test_table2");
};


TEST(TestTable, createNewTableAndCheckSetName) {
    Table t = Table("test_table");
    ASSERT_EQ(t.getTableName(), "test_table");
}

TEST_F(DatabaseTest, addDataInTable) {
    bool inserted = test_table1.insertData({new Double(20.3), new Varchar30("Profile1")});
    ASSERT_TRUE(inserted);
}

TEST(TestTable, addOneColumnAndCheckIfAddedCorrectly) {
    Table t = Table("test_table");
    t.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Name", false));
    ASSERT_EQ(t.getColumnsInfo().size(), 2);
}

TEST(TestTable, addTwoColumnsAndCheckIfAddedCorrectly) {
    Table t = Table("test_table");
    t.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Name", false));
    t.insertColumn(ColumnDataInfo(DataType::FLOAT, "Weight", false));
    ASSERT_EQ(t.getColumnsInfo().size(), 3);
}

TEST(TestTable, addDataAndCheckIfAddedCorrectly) {
    Table t = Table("test_table");
    t.insertColumn(ColumnDataInfo(DataType::VARCHAR30, "Name", false));
    t.insertColumn(ColumnDataInfo(DataType::DOUBLE, "Weight", false));

    std::vector<DataValue*> data = {new Varchar30("Mina"), new Double(30.3)};
    bool added_correctly = t.insertData(data);
    ASSERT_EQ(added_correctly, true);
    t.printTable();
}

int main(int argc, char** argv) {
//    std::cout << "Executing tests ";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}