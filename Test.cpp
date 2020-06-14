#include "range.hpp"
#include "doctest.h"
TEST_CASE("range check"){
    for (int j=0;j<100;j++){
        for (int i: itertools::range(2,3))
            CHECK(i==2);
    }
}