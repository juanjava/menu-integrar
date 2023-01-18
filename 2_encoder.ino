/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////ENCODER  //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
void ClockChanged() {////////////del ejemplo del encoder
  clkValue = digitalRead(CLK);//Read the CLK pin level
  dtValue = digitalRead(DT);//Read the DT pin level

  if (lastCLK != clkValue) {
    lastCLK = clkValue;

    if (clkValue == dtValue) {
      pines_iguales_encoder = true;
    } else {
      pines_iguales_encoder = false;
    }

    if (!ajustandoalgo) { ///NO estoy ajustando nada
      if (pines_iguales_encoder) {
        sumando();
      } else {
        restando();
      }
    } else { ////ajustando algun valor
      ajustar_valores_encoder_sumando(pines_iguales_encoder);
    }
  }
}

void sumando() {///clar
  if (posscroll < minmax[submenu][1]) {
    posscroll++;
  }else if (posscroll>minmax[submenu][1]){
    posscroll = minmax[submenu][1];
    }else{}
}
void restando() {///clar
  if (posscroll > minmax[submenu][0]) {
    posscroll--;
  }else if (posscroll<minmax[submenu][0]){
    posscroll = minmax[submenu][0];
    }else{}
}

/*///////otros ajustes de variables
  boolean ajustandoalgo = false;///metido en encoder (ClockChanged) y en ajustarbrilloled
  byte numerovalor = 0;////
  boolean ajustandovalores[] = {false, false, false, false};
  int valoresajustes[] = {0, 100, 200, 300};
  int rangos_ajustes{///para ponerle limites al encoder
  {00, 99},
  {100, 199},
  {200, 299}, 
  {300, 399},
  };////por legibilidad///*/
void ajustar_valores_encoder_sumando(boolean sumando) {
    if (ajustandovalores[numerovalor] == true) {
      ///modificar_variable_int(int aux, int limite_min, int limitemax, boolean sumando) {
      valoresajustes[numerovalor] = modificar_variable_int(valoresajustes[numerovalor], rangos_ajustes[numerovalor][0], rangos_ajustes[numerovalor][1], sumando);
  }
}
/*if (ajustandoºalgo) {////////////////MODO LARRRRRGO
  if (ajustandovalores[0]) {
    valoresajustes[] = modificar_variable_int(horas[numerocomida][0], 0, 23, sumando);
  } else if (ajustandovalores[1]) {
    horas[numerocomida][1] = modificar_variable_int(horas[numerocomida][1], 0, 59, sumando);
  } else if (ajustandovalores[]) {
    cantidades[numerocomida] = modificar_variable_int(cantidades[numerocomida], 9, 30000, sumando);
  } else if (ajustandovalores[]) {
    comidas_habilitadas[numerocomida] = !comidas_habilitadas[numerocomida];
  } else {}
  } else {}
  ///////////////////7DEL DISPENSADOR DE PIENSO */
  
int modificar_variable_int(int variable, int limite_min, int limitemax, boolean sumando) {
  ///modificar_variable_int(variable,limite_min,limitemax,sumando);
  if (variable > limitemax) {
    variable = limitemax;
  }
  if (variable < limite_min) {
    variable = limite_min;
  }
  //////actuar////
  if (variable < limitemax && sumando) {
    variable++;
  } else if (variable > limite_min && !sumando) {
    variable--;
  } else {}
  return variable;
}
