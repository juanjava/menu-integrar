/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////INTERFAZ //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////PANTALLAS MENU //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
void mostrar_menu() {///escribe la priumera linea, y la segunda si hay mas para escribir
  lcd.setCursor(0, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print(">");///flecha
  lcd.setCursor(1, 0);
  mostrarlinea(posscroll);
  ///lcd.print("          ");///BORRAR CARACTERES VIEJOS
  /*lcd.setCursor(18, 0);
  lcd.setCursor(18, 0);
  lcd.print(posscroll);///debugg*/
  
  ///////////LINEA 2
  lcd.setCursor(0, 1);///linea de abajo

  if (posscroll <= minmax[submenu][1]) {
    mostrarlinea(posscroll + 1); ////la siguiente
    ////lcd.print("          ");///BORRAR CARACTERES VIEJOS
  } else {
    lcd.print("                    ");////no imprimo nada; puede quedar la de abajo vacia///
  }
  /*lcd.setCursor(16, 1);
  lcd.print(submenu);///debugg
  /////lcd.print("                   ");////////quito restos de caracteres viejos
  lcd.print(" ");
  lcd.print(minmax[submenu][1]);*/
  PANTALLA_20_04(submenu);
}
/////lcd.print(12345678901234567890);///20 caracteres
void PANTALLA_20_04(byte algo) {

  if (pantallagrande) {/////////////////REUTILIZACION DE CODIGO
    ///////////LINEA 3
    if ((posscroll + 2) <= minmax[algo][1]) {
      lcd.setCursor(0, 2);///linea de abajo
      mostrarlinea(posscroll + 2); ////la siguiente
      /////lcd.print("          ");///BORRAR CARACTERES VIEJOS
    } else {
      lcd.setCursor(0, 2);///linea de abajo
      lcd.print("                    ");
    }
    ///////////LINEA 4
    if ((posscroll + 3) <= minmax[algo][1]) {
      lcd.setCursor(0, 3);///linea de abajo
      mostrarlinea(posscroll + 3); ////la siguiente
      ///lcd.print("          ");///BORRAR CARACTERES VIEJOS
    } else {
      lcd.setCursor(0, 3);///linea de abajo
      lcd.print("                    ");
    }
  } else {}
}

void mostrarlinea(int lineamenu) {////llamo a las de abajo, solo para dividir el switch case

  if (lineamenu >= 0 && lineamenu < 10) {
    menuinicio(lineamenu);
  } else if (lineamenu >= 10 && lineamenu < 20) {
    submenu1(lineamenu);
  } else if (lineamenu >= 20 && lineamenu < 30) {
    submenu2(lineamenu);
  } else if (lineamenu >= 30 && lineamenu < 40) {
    submenu3(lineamenu);
  } else if (lineamenu >= 40 && lineamenu < 50) {
    submenu4(lineamenu);
  } else {}
}
void menuinicio(int lineamenu) {
  submenu = 0;
  switch (lineamenu) {
    case 0:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU 1            ");
      break;
    case 1:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU 2            ");
      break;
    case 2:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU 3            ");
      break;
    case 3:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU 4            ");
      break;
    case 4:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("cambiar 1         ");
      break;
    case 5:
      lcd.print("cambiar 2         ");
      break;
    case 6:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("cambiar 3         ");
      break;
    case 7:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("cambiar 4        ");
      break;
    case 8:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("Todos off        ");
      break;
    default:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("                   ");
      break;
  }
}
void submenu1(int lineamenu) {
  submenu = 1;
  switch (lineamenu) {
    case 10:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("VOLVER         ");
      break;
    case 11:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("PANTALLA 4 LINEAS ");
      break;
    case 12:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("PANTALLA 2 LINEAS ");
      break;
    case 13:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("AJUSTAR VALOR ");
      lcd.print(valoresajustes[0]);
      break;
    default:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("                  ");
      break;
  }
}
void submenu2(int lineamenu) {///on//off/brillo//volver
  submenu = 2;
  switch (lineamenu) {
    case 20:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("VOLVER            ");
      break;
    case 21:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU2 ELEMENTO 1  ");
      break;
    case 22:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("AJUSTAR VAL 2   ");
      lcd.print(valoresajustes[1]);
      break;
    case 23:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU2 ELEMENTO 3  ");
      break;
    case 24:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU2 ELEMENTO 4  ");
      break;
    case 25:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU2 ELEMENTO 5  ");
      break;
    default:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("                  ");
      break;
  }
}
void submenu3(int lineamenu) {///on//off/brillo//volver
  submenu = 3;
  switch (lineamenu) {
    case 30:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("VOLVER"          );
      break;
    case 31:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU 3 ELEMENTO 1 ");
      break;
    case 32:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("AJUSTAR VALOR ");
      lcd.print(valoresajustes[2]);
      lcd.print(" ");
      break;
    case 33:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU SIN LIBRERIA");
      break;
    case 34:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("PARA INTEGRAR   ");
      break;
    case 35:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("LCD 4/2 LINEAS ");
      break;
    case 36:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("HATMI SUSCRIBETE ");
      break;
    case 37:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU3 777         ");
      break;
    case 38:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("MENU3 888888     ");
      break;
    default:
      lcd.print("                    ");
      break;
  }
}
void submenu4(int lineamenu) {///on//off/brillo//volver
  submenu = 4;
  switch (lineamenu) {
    case 40:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("VOLVER            ");
      break;
    case 41:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("AJUSTAR VALOR     ");
      lcd.print(valoresajustes[3]);
      break;
    case 42:
    //lcd.print(12345678901234567890);///20 caracteres
      lcd.print("FIN              ");
      break;
    default:
      lcd.print("                    ");
      break;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////PANTALLAS AJUSTES //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
void ajustarvalor(byte indice_valor) { ///////////FINIQUITAT//////
  ajustandoalgo = true;
  lcd.setCursor(0, 0); ///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUSTANDO VALOR :");
  lcd.print(indice_valor + 1);
  lcd.setCursor(0, 1);
  lcd.print("CANTIDAD:");
  lcd.print(valoresajustes[indice_valor]);
}
/*
  void pantallasajustes() {/////////////////////ESTARA MAL
  if (ajustandoalgo) {
    if (ajustandohora) {
      ajustar_hora();
    } else if (ajustandominuto) {
      ajustar_minuto();
    } else if (ajustando_habilitar_comida) {
      ajustar_habilitar_comida();
    } else if (ajustar_cantidad) {
      ajustar_cantidad();
    }  else {
      booleanos_a_false();
    }
  } else {
    mostrar_menu();////MENU EN SI
  }
  }*/

  
