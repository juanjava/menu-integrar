
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////BOTON //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void mirarboton_con_millis() {///// CON MILLIS
  millisahora = millis();
  if (digitalRead(SW)) {//high/true es NO pulsado
    estado_boton_enc_antes = true;
    botonpulsado = false;
    ///millisantes_enc = millisahora;//RALENTIZA
  } else { /////he pulsado
    if (estado_boton_enc_antes == true) { ///1ª vez que entra desde que pulsas
      estado_boton_enc_antes = false;
      millisantes_enc = millisahora;//guardo millis
      botonpulsado = false;
      ///Serial.println("Boton pulsado Boton pulsado Boton pulsado ");
    } else if (millisahora > (millisantes_enc + 400) && millisahora > (ultimapulsacion_enc + 2000)) { ///milisegundos

      ////millisahora>(ultimapulsacion_enc+2000) anti dos clics muy rapidos
      if (!botonpulsado) { ////antirebote//anti aguantar
        botonpulsado = true;
        hacer_caso_boton2();
        ultimapulsacion_enc =  millisahora;
        elementopulsado = posscroll;
      } else {
        botonpulsado = true;
      }
    } else {
      botonpulsado = false;
    }
  }//fin else he pulsado
}

void mirarboton_sin_millis() { /////////////ARREGLADO
  if (!digitalRead(SW) && (ultimoclick != posscroll)) //leo el boton y asigno posscroll a elementopulsado
  {
    ultimoclick = posscroll;
    Serial.print("Elemento pulsado: ");
    Serial.println(ultimoclick);
    ///sacar_variables_serial();
    ///hacer_caso_boton();///COMENTADO TB
    ////puede hacer un entrare menu y click en volver a la vez
  }
  if (!digitalRead(SW) && ajustandoalgo) { /// solo cuando ajustandoled = true
    ajustandoalgo = false; ///SALGO DE AHI
    ///elementopulsado=-1;
    posscroll = submenu - 1;
    ultimoclick = posscroll;
    delay(200);
  } else {}
}


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////CASO BOTON //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
  void hacer_caso_boton() { ///esto se hara cuando pulse el boton///VERSION CORTA //AJUSTANDO ALGO  IMPLEMENTADO//
  if (ajustandoalgo) {
    boton_en_editando_variables();
  } else {
    if (posscroll >= 0 && posscroll < 10) { ///pulso boton en menu inicio
      submenu = 0;
      if (posscroll < 4) {
        posscroll++;
        posscroll = posscroll * 10; ///me meto en submenu; opcion 0 ha de acabar en opcion 10
      } else {
        funciones_directas_menu_principal();
      }
    } else { //////////mayor de 10, estoy en un subapartado
      int subapartado = posscroll % 10; //% DEVUELVE EL RESTO DE LA DIVISION
      if (subapartado == 0) {///he puesto el salir en cero
        posscroll = 0;/*elementopulsado=0;*//*
      }////volver///
      else {
        ////INVENTATE ALGO///////////RELLENA TU
        submenu_actuar();
      }
    }
  }
  }
*/
void  hacer_caso_boton2() {/////////////////VERSION LARGA
  if (ajustandoalgo) {
    boton_en_editando_variables();
  } else {
    boton_en_menu();
  }
}
void boton_en_editando_variables() {
  ajustandoalgo = false;
  ajustandovalores[numerovalor] = false;
}

void entrarsubmenu() {
  submenu = posscroll;/////importante
  posscroll++;
  posscroll = posscroll * 10; ///me meto en submenu; opcion 0 ha de acabar en opcion 10
}
void calcular_submenu() {
  submenu = (posscroll / 10) - 1;
}
void submenu_actuar() {///////////////////////
  if (editando_variable_si_no()) {} else { //////para hacer que vaya
    int subapartado = posscroll % 10; ///resto de la division
    if (subapartado == 0) {///lcd.print("VOLVER");*/
      salir_a_menu_inicio();
      //////montate tu chiringuito aqui
      ////necesita un patron en funcionalidad todos los 1 hacer la misma cosa, los 2; los 3 etc
    }  else if (subapartado == 1) {
    }  else if (subapartado == 2) {
    }  else if (subapartado == 3) {
    } else if (subapartado == 4) {
    } else {}
  }
}

void salir_a_menu_inicio() {
  ///veniamos del 12, por ejemplo; 10/10 = 1  1-1 = 0; submenu cero
  calcular_submenu();
  if (submenu < 0) {///blindaje
    submenu = 0;
  }
  /////situamos puntero ahi
  posscroll = submenu;
}




void funciones_directas_menu_principal() {
  modo_largo();
  ///modo_corto();
}
void modo_largo() {
  switch (posscroll) {
      Serial.println(elementopulsado);
    case 4:
      estadoledes[0] = !estadoledes[0];
      break;
    case 5:
      estadoledes[1] = !estadoledes[1];
      break;
    case 6:
      estadoledes[2] = !estadoledes[2];
      break;
    case 7:
      estadoledes[3] = !estadoledes[3];
      break;
    case 8:
      for (int i = 0; i < 4; i++) {
        estadoledes[i] = false;
      }
      break;
    default:
      // statements
      break;
  }///fin del switch
}
void modo_corto() {
  if (posscroll < 8) {
    estadoledes[posscroll - 4] = !estadoledes[posscroll - 4];
  } else if (posscroll == 8) {
    for (int i = 0; i < 4; i++) {
      estadoledes[i] = false;
    }
  } else {}
}

/*byte minmax[5][2] = {///para ponerle limites al encoder
  {00, 08},
  {10, 13},
  {20, 25},
  {30, 39},
  {40, 42}
  };////por legibilidad///*/
boolean editar_variable() {
  calcular_submenu();
  numerovalor = submenu;
  ajustandoalgo = true;
  ajustandovalores[numerovalor] = true;
}
boolean editando_variable_si_no() {
  /*boolean ajustandoalgo = false;///metido en encoder (ClockChanged) y en ajustarbrilloled
    byte numerovalor = 0;////
    boolean ajustandovalores[] = {false, false, false, false};*/
  if (posscroll == 13 || posscroll == 22 || posscroll == 32 || posscroll == 41) {
    calcular_submenu();
    numerovalor = submenu;

    return ajustandovalores[numerovalor]; ///true or false
  } else {
    return false;
  }
  return false;
}
void boton_en_menu() {/////SWITCH CASE BESTIA
  Serial.print("Boton en menu  ");
  Serial.println(posscroll);
  /*if (posscroll < 4) {
    entrarsubmenu();
    } else if (posscroll < 10 && posscroll > 3) {
    funciones_directas_menu_principal();
    } else if {}*/
  switch (posscroll) {
    case 0:
      entrarsubmenu();
      break;
    case 1:
      entrarsubmenu();
      break;
    case 2:
      entrarsubmenu();
      break;
    case 3:
      entrarsubmenu();
      break;
    case 4:
      funciones_directas_menu_principal();
      break;
    case 5:
      funciones_directas_menu_principal();
      break;
    case 6:
      funciones_directas_menu_principal();
      break;
    case 7:
      funciones_directas_menu_principal();
      break;
    case 8:
      funciones_directas_menu_principal();
      break;

    case 10: 
      salir_a_menu_inicio();
      break;
    case 11:
        pantallagrande = true;
    iniciar_pantalla();
      break;
    case 12:
    pantallagrande = false;
    iniciar_pantalla();
      break;
    case 13:
      editar_variable();
      break;
    case 20://///lcd.print("volver");
      salir_a_menu_inicio();
      break;
    case 21:
      submenu_actuar();
      break;
    case 22:
      editar_variable();
      break;
    case 23:
      submenu_actuar();
      break;
    case 24:
      submenu_actuar();
      break;
    case 25:
      submenu_actuar();
      break;
    case 30://///lcd.print("volver");
      salir_a_menu_inicio();
      break;
    case 31:
      submenu_actuar();
      break;
    case 32:
      editar_variable();
      break;
    case 33:
      submenu_actuar();
      break;
    case 34:
      submenu_actuar();
      break;
    case 35:
      submenu_actuar();
      break;
    case 36:
      submenu_actuar();
      break;
    case 37:
      submenu_actuar();
      break;
    case 38:
      submenu_actuar();
      break;
    case 39:
      submenu_actuar();
      break;
    case 40://///lcd.print("volver");
      salir_a_menu_inicio();
      break;
    case 41:
      editar_variable();
      break;
    case 42:
      submenu_actuar();
      break;
      /// default:
      // statements
  }
}
