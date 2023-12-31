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


/* ### TASK VARIABLE ### */

#define IDEALLY_TIME (150)

#define SCHEDULE_BASE_PERIOD (150)

#define PIR_PERIOD 150//((int)(SCHEDULE_BASE_PERIOD * 4.5 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))
#define LED_BLINKING_PERIOD 150 //((int)(SCHEDULE_BASE_PERIOD * 1 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))
#define SERVO_MOTOR_PERIOD 300 //((int)(SCHEDULE_BASE_PERIOD * 1 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))
#define BUTTON_PERIOD 150 //((int)(SCHEDULE_BASE_PERIOD * 1 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))
#define SONAR_PERIOD 450 //((int)(SCHEDULE_BASE_PERIOD * 2.5 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))
#define IOMAN_PERIOD 1000 //((int)(SCHEDULE_BASE_PERIOD * 5 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME)))

#define BLINK_DELTA_1 (BLINK_DELTA_2*5)
#define BLINK_DELTA_2 (30)

/* ### ### ### ### ### ### ### ### */

/* ### REQUEST VARIABLE ### */

#define N1_TIME 3000 //(3000 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME))
#define N2_TIME 3000 //(3000 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME))
#define N3_TIME 9000 //(9000 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME))
#define N4_TIME 3000 //(3000 * (SCHEDULE_BASE_PERIOD / IDEALLY_TIME))

#define MYTIME1 5000

/* ### ### ### ### ### ### ### ### */



/* ### STRING TO LCD ### */

#define WELCOME_STRING "Welcome"
#define PRE_ENTERING_STRING "Proceed to the Washing Area"
#define WAITING_STRING "Ready to Wash"
#define PRE_WASHING_DONE_STRING "Washing complete, you can leave the area"
#define ERROR_STRING "Detected a Problem - Please Wait"

#define MYSTRING_1 "Abort Washing"

/* ### ### ### ### ### ### ### ### */

/* ### STRING TO GUI ### */

#define STATE1 "1"
#define STATE2 "2"
#define STATE3 "3"
#define STATE4 "4"
#define STATE5 "5"
#define STATE6 "6"

/* ### ### ### ### ### ### ### ### */


/* ### DEBUGGING VARIABLE ### */

//#define DEBUG
#ifdef DEBUG

//#define SCHEDULER_INIT_PHASE
//#define SCHEDULER_PERIOD_DEBUG 

//#define PIR_DEBUG //valuta se eliminarmi
//#define SERVO_MOTOR_DEBUG
//#define SONAR_DEBUG
//#define TEMP_DEBUG
//#define LCD_DEBUG

//#define DEBUG_IOMAN_WITHOUT_CONSOLE

//#define SONAR_DEBUG_LEFTING

//#define STATE_CHANGE_DEBUG 

#endif

//#define S_DEGUB

/* ### ### ### ### ### ### ### */


#endif
