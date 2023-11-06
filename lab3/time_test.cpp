#include "catch.hpp"
#include "Time.h"

TEST_CASE("Clock Initialization", "[clock, initialization]") {
    // Default
    REQUIRE_NOTHROW(Clock{});
    REQUIRE(Clock{}.getHour() == 0);
    REQUIRE(Clock{}.getMinutes() == 0);
    REQUIRE(Clock{}.getSeconds() == 0);

    // Integer initializations
    REQUIRE_THROWS(Clock{-10, 0, 0});
    REQUIRE_THROWS(Clock{10, -5, 0});
    REQUIRE_THROWS(Clock{10, 0, -5});
    REQUIRE_THROWS(Clock{50, 0, 0});
    REQUIRE_THROWS(Clock{10, 20, 70});
    REQUIRE_THROWS(Clock{0, 100, 20});

    REQUIRE_NOTHROW(Clock{0, 0, 0});
    REQUIRE_NOTHROW(Clock{12, 0, 0});
    REQUIRE_NOTHROW(Clock{23, 59, 59});
    REQUIRE_NOTHROW(Clock{0, 30, 0});
    REQUIRE_NOTHROW(Clock{0, 0, 30});
}

TEST_CASE("From string function", "[clock, functions]") {
    REQUIRE_THROWS(Clock{}.fromString("55:10:40"));
    REQUIRE_THROWS(Clock{}.fromString("100:10:40"));
    REQUIRE_THROWS(Clock{}.fromString("20:190:40"));
    REQUIRE_THROWS(Clock{}.fromString("10:10:992"));
    REQUIRE_THROWS(Clock{}.fromString("-20:10:40"));
    REQUIRE_THROWS(Clock{}.fromString("15:-10:40"));
    REQUIRE_THROWS(Clock{}.fromString("15:10:-40"));
    REQUIRE_THROWS(Clock{}.fromString("15:1040"));
    REQUIRE_THROWS(Clock{}.fromString("1510:40"));
    REQUIRE_THROWS(Clock{}.fromString("151040"));
    REQUIRE_THROWS(Clock{}.fromString(":::"));
    REQUIRE_THROWS(Clock{}.fromString("10:00:"));
    REQUIRE_THROWS(Clock{}.fromString("-10::"));
    REQUIRE_THROWS(Clock{}.fromString(":-10:"));
    REQUIRE_THROWS(Clock{}.fromString("::-10"));
    REQUIRE_THROWS(Clock{}.fromString("5:0:0"));
    REQUIRE_THROWS(Clock{}.fromString("0:5:0"));
    REQUIRE_THROWS(Clock{}.fromString("0:0:5"));
    REQUIRE_THROWS(Clock{}.fromString("5:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:5:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:00:5"));
    REQUIRE_THROWS(Clock{}.fromString("24:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("24:30:15"));

    REQUIRE_THROWS(Clock{}.fromString("-10:20:30"));
    REQUIRE_THROWS(Clock{}.fromString("10:-20:30"));
    REQUIRE_THROWS(Clock{}.fromString("10:20:-30"));

    REQUIRE_THROWS(Clock{}.fromString("24:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:60:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:00:60"));

    REQUIRE_THROWS(Clock{}.fromString("48:00:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:80:00"));
    REQUIRE_THROWS(Clock{}.fromString("00:00:80"));

    REQUIRE_NOTHROW(Clock{}.fromString("00:00:00"));
    REQUIRE_NOTHROW(Clock{}.fromString("10:00:00"));
    REQUIRE_NOTHROW(Clock{}.fromString("10:10:10"));
    REQUIRE_NOTHROW(Clock{}.fromString("00:30:50"));
    REQUIRE_NOTHROW(Clock{}.fromString("05:05:05"));
    REQUIRE_NOTHROW(Clock{}.fromString("23:59:59"));

    REQUIRE(Clock{}.fromString("00:00:00").getHour() == 0);
    REQUIRE(Clock{}.fromString("00:00:00").getMinutes() == 0);
    REQUIRE(Clock{}.fromString("00:00:00").getSeconds() == 0);

    REQUIRE(Clock{}.fromString("12:30:00").getHour() == 12);
    REQUIRE(Clock{}.fromString("12:30:00").getMinutes() == 30);
    REQUIRE(Clock{}.fromString("12:30:00").getSeconds() == 0);

    REQUIRE(Clock{}.fromString("00:00:35").getHour() == 0);
    REQUIRE(Clock{}.fromString("00:00:35").getMinutes() == 0);
    REQUIRE(Clock{}.fromString("00:00:35").getSeconds() == 35);
    
    REQUIRE(Clock{}.fromString("00:20:00").getHour() == 0);
    REQUIRE(Clock{}.fromString("00:20:00").getMinutes() == 20);
    REQUIRE(Clock{}.fromString("00:20:00").getSeconds() == 0);

    REQUIRE(Clock{}.fromString("12:00:00").getHour() == 12);
    REQUIRE(Clock{}.fromString("12:00:00").getMinutes() == 0);
    REQUIRE(Clock{}.fromString("12:00:00").getSeconds() == 0);

    REQUIRE(Clock{}.fromString("20:15:30").getHour() == 20);
    REQUIRE(Clock{}.fromString("20:15:30").getMinutes() == 15);
    REQUIRE(Clock{}.fromString("20:15:30").getSeconds() == 30);

    REQUIRE(Clock{}.fromString("00:30:00").getHour() == 0);
    REQUIRE(Clock{}.fromString("00:30:00").getMinutes() == 30);
    REQUIRE(Clock{}.fromString("00:30:00").getSeconds() == 0);

    REQUIRE(Clock{}.fromString("15:00:59").getHour() == 15);
    REQUIRE(Clock{}.fromString("15:00:59").getMinutes() == 00);
    REQUIRE(Clock{}.fromString("15:00:59").getSeconds() == 59);

    // AM/ PM
    REQUIRE_THROWS(Clock{}.fromString("10:30:00 br"));
    REQUIRE_THROWS(Clock{}.fromString("10:30:00 pp"));
    REQUIRE_THROWS(Clock{}.fromString("10:30:00 em"));
    REQUIRE_THROWS(Clock{}.fromString("15:30:00 am"));
    REQUIRE_THROWS(Clock{}.fromString("15:30:00 pm"));

    REQUIRE_NOTHROW(Clock{}.fromString("10:30:00 am"));
    REQUIRE_NOTHROW(Clock{}.fromString("10:30:00 pm"));
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

TEST_CASE("Operator++ overloads", "[clock, operators]") {
    Clock testClock{};
    REQUIRE(testClock++ == Clock{});
    REQUIRE(testClock == Clock{0, 0, 1});
    
    testClock = Clock{23, 59, 59};
    REQUIRE(testClock++ == Clock{23, 59, 59});
    REQUIRE(testClock == Clock{0, 0, 0});

    testClock = Clock{12, 30, 0};
    REQUIRE(testClock++ == Clock{12, 30, 0});
    REQUIRE(testClock == Clock{12, 30, 1});

    testClock = Clock{0, 0, 0};
    REQUIRE(++testClock == Clock{0, 0, 1});
    REQUIRE(testClock == Clock{0, 0, 1});

    testClock = Clock{23, 59, 59};
    REQUIRE(++testClock == Clock{0, 0, 0});
    REQUIRE(testClock == Clock{23, 59, 59});
    
    testClock = Clock{12, 30, 0};
    REQUIRE(++testClock == Clock{12, 30, 1});
    REQUIRE(testClock == Clock{12, 30, 1});
}

TEST_CASE("Operator-- overloads", "[clock, operators]") {
    Clock testClock{};
    REQUIRE(testClock-- == Clock{0, 0, 0});
    REQUIRE(testClock == Clock{23, 59, 59});
    
    testClock = Clock{23, 59, 59};
    REQUIRE(testClock-- == Clock{23, 59, 59});
    REQUIRE(testClock == Clock{23, 59, 58});

    testClock = Clock{12, 30, 0};
    REQUIRE(testClock-- == Clock{12, 30, 0});
    REQUIRE(testClock == Clock{12, 29, 59});

    testClock = Clock{0, 0, 0};
    REQUIRE(--testClock == Clock{23, 59, 59});
    REQUIRE(testClock == Clock{23, 59, 59});

    testClock = Clock{23, 59, 59};
    REQUIRE(--testClock == Clock{23, 59, 58});
    REQUIRE(testClock == Clock{23, 59, 58});
    
    testClock = Clock{12, 30, 0};
    REQUIRE(--testClock == Clock{12, 29, 59});
    REQUIRE(testClock == Clock{12, 29, 59});
}

TEST_CASE("Operator+ overloads", "[clock, operators]") {
    REQUIRE(Clock{12, 45, 30} + Clock{12, 45, 30} == Clock{1,30,0});
    REQUIRE(Clock)
}

TEST_CASE("Operator- overloads", "[clock, operators]") {
    REQUIRE(Clock{12,45,30} - Clock{12,45,30} == Clock{0,0,0});
}

TEST_CASE("Operator+= overloads", "[clock, operators]") {

}

TEST_CASE("Operator-= overloads", "[clock, operators]") {

}

TEST_CASE("Operator< overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator<= overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator> overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator>= overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator== overloads", "[clock, operators]") {
    
}

TEST_CASE("Operator!= overloads", "[clock, operators]") {
    
}