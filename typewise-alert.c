#include "typewise-alert.h"
#include <stdio.h>

void (*alertTarget_FuncPtr[])(BreachType)={sendToController,sendToEmail};

CoolingTypeLimits coolingTypeParameterLimit[] = {{PASSIVECOOLING_LOWERLIMIT,PASSIVECOOLING_UPPERLIMIT },
                                               {HI_ACTIVECOOLING_LOWERLIMIT,HI_ACTIVECOOLING_UPPERLIMIT},
                                               {MED_ACTIVECOOLING_LOWERLIMIT,MED_ACTIVECOOLING_UPPERLIMIT}
                                              };

const char* BreachTypeParameters[] = {"NORMAL","TOO_LOW","TOO_HIGH"};


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = coolingTypeParameterLimit[coolingType].lowerLimit;
  int upperLimit = coolingTypeParameterLimit[coolingType].upperLimit;

  return (inferBreach(temperatureInC, lowerLimit, upperLimit));
}

BreachType checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = inferBreach(batteryChar.coolingType,temperatureInC);
  alertTarget_FuncPtr[alertTarget](breachType);
  
  return breachType;
  
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %s\n",BreachTypeParameters[breachType]);
}
