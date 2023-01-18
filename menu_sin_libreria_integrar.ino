/////////librerias//////////////
///#include <LiquidCrystal.h>//sin i2c
///i2c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

boolean pantallagrande = true;
LiquidCrystal_I2C lcd(0x27, 20, 4);


///ROTARY ENCODER//////////////
///PINES///
byte CLK = 2;//CLK->D2
byte DT = 3;//DT->D3
byte SW = 4;//SW->D4
///VARIABLES
///En Arduino y Nano se dispone de dos interrupciones, 0 y 1, asociados a los pines digitales 2 y 3
const byte interrupt0 = 0;// Interrupt 0 在 pin 2 上
int clkValue = 0;//Read the CLK pin level
int dtValue = 0;//Read the DT pin level
//int count = 0;//Define the count
int lastCLK = 0;//CLK initial value
boolean pines_iguales_encoder = true;

boolean estado_boton_enc_antes = false;
boolean botonpulsado = false;//anti aguantar//
unsigned long millisahora = 0;
unsigned long millisantes_enc = 0;
unsigned long ultimapulsacion_enc = 0;

///////////////EL MENU////////////////////////
byte submenu = 0; ///ANDE ANDO
byte posscroll = 0;///////////donde estoy en el menu()
byte ultimoclick = 50;////antirrebote de pulsaciones de boton///modo sin millis()
int elementopulsado = -1;/////si he pulsado algo esto lo hara indefinidamente /////no uso para ejemplo

/////////////minimos y maximos del menu////////////////////
byte minmax[5][2] = {///para ponerle limites al encoder
  {00, 8},
  {10, 13},
  {20, 25},
  {30, 38},
  {40, 42}
};////por legibilidad///


////////////////// LEDES//////////////////////
byte ledes[] = {6, 9, 10, 11}; ///numero de los pines
boolean estadoledes[] = {false, false, false, false};

////////////////// AJUSTANDO VARIABLES; CON DIVERSOS RANGOS EN CADA UNA//////////////////////
boolean ajustandoalgo = false;///metido en encoder (ClockChanged) y en ajustarbrilloled
byte numerovalor = 0;////indice arrays abajo
boolean ajustandovalores[] = {false, false, false, false};
int valoresajustes[] = {0, 100, 200, 300};
int rangos_ajustes[4][2] = {///para ponerle limites al encoder
  {00, 99},
  {100, 199},
  {200, 299},
  {300, 399},
};////por legibilidad///

void setup() {
  ///LiquidCrystal_I2C lcd(0x27, 20, 4);  
  iniciar_pantalla();

  ////ENCODER
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  attachInterrupt(interrupt0, ClockChanged, LOW); //Set the interrupt 0 handler, trigger level change
  ///los leds
  for (int i = 0; i < 4; i++) {
    pinMode(ledes[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Estoy en el setup");
}
void iniciar_pantalla(){
    if(pantallagrande){/////////////////REUTILIZACION DE CODIGO
  LiquidCrystal_I2C lcd(0x27, 20, 4);  
} else {
 LiquidCrystal_I2C lcd(0x27, 16, 2); 
}
  ///lcd.begin(16, 2);
  // Inicializar el LCD
  lcd.init();
  lcd.backlight();//Encender la luz de fondo.
  } 

void loop() {
  ///////////PRIMERO MOSTRAR EN PANTALLA LO QUE TOQUE///////////////
  if (!ajustandoalgo) {
    mostrar_menu();
  }else {
    ajustarvalor(numerovalor);
  }
  /////luego toca ver si he pulsado el booton
 ///mirarboton_sin_millis();
 mirarboton_con_millis();
encender_ledes();
}
void encender_ledes(){
    for (int i = 0; i < 4; i++) {
    digitalWrite(ledes[i], estadoledes[i]);
  }
  }

  
