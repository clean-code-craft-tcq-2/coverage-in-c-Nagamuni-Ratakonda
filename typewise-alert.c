#include "typewise-alert.h"
#include <stdio.h>

CoolingTypeLimits coolingTypeParameterLimit[] = {{PASSIVECOOLING_LOWERLIMIT,PASSIVECOOLING_UPPERLIMIT },
                                               {HI_ACTIVECOOLING_LOWERLIMIT,HI_ACTIVECOOLING_UPPERLIMIT},
                                               {MED_ACTIVECOOLING_LOWERLIMIT,MED_ACTIVECOOLING_UPPERLIMIT}
                                              };


BreachType inferBreach(CoolingType coolingType, double temperatureInC) {
  if(temperatureInC < coolingTypeParameterLimit[coolingType].lowerLimit) {
    return TOO_LOW;
  }
  if(temperatureInC < coolingTypeParameterLimit[coolingType].upperLimit)) {
    return TOO_HIGH;
  }
  return NORMAL;
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = inferBreach(batteryChar.coolingType,temperatureInC);

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
