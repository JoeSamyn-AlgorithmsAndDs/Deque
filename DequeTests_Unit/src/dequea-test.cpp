#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include "deque_a.h"

TEST_CASE("DequeA Tests", "[AddLast]"){
    DequeA deque;
    
    SECTION("AddLast"){
        // Arrange

        // Act
        deque.addLast(1);
        deque.addLast(1);
        deque.addLast(2);
        deque.show();

        // Assert
        REQUIRE(deque.size() == 3);
    }

    SECTION("AddLast_ValidateCyclicInsert"){

        REQUIRE(1 == 1);
    }

    SECTION("AddFirst"){
        // Arrange 

        // Act 
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);
        deque.show();

        // Assert
        REQUIRE(deque.size() == 3);
    }

    SECTION("removeFirst_nonemptyDeque"){
        // Arrange 
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);

        // Act
        int expected_1 = deque.removeFirst();
        int expected_2 = deque.removeFirst();
        int expected_3 = deque.removeFirst();
        deque.show();

        // Assert
        REQUIRE(expected_1 == 3);
        REQUIRE(expected_2 == 2);
        REQUIRE(expected_3 == 1);
        REQUIRE(deque.size() == 0);
    }

    SECTION("removeFirst_resize"){
        // Arrange 
        for(int i = 0; i < 9; i++){
            deque.addFirst(i);
        }

        // Act
        for(int i = 0; i <=6; i++){
            deque.removeFirst();
        }

        deque.show();

        // Assert
        REQUIRE(deque.arrayLength() == 8);
    }

    SECTION("removeFirst_emptyDeque"){
        int val = deque.removeFirst();
        REQUIRE(val == -1);
    }
    
}