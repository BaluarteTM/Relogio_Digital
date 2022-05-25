// C++ code

#include <LiquidCrystal.h>
#define but_hora 13 
#define but_min 12
#define on_off 11



LiquidCrystal lcd (7 , 6 , 5 , 4 , 3 , 2); //Definimos qual são os pinos do LCD.

int horas = 12; //Variavel de hora.
int minutos = 0; //Variavel de minuto.
int segundos = 0; //Variavel de segundo.
bool liga; //Variavel que define estado (on / of)
bool aumenta_hora; //Variavel de edição de horário.
bool aumenta_min; //Variavel de edição de horário.



void setup()
{
  pinMode(but_hora , INPUT); //Controle de calibragem de horário.
  pinMode(but_min , INPUT); //Controle de calibragem de horário.
  pinMode(on_off , INPUT);  //Controle de funcionamento.
  liga = false; //Define o funcionamento padrão como negativo.
  lcd.begin(16 , 2);  //Inicia o LCD.
  //Serial.begin(9600);  
    }


void loop()
{
  
  liga = digitalRead(on_off);  //Conecta botão (on / off) no sistema.
  aumenta_hora = digitalRead(but_hora); //Conecta botão de calibragem no sistema.
   aumenta_min = digitalRead(but_min); //Conecta botão de calibragem no sistema.
  
  while(liga == true){ //funcionamento básico de um Relógio.
    //Serial.print(liga);
    lcd.setCursor(4 , 0);
  lcd.print(horas);;
    lcd.print(":");
    lcd.print(minutos);
    lcd.print(":");
    lcd.print(segundos);
    segundos = segundos + 1; //A cada ciclo acrecenta + 1 segundo.
    delay(1000);
    
    if(segundos > 59){ //A cada 60 segundos, é acrescentado + 1 minuto. 
      lcd.clear();      
      segundos = 00; //Define segundos para 0 novamente.
      minutos = minutos + 1;
      
    }
    if(minutos > 59){
      lcd.clear();
      minutos = minutos - 60;
      horas = horas + 1;
    }
    if(horas > 23){
      lcd.clear();
      horas = 0;
      lcd.setCursor(4 , 1);
      lcd.print("BOM DIA");
    }
    
    if(minutos > 1){ //Retira o texto de "BOM DIA"
      lcd.clear();
    }
      
        
      
    liga = digitalRead(on_off);
    
    
  while(liga == false){
    liga = digitalRead(on_off);
    lcd.setCursor(4 , 0);
  lcd.print(horas);;
    lcd.print(":");
    lcd.print(minutos);
    lcd.print(":");
    lcd.print(segundos);
    aumenta_hora = digitalRead(but_hora);
    aumenta_min = digitalRead(but_min);
    delay(100);
    if(aumenta_min == HIGH){
      minutos = minutos + 1;
      delay(500);
      if(minutos > 59){
        lcd.clear();
        minutos = 0;
       	}
    }
    if(aumenta_hora == HIGH){
      horas = horas + 1;
      delay(500);
      if(horas > 23){
        lcd.clear();
        horas = 0;
      }
    }
         
         
   }
 }
}

    
  
    
      
    
    
    
              
  

