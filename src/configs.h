#ifndef __CONFS__
#define __CONFS__

/* ### WIRING CONFIGS ### */

#define LED1_PIN 13
#define LED2_PIN 12

#define PIR_PIN 2

#define BUTT_PIN 4

#define SERVO_MOTOR_PIN 9

#define SONAR_ECHO 8
#define SONAR_TRIG 7

#define BLINKING_LED 6

#define TEMPERATURE_SENSOR_PIN A0

/* ### ### ### ### ### ### ### ### */


/* ### REQUEST VARIABLE ### */

#define N1_TIME 3000
#define N2_TIME 3000
#define N3_TIME 10000
#define N4_TIME 3000

/* ### ### ### ### ### ### ### ### */


/* ### TASK VARIABLE ### */

#define SCHEDULE_BASE_PERIOD (100)

#define PIR_PERIOD (SCHEDULE_BASE_PERIOD * 4)
#define LED_BLINKING_PERIOD SCHEDULE_BASE_PERIOD
#define SERVO_MOTOR_PERIOD SCHEDULE_BASE_PERIOD
#define BUTTON_PERIOD (SCHEDULE_BASE_PERIOD)
#define SONAR_PERIOD (SCHEDULE_BASE_PERIOD * 2)

#define BLINK_DELTA_1 (BLINK_DELTA_2*5)
#define BLINK_DELTA_2 (25)

/* ### ### ### ### ### ### ### ### */



/* ### STRING TO LCD ### */

#define WELCOME_STRING "Welcome"
#define PRE_ENTERING_STRING "Proceed to the Washing Area"
#define WAITING_STRING "Ready to Wash"
#define PRE_WASHING_DONE_STRING "Washing complete, you can leave the area"
#define ERROR_STRING "Detected a Problem - Please Wait"

/* ### ### ### ### ### ### ### ### */



/* ### DEBUGGING VARIABLE ### */

#define DEBUG
#ifdef DEBUG

//#define SCHEDULER_INIT_PHASE
//#define SCHEDULER_PERIOD_DEBUG

//#define PIR_DEBUG //valuta se eliminarmi
//#define SERVO_MOTOR_DEBUG
//#define SONAR_DEBUG
#define TEMP_DEBUG
#define LCD_DEBUG

//#define SONAR_DEBUG_LEFTING

//#define STATE_CHANGE_DEBUG //TODO, quasi

#endif

/* ### ### ### ### ### ### ### */


#endif
