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

    SECTION("AddFirst_doubleArraySizeWhenFull"){
        // arrange
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);
        deque.addFirst(4);
        deque.addFirst(5);

        // act
        int length = deque.arrayLength();

        // assert
        REQUIRE(length == 8);
    }

    SECTION("AddLast_doubleArraySizeWhenFull"){
        // arrange
        deque.addLast(1);
        deque.addLast(2);
        deque.addLast(3);
        deque.addLast(4);
        deque.addLast(5);

        // act
        int length = deque.arrayLength();

        // assert
        REQUIRE(length == 8);
    }

    SECTION("removeFirst_nonemptyDeque"){
        deque.show();
        // Arrange 
        deque.addFirst(1);
        deque.addFirst(2);
        deque.addFirst(3);
        deque.show();

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
        REQUIRE(deque.arrayLength() == 4);
    }

    SECTION("removeFirst_emptyDeque"){
        int val = deque.removeFirst();
        REQUIRE(val == -1);
    }
    
    SECTION("removeLast"){
        // Arrange
        for(int i = 0; i < 5; i++){
            deque.addFirst(i);
        }

        deque.show();

        // Act
        int item_1 = deque.removeLast();
        int item_2 = deque.removeLast();
        int item_3 = deque.removeLast();

        // Assert
        REQUIRE(item_1 == 0);
        REQUIRE(item_2 == 1);
        REQUIRE(item_3 == 2);
    }

    SECTION("removeLast_emptyDeque"){
        // Arrange

        // Act 
        int item = deque.removeLast();

        // Assert
        REQUIRE(item == -1);
    }

    SECTION("removeLast_verifyResize"){
        // Arrange
        for(int i = 0; i < 4; i++){
            deque.addFirst(i);
        }

        // Act
        for(int i = 0; i < 3; i++){
            deque.removeLast();
        }

        // Assert
        REQUIRE(deque.arrayLength() == 2);
    }
}