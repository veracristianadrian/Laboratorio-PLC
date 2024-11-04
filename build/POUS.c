void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void JOYSTICK_init__(JOYSTICK *data__, BOOL retain) {
  __INIT_LOCATED(INT,__MW0_0,data__->ANGULOBRAZO,retain)
  __INIT_LOCATED_VALUE(data__->ANGULOBRAZO,0)
  __INIT_LOCATED(INT,__MW0_1,data__->PRIMERLED,retain)
  __INIT_LOCATED_VALUE(data__->PRIMERLED,40)
  __INIT_LOCATED(INT,__MW0_2,data__->SEGUNDOLED,retain)
  __INIT_LOCATED_VALUE(data__->SEGUNDOLED,90)
  __INIT_LOCATED(INT,__MW0_3,data__->TERCERLED,retain)
  __INIT_LOCATED_VALUE(data__->TERCERLED,120)
  __INIT_LOCATED(INT,__MW0_4,data__->CUARTOLED,retain)
  __INIT_LOCATED_VALUE(data__->CUARTOLED,150)
  __INIT_LOCATED(INT,__IW0_1,data__->JOYSTICKENTRADA,retain)
  __INIT_LOCATED_VALUE(data__->JOYSTICKENTRADA,0)
  __INIT_LOCATED(INT,__MW0_5,data__->JOYSTICKDERECHA,retain)
  __INIT_LOCATED_VALUE(data__->JOYSTICKDERECHA,1000)
  __INIT_LOCATED(INT,__MW0_6,data__->JOYSTICKIZQUIERDA,retain)
  __INIT_LOCATED_VALUE(data__->JOYSTICKIZQUIERDA,10)
  __INIT_LOCATED(BOOL,__QX0_0,data__->LED45GRADOS,retain)
  __INIT_LOCATED_VALUE(data__->LED45GRADOS,0)
  __INIT_LOCATED(BOOL,__QX0_1,data__->LED90GRADOS,retain)
  __INIT_LOCATED_VALUE(data__->LED90GRADOS,0)
  __INIT_LOCATED(BOOL,__QX0_2,data__->LED120GRADOS,retain)
  __INIT_LOCATED_VALUE(data__->LED120GRADOS,0)
  __INIT_LOCATED(BOOL,__QX0_3,data__->LED150GRADOS,retain)
  __INIT_LOCATED_VALUE(data__->LED150GRADOS,0)
  __INIT_LOCATED(BOOL,__QX0_4,data__->RELAY,retain)
  __INIT_LOCATED_VALUE(data__->RELAY,0)
  __INIT_VAR(data__->_TMP_GE12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE28_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_BOOL_TO_INT11_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_BOOL_TO_INT29_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB38_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SEL41_OUT,0,retain)
  __INIT_VAR(data__->_TMP_GE16_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR42_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void JOYSTICK_body__(JOYSTICK *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_GE12_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_LOCATED(data__->PRIMERLED,)));
  __SET_LOCATED(data__->,LED45GRADOS,,__GET_VAR(data__->_TMP_GE12_OUT,));
  __SET_VAR(data__->,_TMP_LE28_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->JOYSTICKENTRADA,),
    (INT)__GET_LOCATED(data__->JOYSTICKIZQUIERDA,)));
  __SET_VAR(data__->,_TMP_GE1_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->JOYSTICKENTRADA,),
    (INT)__GET_LOCATED(data__->JOYSTICKDERECHA,)));
  __SET_VAR(data__->,_TMP_BOOL_TO_INT11_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_GE1_OUT,)));
  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_VAR(data__->_TMP_BOOL_TO_INT11_OUT,)));
  __SET_VAR(data__->,_TMP_BOOL_TO_INT29_OUT,,BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_LE28_OUT,)));
  __SET_VAR(data__->,_TMP_SUB38_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_VAR(data__->_TMP_BOOL_TO_INT29_OUT,)));
  __SET_VAR(data__->,_TMP_SEL41_OUT,,SEL__INT__BOOL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_LE28_OUT,),
    (INT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (INT)__GET_VAR(data__->_TMP_SUB38_OUT,)));
  __SET_LOCATED(data__->,ANGULOBRAZO,,__GET_VAR(data__->_TMP_SEL41_OUT,));
  __SET_VAR(data__->,_TMP_GE16_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_LOCATED(data__->SEGUNDOLED,)));
  __SET_LOCATED(data__->,LED90GRADOS,,__GET_VAR(data__->_TMP_GE16_OUT,));
  __SET_VAR(data__->,_TMP_GE19_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_LOCATED(data__->TERCERLED,)));
  __SET_LOCATED(data__->,LED120GRADOS,,__GET_VAR(data__->_TMP_GE19_OUT,));
  __SET_VAR(data__->,_TMP_GE23_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->ANGULOBRAZO,),
    (INT)__GET_LOCATED(data__->CUARTOLED,)));
  __SET_LOCATED(data__->,LED150GRADOS,,__GET_VAR(data__->_TMP_GE23_OUT,));
  __SET_VAR(data__->,_TMP_OR42_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_GE1_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LE28_OUT,)));
  __SET_LOCATED(data__->,RELAY,,__GET_VAR(data__->_TMP_OR42_OUT,));

  goto __end;

__end:
  return;
} // JOYSTICK_body__() 





