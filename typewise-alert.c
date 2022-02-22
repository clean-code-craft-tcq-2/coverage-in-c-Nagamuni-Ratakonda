#include "typewise-alert.h"
#include <stdio.h>

void (*alertTarget_FuncPtr[])(BreachType)={sendToController,sendToEmail};

CoolingTypeLimits coolingTypeParameterLimit[] = {{PASSIVECOOLING_LOWERLIMIT,PASSIVECOOLING_UPPERLIMIT },
                                               {HI_ACTIVECOOLING_LOWERLIMIT,HI_ACTIVECOOLING_UPPERLIMIT},
                                               {MED_ACTIVECOOLING_LOWERLIMIT,MED_ACTIVECOOLING_UPPERLIMIT}
                                              };

const char* BreachTypeParameters[] = {"NORMAL","TOO_LOW","TOO_HIGH"};


BreachType inferBreach(CoolingType coolingType, double temperatureInC) {
  if(temperatureInC < coolingTypeParameterLimit[coolingType].lowerLimit) {
    return TOO_LOW;
  }
  if(temperatureInC < coolingTypeParameterLimit[coolingType].upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = inferBreach(batteryChar.coolingType,temperatureInC);
  alertTarget_FuncPtr[alertTarget](breachType);
  
  }
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
