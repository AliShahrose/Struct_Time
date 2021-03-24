#define CATCH_CONFIG_MAIN
#include "Time.h"
#include "catch.hpp"

#include <sstream>


TEST_CASE("Testing time struct")
{       Time time{};
        CHECK (time.h == 0);
        CHECK (time.m == 0);
        CHECK (time.s == 0);}

TEST_CASE ("Assignment")
{
    Time time{10,15,25};
    CHECK (time.h == 10);
    CHECK (time.m == 15);
    CHECK (time.s == 25);
}

TEST_CASE ("is_valid")
{
    Time time{10,15,25};
    Time time2{-1,15,25};
    Time time3{10,-1,25};
    Time time4{10,15,-1};
    Time time5{25,15,25};
    Time time6{10,60,25};
    Time time7{10,15,100};

    CHECK (is_valid(time));
    CHECK_FALSE (is_valid(time2));
    CHECK_FALSE (is_valid(time3));
    CHECK_FALSE (is_valid(time4));
    CHECK_FALSE (is_valid(time5));
    CHECK_FALSE (is_valid(time6));
    CHECK_FALSE (is_valid(time7));
}

TEST_CASE ("is_am")
{
    Time time{22,33,44};
    Time time1{10,33,44};
    CHECK_FALSE (is_am(time));
    CHECK(is_am(time1));
}

TEST_CASE("to_string")

{   Time const t1 {0, 0, 0};
    Time const t2 {4, 8, 9};
    Time const t3{16, 42, 11};

  CHECK(to_string(t1) == "00:00:00");
  CHECK(to_string(t1, true) == "12:00:00[am]");
  CHECK(to_string(t2) == "04:08:09");
  CHECK(to_string(t3) == "16:42:11");
  CHECK(to_string(t3, true) == "04:42:11[pm]");
}

TEST_CASE ("Comparison Operators")
{
    Time t1{10,15,25};
    Time t2{20,25,45};
    Time t3{10,15,25};
    Time t4{20,25,45};
    
    CHECK(t1 == t3);
    CHECK_FALSE(t1 == t2);
    CHECK(t3 != t4);
    CHECK_FALSE(t2 != t4);

    CHECK(t2 > t1);
    CHECK_FALSE(t1 > t2);
   
    CHECK(t2>= t1);
    CHECK_FALSE( t1 >= t2);
    CHECK(t1 >= t3);
    
    CHECK( t1< t2);
    CHECK_FALSE(t2 < t1);
    
    CHECK(t1 <= t2);
    CHECK_FALSE(t2 <= t1);
    CHECK(t2 <= t4);
        
}

TEST_CASE ("Addition Subtraction")
{
    
    Time time{10,25,15};
    time = time + 5;

    CHECK_FALSE (time.s == 15);
    CHECK (time.s == 20);

    time = time - 10;

    CHECK_FALSE (time.s == 20);
    CHECK (time.s == 10);

    Time time2{20,12,50};
    time2 = time2 + 11;

    CHECK_FALSE (time2.s == 50);
    CHECK (time2.m == 13);
    CHECK (time2.s == 1);

    time2 = time2 - 11;

    CHECK (time2.s == 50);
    CHECK (time2.m == 12);
    CHECK (time2.s == 50);
}

 

TEST_CASE("Time++,++Time,Time--,--Time,os,is")

{   Time t1{0, 0, 0};
    Time t2{16, 42, 11};
    Time t3{20, 21, 30};

  Time t{t1};
  CHECK(to_string(t++) == "00:00:00");
  CHECK(to_string(t) == "00:00:01");
  
  t = t1;
  CHECK(to_string(++t) == "00:00:01");
  CHECK(to_string(t) == "00:00:01");
  
  t = t3;
  CHECK(to_string(t++) == "20:21:30");
  CHECK(to_string(t) == "20:21:31");
  
  t = t3;
  CHECK(to_string(++t) == "20:21:31");
  CHECK(to_string(t) == "20:21:31");

 
  t = t1;
  CHECK(to_string(t--) == "00:00:00");
  CHECK(to_string(t) == "23:59:59");
  
  t = t1;
  CHECK(to_string(--t) == "23:59:59");
  CHECK(to_string(t) == "23:59:59");
  
  t = t3;
  CHECK(to_string(t--) == "20:21:30");
  CHECK(to_string(t) == "20:21:29");
  
  t = t3;
  CHECK(to_string(--t) == "20:21:29");
  CHECK(to_string(t) == "20:21:29");


  std::ostringstream os1{};
  os1 << t2;
  CHECK(os1.str() == "16:42:11");
  std::ostringstream os2{};
  os2 << t3;
  CHECK(os2.str() == "20:21:30");

  std::istringstream is1{"09:52:15"};
  Time t_is1{};
  is1 >> t_is1;
  CHECK(to_string(t_is1) == "09:52:15");
  
  std::istringstream is2{"97:110:500"};
  Time t_is2{};
  is2 >> t_is2;
  CHECK(is2.fail());
}