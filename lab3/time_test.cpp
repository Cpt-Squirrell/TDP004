#include "catch.hpp"
#include "Time.h"

TEST_CASE("Clock Initializations", "[clock, initialization]") {
    // Incorrect initialization
    
    // Incorrect string initializations
    REQUIRE_THROWS(Clock{"55:10:40"});
    REQUIRE_THROWS(Clock{"100:10:40"});
    REQUIRE_THROWS(Clock{"20:190:40"});
    REQUIRE_THROWS(Clock{"10:10:992"});
    REQUIRE_THROWS(Clock{"-20:10:40"});
    REQUIRE_THROWS(Clock{"15:-10:40"});
    REQUIRE_THROWS(Clock{"15:10:-40"});
    REQUIRE_THROWS(Clock{"15:1040"});
    REQUIRE_THROWS(Clock{"1510:40"});
    REQUIRE_THROWS(Clock{"151040"});
    REQUIRE_THROWS(Clock{":::"});
    REQUIRE_THROWS(Clock{"10:00:"});
    REQUIRE_THROWS(Clock{":10:"});
    REQUIRE_THROWS(Clock{"::10"});
    REQUIRE_THROWS(Clock{"::10"});
    REQUIRE_THROWS(Clock{"5:0:0"});
    REQUIRE_THROWS(Clock{"0:5:0"});
    REQUIRE_THROWS(Clock{"0:0:5"});
    REQUIRE_THROWS(Clock{"5:00:00"});
    REQUIRE_THROWS(Clock{"00:5:00"});
    REQUIRE_THROWS(Clock{"00:00:5"});
    REQUIRE_THROWS(Clock{"24:00:00"});
    REQUIRE_THROWS(Clock{"24:30:15"});
    
    // AM/ PM initializations
    REQUIRE_THROWS(Clock{"10:30:00 br"});
    REQUIRE_THROWS(Clock{"10:30:00 pp"});
    REQUIRE_THROWS(Clock{"10:30:00 em"});
    REQUIRE_THROWS(Clock{"15:30:00 am"});
    REQUIRE_THROWS(Clock{"15:30:00 pm"});

    // Incorrect integer initializations
    REQUIRE_THROWS(Clock{-10, 0, 0});
    REQUIRE_THROWS(Clock{10, -5, 0});
    REQUIRE_THROWS(Clock{10, 0, -5});
    REQUIRE_THROWS(Clock{50, 0, 0});
    REQUIRE_THROWS(Clock{10, 20, 70});
    REQUIRE_THROWS(Clock{0, 100, 20});
    REQUIRE_THROWS(Clock{0.01, 10, 5});
    REQUIRE_THROWS(Clock{10, 0.05, 5});
    REQUIRE_THROWS(Clock{'5', '1', '2'});
    REQUIRE_THROWS(Clock{' ', ' ', ' '});
    
    // Correct initialization
    REQUIRE_NOTHROW(Clock{}); // Default
    REQUIRE_NOTHROW(Clock{"00:00:00"});
    REQUIRE_NOTHROW(Clock{"10:00:00"});
    REQUIRE_NOTHROW(Clock{"10:10:10"});
    REQUIRE_NOTHROW(Clock{"00:30:50"});
    REQUIRE_NOTHROW(Clock{"05:05:05"});
    REQUIRE_NOTHROW(Clock{"23:59:59"});

    REQUIRE_NOTHROW(Clock{"10:30:00 am"});
    REQUIRE_NOTHROW(Clock{"10:30:00 pm"});

    // Assert correct values are being assigned
    REQUIRE(Clock{}.getHour() == 0);
    REQUIRE(Clock{}.getMinutes() == 0);
    REQUIRE(Clock{}.getSeconds() == 0);

    REQUIRE(Clock{"12:00:00"}.getHour() == 12);
    REQUIRE(Clock{"12:00:00"}.getMinutes() == 0);
    REQUIRE(Clock{"12:00:00"}.getSeconds() == 0);
    
    REQUIRE(Clock{"12:30:00"}.getHour() == 12);
    REQUIRE(Clock{"12:30:00"}.getMinutes() == 30);
    REQUIRE(Clock{"12:30:00"}.getSeconds() == 0);
    
    REQUIRE(Clock{"20:15:30"}.getHour() == 20);
    REQUIRE(Clock{"20:15:30"}.getMinutes() == 15);
    REQUIRE(Clock{"20:15:30"}.getSeconds() == 30);
    
    REQUIRE(Clock{"00:30:00"}.getHour() == 0);
    REQUIRE(Clock{"00:30:00"}.getMinutes() == 30);
    REQUIRE(Clock{"00:30:00"}.getSeconds() == 0);
    
    REQUIRE(Clock{"15:00:59"}.getHour() == 15);
    REQUIRE(Clock{"15:00:59"}.getMinutes() == 00);
    REQUIRE(Clock{"15:00:59"}.getSeconds() == 59);
}

