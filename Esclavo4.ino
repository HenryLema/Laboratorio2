//Nombre: Henry Lema
//Asignatura: Sistemas Embebidos
# include <Wire.h>
# include <LiquidCrystal.h>//libreria lcd
LiquidCrystal lcd = {13, 12, 11, 10, 9, 8};// pines de lcd 

char data;                //variables y contadores
String encripta = "";
String recibe = "";
String supr="";
String reves = "";
int i=0;
int k=0;
int x=0;

void setup() {
  lcd.begin(16, 2);
  Wire.begin(1); //comunicacion maestro esclavo canal
  Wire.onReceive(recieveEvent);
  Serial.begin(9600); 
}

void loop() {
 lcd.setCursor(0,1);
    lcd.print(encripta);
}
void recieveEvent(int bytes) {// metodo requerimiento de palabra
  encripta = "";
  lcd.clear();
  while (Wire.available()) {
    data = Wire.read();
    encripta.concat(data);
   // lcd.setCursor(0,1);
    //lcd.print(encripta);
    Serial.println(encripta);  
    }
  for (x=recibe.length()-1;x>=0;x--){ //bucle invierte la cadena
    reves = reves + recibe.charAt(x)+x;//posicion
    delay(20);
    Serial.println(reves);  // invierte la cadena string

 if(x>recibe.length()){//compara la longitud de la cadena
  reves = "";
  x=0;
  i=0;
  }

   
    
  }
  for (k=encripta.length()-1;k>=0;k--){
    k--;
    supr = supr + encripta.charAt(k);
    Serial.println(supr); 
    delay(10);
    }
    recibe=supr;    

 
  lcd.setCursor(0, 0);// posicion impresion fila 0
  lcd.print("enc:");
  lcd.setCursor(6, 0);
  lcd.print(encripta);
  
  lcd.setCursor(0, 1); // posicion fila 1
  lcd.print("rcb:");
  lcd.setCursor(4 , 1);
  lcd.print(recibe);
  encripta = "";
  recibe = "";

 supr="";
 reves = "";
  //lcd.clear();

  //lcd.clear();
  
}
