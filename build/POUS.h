#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM JOYSTICK
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(INT,ANGULOBRAZO)
  __DECLARE_LOCATED(INT,PRIMERLED)
  __DECLARE_LOCATED(INT,SEGUNDOLED)
  __DECLARE_LOCATED(INT,TERCERLED)
  __DECLARE_LOCATED(INT,CUARTOLED)
  __DECLARE_LOCATED(INT,JOYSTICKENTRADA)
  __DECLARE_LOCATED(INT,JOYSTICKDERECHA)
  __DECLARE_LOCATED(INT,JOYSTICKIZQUIERDA)
  __DECLARE_LOCATED(BOOL,LED45GRADOS)
  __DECLARE_LOCATED(BOOL,LED90GRADOS)
  __DECLARE_LOCATED(BOOL,LED120GRADOS)
  __DECLARE_LOCATED(BOOL,LED150GRADOS)
  __DECLARE_LOCATED(BOOL,RELAY)
  __DECLARE_VAR(BOOL,_TMP_GE12_OUT)
  __DECLARE_VAR(BOOL,_TMP_LE28_OUT)
  __DECLARE_VAR(BOOL,_TMP_GE1_OUT)
  __DECLARE_VAR(INT,_TMP_BOOL_TO_INT11_OUT)
  __DECLARE_VAR(INT,_TMP_ADD10_OUT)
  __DECLARE_VAR(INT,_TMP_BOOL_TO_INT29_OUT)
  __DECLARE_VAR(INT,_TMP_SUB38_OUT)
  __DECLARE_VAR(INT,_TMP_SEL41_OUT)
  __DECLARE_VAR(BOOL,_TMP_GE16_OUT)
  __DECLARE_VAR(BOOL,_TMP_GE19_OUT)
  __DECLARE_VAR(BOOL,_TMP_GE23_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR42_OUT)

} JOYSTICK;

void JOYSTICK_init__(JOYSTICK *data__, BOOL retain);
// Code part
void JOYSTICK_body__(JOYSTICK *data__);
#endif //__POUS_H