TEST_CASE("To string function", "[clock, functions]") {
    // 24 hour format
    REQUIRE(Clock{}.toString(false) == "00:00:00"); // Default
    REQUIRE(Clock{"12:00:00"}.toString(false) == "12:00:00");
    REQUIRE(Clock{"12:30:00"}.toString(false) == "12:30:00");
    REQUIRE(Clock{"20:15:30"}.toString(false) == "20:15:30");
    REQUIRE(Clock{"15:00:59"}.toString(false) == "15:00:59");
    REQUIRE(Clock{"13:00:00"}.toString(false) == "13:00:00");
    REQUIRE(Clock{"00:00:00"}.toString(false) == "00:00:00");
    REQUIRE(Clock{"00:30:00"}.toString(false) == "00:30:00");
    REQUIRE(Clock{"00:59:59"}.toString(false) == "00:59:59");
    REQUIRE(Clock{"05:05:35"}.toString(false) == "05:05:35");

    // 12 hour format
    REQUIRE(Clock{}.toString(true) == "00:00:00 am"); // Default
    REQUIRE(Clock{"12:00:00"}.toString(true) == "12:00:00 pm");
    REQUIRE(Clock{"12:30:00"}.toString(true) == "12:30:00 pm");
    REQUIRE(Clock{"20:15:30"}.toString(true) == "08:15:30 pm");
    REQUIRE(Clock{"15:00:59"}.toString(true) == "03:00:59 pm");
    REQUIRE(Clock{"13:00:00"}.toString(true) == "01:00:00 pm");
    REQUIRE(Clock{"00:00:00"}.toString(true) == "12:00:00 am");
    REQUIRE(Clock{"00:30:00"}.toString(true) == "12:30:00 am");
    REQUIRE(Clock{"00:59:59"}.toString(true) == "12:59:59 am");
    REQUIRE(Clock{"05:05:35"}.toString(true) == "05:05:35 am");
}

TEST_CASE("From string function", "[clock, functions]") {
    REQUIRE_THROWS(Clock{}.fromString("-10:20:30"));
    REQUIRE_THROWS(Clock{}.fromString("10:-20:30"));
    REQUIRE_THROWS(Clock{}.fromString("10:20:-30"));

    REQUIRE_THROWS(Clock{}.fromString("24:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:60:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:00:60"));

    REQUIRE_THROWS(Clock{}.fromString("48:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:80:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:00:80"));

    REQUIRE(Clock{}.fromString("00:00:00").toString() == "00:00:00");
    REQUIRE(Clock{}.fromString("12:30:00").toString() == "12:30:00");
    REQUIRE(Clock{}.fromString("00:00:35").toString() == "00:00:35");
    REQUIRE(Clock{}.fromString("00:20:00").toString() == "00:20:00");
}

TEST_CASE("Operator++ overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator-- overloads", "[clock, operators]") {
    
}