#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "deque_a.h"

TEST_CASE("DequeA Tests", "[AddLast]"){
    DequeA deque;
    
    SECTION("AddLast"){
        deque.addLast(1);
        deque.addLast(1);
        deque.addLast(2);
        deque.show();
        REQUIRE(deque.size() == 3);
    }
}