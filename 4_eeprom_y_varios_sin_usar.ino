
/////////////////////////////eeprom
//////////////////////////EEPROM
///estructura memoria
/*
  0-5    5 bytes  hora minuto  cantidad (int)
  5-10    5 bytes  hora minuto  cantidad (int)
  10-15   5 bytes  hora minuto  cantidad (int)
  15-20   enable1 enable2 enable3
  20-25 fecha compilacion  dia mes año(22) hora minuto
*/
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////CARGAR //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
  void cargar_variables_eeprom() {
  cargar_horas_comidas();
  cargar_cantidades();
  cargar_enables();
  }
  void cargar_horas_comidas() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      horas[i][j] = EEPROM.read((i * 5) + j);
      ///0*5 0 1*5 5
      ////ANTI EEPROM VACIA////
      if (j == 0) { ////la hora
        if (horas[i][j] > 23) {
          horas[i][j] = 23;
        }
      } else { /////MINUTO
        if (horas[i][j] > 59) {
          horas[i][j] = 59;
        }
      }////ANTI EEPROM VACIA////
    }
  }
  }
  void cargar_cantidades() {
  for (int i = 0; i < 3; i++) {
    byte aux = (i * 5) + 2;
    EEPROM.get(aux, cantidades[i]);
  }
  }
  void cargar_enables() {
  byte aux = 0;
  for (int i = 0; i < 3; i++) {
    aux = EEPROM.read(15 + i);
    ////quiero boolean
    if (aux == 255) {
      comidas_habilitadas[i] = true;
    } else if (aux == 0) {
      comidas_habilitadas[i] = false;
    } else {
      comidas_habilitadas[i] = true;/////por si acaso
    }
  }//fin for
  }
*/
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////GUARDAR //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
  0-5    5 bytes  hora minuto  cantidad (int)
  5-10    5 bytes  hora minuto  cantidad (int)
  10-15   5 bytes  hora minuto  cantidad (int)
  15-20   enable1 enable2 enable3
  20-25 fecha compilacion  dia mes año(22) hora minuto
*/
/*
  void guardar_horario(int indice_horario) {///0,1,2
  ///int horas[3][2];
  EEPROM.update(indice_horario * 5, horas[indice_horario][0]);
  EEPROM.update((indice_horario * 5) + 1, horas[indice_horario][1]);
  }
  void guardar_horario_miau(int indice_horario) {///0,1,2
  ///int horas[3][2];
  if (indice_horario == 0) {
    EEPROM.update(0, horas[0][0]);
    EEPROM.update(1, horas[0][1]);
  } else if (indice_horario == 1) {
    EEPROM.update(5, horas[1][0]);
    EEPROM.update(6, horas[1][1]);
  } else if (indice_horario == 2) {
    EEPROM.update(10, horas[2][0]);
    EEPROM.update(11, horas[2][1]);
  } else {}
  }
  void guardarcantidad(byte comida, int cantidad) {
  EEPROM.put((comida * 5) + 2, cantidad);
  ///EEPROM.put(direccion, valor);
  }
  void guardar_enables(byte comida, boolean enable) {
  if (enable) {
    EEPROM.put(15 + comida, 255);
    ///EEPROM.put(direccion, valor);
  } else { ///false
    EEPROM.put(15 + comida, 0);
  }
  }

  void cargar_defaults_sistema() {
  ////horas[3][2] = {21, 30}, {9, 00}, {13, 30};
  for (int i = 0; i < 3; i++) {
    horas[i][0] = 21;
    horas[i][1] = 30;
    guardar_horario(i);
    guardarcantidad(i, 400);
    if (i == 0) {
      guardar_enables(i, true);
    } else {
      guardar_enables(i, false);
    }
  }///fin for
  }

*/
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////PANTALLAS AJUSTES ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*
  void ajustar_anyo() {
  //Serial.println("estoy en el ajustar_anyo");
  ajustando_reloj_sistema = true;
  ajustando_anyo = true;
  lcd.setCursor(1, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUST A");
  lcd.write(byte(0));////eñe
  ///enye();
  lcd.print("O :   ");
  lcd.print("            ");
  lcd.setCursor(0, 1);
  lcd.print(anyo);
  lcd.print("            ");
  }
  void ajustar_mes() {
  //Serial.println("estoy en el ajustar_mes");
  ajustando_reloj_sistema = true;
  ajustando_mes = true;
  lcd.setCursor(1, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUSTANDO MES :");
  lcd.setCursor(0, 1);
  lcd.print("MES:");
  lcd.print(mes);
  }
  void ajustar_dia() {
  //Serial.println("estoy en el ajustar_dia");
  ajustando_reloj_sistema = true;
  ajustando_dia = true;
  lcd.setCursor(1, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUSTANDO DIA :");
  lcd.print("        ");
  lcd.setCursor(0, 1);
  lcd.print("DIA:");
  lcd.print(dia);
  lcd.print("        ");
  }
  void ajustar_hora_reloj(){
  //Serial.println("estoy en el ajustar_hora_reloj");
  ajustando_reloj_sistema = true;
  ajustandohora = true;
  lcd.setCursor(1, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUSTANDO HORA :");
  lcd.print("           ");
  lcd.setCursor(0, 1);
  lcd.print("hora:");
  lcd.print(hora);
  lcd.print(":");
  lcd.print(minuto);
  lcd.print("           ");
  }
  void ajustar_minuto_reloj(){
  //Serial.println("estoy en el ajustar_minuto_reloj");
  ajustando_reloj_sistema = true;
  ajustandominuto = true;
  lcd.setCursor(1, 0);///desplazo algo a la derecha el elemento seleccionado
  lcd.print("AJUSTANDO MINUTO :");
  lcd.setCursor(0, 1);
  lcd.print("hora:");
  lcd.print(hora);
  lcd.print(":");
  lcd.print(minuto);
  }
*/
