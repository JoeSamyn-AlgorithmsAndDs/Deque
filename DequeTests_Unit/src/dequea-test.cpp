#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "deque_a.h"

TEST_CASE("DequeA Tests", "[AddLast]"){
    DequeA deque;
    
    SECTION("Add Last"){
        deque.addLast(1);
        deque.show();
        REQUIRE(deque.size() == 1);
    }
}