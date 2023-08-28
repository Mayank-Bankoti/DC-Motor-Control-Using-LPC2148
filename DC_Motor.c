#include <lpc214x.h>

#define MOTOR_EN_PIN    (1 << 1)    // P0.1 - Enable 1 pin for L293D
#define MOTOR_A_PIN     (1 << 4)    // P0.4 - IN1
#define MOTOR_B_PIN     (1 << 5)    // P0.5 - IN2
#define SWITCH_PIN      (1 << 3)    // P0.3 - Switch button




void initGPIO() {
  
    IODIR0 |= (MOTOR_A_PIN | MOTOR_B_PIN | MOTOR_EN_PIN);
    IOCLR0 = (MOTOR_A_PIN | MOTOR_B_PIN | MOTOR_EN_PIN);
    IODIR0 &= ~(SWITCH_PIN);
}


int main() {

    initGPIO();

    while (1) {

		if((IOPIN0 & SWITCH_PIN))
		{
		IOSET0 = MOTOR_A_PIN;
        IOCLR0 = MOTOR_B_PIN;
		}
		else
		{
		  IOCLR0 = MOTOR_A_PIN;
        IOSET0 = MOTOR_B_PIN;
		}

    }

    return 0;
}
