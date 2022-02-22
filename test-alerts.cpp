#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

/*
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(PASSIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(inferBreach(PASSIVE_COOLING,36) == TOO_HIGH);
  REQUIRE(inferBreach(PASSIVE_COOLING,0) == NORMAL);
  REQUIRE(inferBreach(PASSIVE_COOLING,35) == NORMAL);
  
  REQUIRE(inferBreach(HI_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(inferBreach(HI_ACTIVE_COOLING,46) == TOO_HIGH);
  REQUIRE(inferBreach(HI_ACTIVE_COOLING,0) == NORMAL);
  REQUIRE(inferBreach(HI_ACTIVE_COOLING,45) == NORMAL);
  
  REQUIRE(inferBreach(MED_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(inferBreach(MED_ACTIVE_COOLING,41) == TOO_HIGH);
  REQUIRE(inferBreach(MED_ACTIVE_COOLING,0) == NORMAL);
  REQUIRE(inferBreach(MED_ACTIVE_COOLING,40) == NORMAL);
}
*/

TEST_CASE("Check and alert if there is a breach in Passive cooling via controller") {
  AlertTarget alertTarget = TO_CONTROLLER;
  BatteryCharacter batteryChar = {PASSIVE_COOLING,"BatteryBrandXYZ"};
  REQUIRE(checkAndAlert(alertTarget, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 36 ) == TOO_HIGH);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 0) == NORMAL);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 35) == NORMAL);
  
}

TEST_CASE("Check and alert if there is a breach in HI_Active cooling via controller") {
  AlertTarget alertTarget = TO_CONTROLLER;
  BatteryCharacter batteryChar = {HI_ACTIVE_COOLING,"BatteryBrandXYZ"};
  REQUIRE(checkAndAlert(alertTarget, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 46 ) == TOO_HIGH);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 0) == NORMAL);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 45) == NORMAL);
  
}

TEST_CASE("Check and alert if there is a breach in MED_Active cooling via controller") {
  AlertTarget alertTarget = TO_CONTROLLER;
  BatteryCharacter batteryChar = {MED_ACTIVE_COOLING,"BatteryBrandXYZ"};
  REQUIRE(checkAndAlert(alertTarget, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 41 ) == TOO_HIGH);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 0) == NORMAL);
  REQUIRE(checkAndAlert(alertTarget, batteryChar, 40) == NORMAL);
  
}

/*
TEST_CASE("Check and alert if there is a breach via email") {
  AlertTarget alertTarget = TO_EMAIL;
  BatteryCharacter batteryChar = {PASSIVE_COOLING,"BatteryBrandXYZ"};
  double temperatureInC = PASSIVECOOLING_LOWERLIMIT ;
  REQUIRE(checkAndAlert(alertTarget, batteryChar, temperatureInC) == NORMAL);
}
*/
