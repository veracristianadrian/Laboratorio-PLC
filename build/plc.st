TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM joystick
  VAR
    anguloBrazo AT %MW0.0 : INT := 0;
  END_VAR
  VAR CONSTANT
    primerled AT %MW0.1 : INT := 40;
    segundoled AT %MW0.2 : INT := 90;
    tercerled AT %MW0.3 : INT := 120;
    cuartoled AT %MW0.4 : INT := 150;
  END_VAR
  VAR
    joystickEntrada AT %IW0.1 : INT;
  END_VAR
  VAR CONSTANT
    joystickDerecha AT %MW0.5 : INT := 1000;
    joystickIzquierda AT %MW0.6 : INT := 10;
  END_VAR
  VAR
    led45grados AT %QX0.0 : BOOL := 0;
    led90grados AT %QX0.1 : BOOL := 0;
    led120grados AT %QX0.2 : BOOL := 0;
    led150grados AT %QX0.3 : BOOL := 0;
    relay AT %QX0.4 : BOOL := 0;
  END_VAR
  VAR
    _TMP_GE12_OUT : BOOL;
    _TMP_LE28_OUT : BOOL;
    _TMP_GE1_OUT : BOOL;
    _TMP_BOOL_TO_INT11_OUT : INT;
    _TMP_ADD10_OUT : INT;
    _TMP_BOOL_TO_INT29_OUT : INT;
    _TMP_SUB38_OUT : INT;
    _TMP_SEL41_OUT : INT;
    _TMP_GE16_OUT : BOOL;
    _TMP_GE19_OUT : BOOL;
    _TMP_GE23_OUT : BOOL;
    _TMP_OR42_OUT : BOOL;
  END_VAR

  _TMP_GE12_OUT := GE(anguloBrazo, primerled);
  led45grados := _TMP_GE12_OUT;
  _TMP_LE28_OUT := LE(joystickEntrada, joystickIzquierda);
  _TMP_GE1_OUT := GE(joystickEntrada, joystickDerecha);
  _TMP_BOOL_TO_INT11_OUT := BOOL_TO_INT(_TMP_GE1_OUT);
  _TMP_ADD10_OUT := ADD(anguloBrazo, _TMP_BOOL_TO_INT11_OUT);
  _TMP_BOOL_TO_INT29_OUT := BOOL_TO_INT(_TMP_LE28_OUT);
  _TMP_SUB38_OUT := SUB(anguloBrazo, _TMP_BOOL_TO_INT29_OUT);
  _TMP_SEL41_OUT := SEL(_TMP_LE28_OUT, _TMP_ADD10_OUT, _TMP_SUB38_OUT);
  anguloBrazo := _TMP_SEL41_OUT;
  _TMP_GE16_OUT := GE(anguloBrazo, segundoled);
  led90grados := _TMP_GE16_OUT;
  _TMP_GE19_OUT := GE(anguloBrazo, tercerled);
  led120grados := _TMP_GE19_OUT;
  _TMP_GE23_OUT := GE(anguloBrazo, cuartoled);
  led150grados := _TMP_GE23_OUT;
  _TMP_OR42_OUT := OR(_TMP_GE1_OUT, _TMP_LE28_OUT);
  relay := _TMP_OR42_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : joystick;
  END_RESOURCE
END_CONFIGURATION
