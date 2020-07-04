//Nombre: Henry Lema
//Asignatura: Sistemas Embebidos
# include <Wire.h>// comunicacion  i2c
# include <LiquidCrystal.h>
LiquidCrystal lcd = {13, 12, 11, 10, 9, 8}; // pines lcd
String encripta = ""; //Strings ingresados
String cod = "";
String inver = "";
String temp="";
 int x=0;// contadores
 int i = 0;
void setup() {
  lcd.begin(16, 2);
  Wire.begin();
  Serial.begin(9600);
   }

void loop() {
  if (Serial.available() > 0) {//revisa que exista un dato lectura
    encripta = Serial.readString(); // lectura
          Serial.println("");
for (x=encripta.length()-1;x>=0;x--){ // compara la longitud de la lectura
  inver = inver + encripta.charAt(x)+x; 
  delay(20);

 if(x>encripta.length()){// contador debe ser mayor que la posicion de la lectura
  inver = "";
   i=0;// reinicia la lectura y posiciones
  x=0;
 
  }
     
  }

    cod=inver;

   Wire.beginTransmission(1);
    Wire.write(cod.c_str());
    Wire.endTransmission();
    Serial.println("");
    delay(200);
} 
lcd.setCursor(0,0); /// palabra mostrados en lcd
lcd.print("palabra");
lcd.setCursor(0,1);// posicion de la palabra ingresada
lcd.print(encripta);
encripta = "";
 cod = "";
 inver = "";
 }
