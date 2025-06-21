#include "../src/data_types/data_types.h"
//#include "../src/database_exceptions/exceptions.h"

#include <gtest/gtest.h>

int foo(INT_TYPE val) {
   return val.get_val();
}

TEST(DataTypesTest, Creation) {
    INT_TYPE i(3);
    ASSERT_EQ(i.get_val(), 3);

    INT_TYPE negative_int(-1233);
    ASSERT_EQ(negative_int.get_val(), -1233);

    DOUBLE_TYPE d(23.0);
    ASSERT_EQ(d.get_val(), 23.0);

    // Testing explicit constructor.
    ASSERT_EQ(foo(INT_TYPE(3)), 3);

    ASSERT_THROW(INT_TYPE int_overflow(33000), INT_TYPEOverflow);
}


