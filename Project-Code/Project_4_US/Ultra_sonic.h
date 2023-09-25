/*
 * Ultra_sonic.h
 *
 *  Created on: Jun 16, 2023
 *      Author: dabou
 */

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include "std_types.h"

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);



#endif /* ULTRA_SONIC_H_ */
