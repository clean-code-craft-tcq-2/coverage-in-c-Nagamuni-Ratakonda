#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(PASSIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(inferBreach(PASSIVE_COOLING,36) == TOO_HIGH);
  REQUIRE(inferBreach(PASSIVE_COOLING,0) == NORMAL);
  REQUIRE(inferBreach(PASSIVE_COOLING,35) == NORMAL);
}
