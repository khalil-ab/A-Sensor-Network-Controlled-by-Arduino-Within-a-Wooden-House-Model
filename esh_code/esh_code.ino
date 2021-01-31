#include <DHT.h>
#define DHTTYPE DHT22 
#define DHTPIN 43     
DHT dht(DHTPIN, DHTTYPE);
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
#include "RTClib.h"
#include <Servo.h>
//#include <OneWire.h>
//#include <DallasTemperature.h>

char Data[5]; // 4 est le nombre des caractere du mot de passe+le 5ème caractere NULL
char code1[15] = "your_own_code1"; 
char code2[15] = "your_own_code2"; 
byte data_cpt = 0, code_cpt = 0;
char touche;
int pir=44;
int buzzer=45;
int alrm=0;//pour activer ou desactiver l'alarme quand c'est 0 ou 1
int cpt;
int porte;
int iAngle;
int ph=A5;
int led1=22;
int led2=23;
int led3=52;
int led4=53;
int led5=32;
int led6=33;
int led7=34;
int led8=35;
int led9=36;
int led10=37;
int led11=51;
int led12=50;
int led13=49;
int led14=48;
int led15=47;
int led16=46;
int gaz=A1;
int x,y,z,w,v;
//OneWire oneWire(43);
//DallasTemperature sensors(&oneWire);

const byte ligne = 4;
const byte colonne = 4;
char clavier[ligne][colonne] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte lignePins[ligne] = {24,25,26,27}; //les pines des lignes
byte colonnePins[colonne] = {28,29,30,31}; //les pines des colonnes

byte soleil[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11011,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};

byte lune[8] = {
  0b11000,
  0b01100,
  0b00110,
  0b00110,
  0b00110,
  0b00110,
  0b01100,
  0b11000
};

byte troisG3[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00110,
  0b00000,
  0b00011
};

byte troisD1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b11000,
  0b10000
};

byte troisG4[8] = {
  0b00000,
  0b00110,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte troisD2[8] = {
  0b11000,
  0b11000,
  0b10000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte deuxG3[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00011,
  0b00110,
  0b00000,
  0b00001
};

byte deuxD1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b11000,
  0b10000
};

byte deuxG4[8] = {
  0b00011,
  0b00110,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte deuxD2[8] = {
  0b00000,
  0b11000,
  0b11000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte unD1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};

byte unD2[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte unG3[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00011,
  0b00001
};

byte unG4[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

LiquidCrystal lcd(8,9,4,5,6,7);
Keypad clavier_matric( makeKeymap(clavier), lignePins, colonnePins, ligne, colonne); //initialiser le clavier 
Servo monServo1,monServo2;
RTC_DS3231 rtc; 

void setup()
{
Serial.begin(9600);
  lcd.begin(16,2);// initialiser le lcd
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
  pinMode(pir,INPUT);
  digitalWrite(pir,LOW);
  rtc.begin();  
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //pour ajuster le temps et la date avec ceux de l'ordinateur
  //rtc.adjust(DateTime(2016,9,29,17,16,50));//pour ajuster le temps et la date avec notre propre choix
  monServo1.attach(10);
  monServo1.write(0); // fixer l’angle sur 0°
monServo2.attach(11);
monServo2.write(180); // fixer l’angle sur 0°
    
pinMode(led1,OUTPUT);
  digitalWrite(led1,LOW);
  pinMode(led2,OUTPUT);
  digitalWrite(led2,LOW); 
  pinMode(led3,OUTPUT);
  digitalWrite(led3,LOW);
  pinMode(led7,OUTPUT);
  digitalWrite(led7,LOW);
  pinMode(led5,OUTPUT);
  digitalWrite(led5,LOW);
  pinMode(led6,OUTPUT);
  digitalWrite(led6,LOW);
  pinMode(led4,OUTPUT);
  digitalWrite(led4,LOW);
  pinMode(led8,OUTPUT);
  digitalWrite(led8,LOW);
  pinMode(led10,OUTPUT);
  digitalWrite(led10,LOW);
  pinMode(led9,OUTPUT);
  digitalWrite(led9,LOW);
  pinMode(led11,OUTPUT);
  digitalWrite(led11,LOW);
  pinMode(led12,OUTPUT);
  digitalWrite(led12,LOW);
  pinMode(led13,OUTPUT);
  digitalWrite(led13,LOW);
   pinMode(led14,OUTPUT);
  digitalWrite(led14,LOW);
   pinMode(led15,OUTPUT);
  digitalWrite(led15,LOW);
   pinMode(led16,OUTPUT);
  digitalWrite(led16,LOW);
  pinMode(ph,INPUT);
  pinMode(gaz,INPUT);
//sensors.begin();
 dht.begin();
DateTime now = rtc.now();


   lcd.createChar(2,troisD1);
     lcd.setCursor(8,0);
     lcd.write(byte(2));

   lcd.createChar(3,troisD2);
     lcd.setCursor(8,1);
     lcd.write(byte(3));

   lcd.createChar(4,troisG3);
     lcd.setCursor(7,0);
     lcd.write(byte(4));

   lcd.createChar(5,troisG4);
     lcd.setCursor(7,1);
     lcd.write(byte(5));

delay(1600);
lcd.clear();

   lcd.createChar(6,deuxD1);
     lcd.setCursor(8,0);
     lcd.write(byte(6));

   lcd.createChar(7,deuxD2);
     lcd.setCursor(8,1);
     lcd.write(byte(7));

   lcd.createChar(8,deuxG3);
     lcd.setCursor(7,0);
     lcd.write(byte(8));

   lcd.createChar(9,deuxG4);
     lcd.setCursor(7,1);
     lcd.write(byte(9));

delay(1600);
lcd.clear();

   lcd.createChar(10,unD1);
     lcd.setCursor(8,0);
     lcd.write(byte(10));

   lcd.createChar(11,unD2);
     lcd.setCursor(8,1);
     lcd.write(byte(11));

   lcd.createChar(12,unG3);
     lcd.setCursor(7,0);
     lcd.write(byte(12));

   lcd.createChar(13,unG4);
     lcd.setCursor(7,1);
     lcd.write(byte(13));

delay(1600);
lcd.clear();

lcd.print("Pour utiliser le");
lcd.setCursor(4,1);
lcd.print("programme");
delay(2000);
lcd.clear();
              
        while(strcmp(Data,code1))
  {
  
      lcd.setCursor(0,0);
          lcd.print("Entrez le code");

          touche = clavier_matric.getKey();
          if (touche!=NO_KEY) // si on a appuyé sur une touche
          {
 
            Data[data_cpt] = touche; 
              lcd.setCursor(data_cpt,1); // pour faire bouger le curseur
              lcd.print("*"); // pour afficher la touche appuyée 
              data_cpt++; 
          }
  
          if(data_cpt == 4) // si on a tapé le code entierement 
          {
              lcd.clear();
              lcd.setCursor(2, 0);
              lcd.print("Le code est ");
              
  
              if(!strcmp(Data, code1)) // comparer l'egalité qui une fois vrai on reçoit 0 c'est pour cela qu'il faut mettre !
              {
                lcd.setCursor(3, 1);
                lcd.print("correct!!");
                delay(1500); 
                lcd.clear();               
              }
              else
              {
                lcd.setCursor(2, 1);
                lcd.print("incorrect!!");
                delay(1500);
                lcd.clear();
                viderData();
              }  
          }
  }

            viderData(); 

if((now.hour()>6)&&(now.hour()<18))
{
  lcd.setCursor(4,0);
  lcd.print("Bonjour!!");
  lcd.setCursor(5,1);
  lcd.print("(^_^)"); 
  delay(1500);
}
else
{
  lcd.setCursor(4,0);
  lcd.print("Bonsoir!!");
  lcd.setCursor(5,1);
  lcd.print("(^_^)"); 
  delay(1500);
}
lcd.clear();
lcd.setCursor(3,0);
    lcd.print("Bienvenu a");
    lcd.setCursor(3,1);
    lcd.print("la maison");
      delay(1500);

lcd.clear();
lcd.setCursor(6,0);
    lcd.print("EMSI");
    lcd.setCursor(2,1);
    lcd.print("SMART HOUSE");
 
      delay(2000);
lcd.clear();

lcd.setCursor(4,0);
    lcd.print("Un projet");
    lcd.setCursor(3,1);
    lcd.print("realise par");
 
      delay(1500);
lcd.clear();
lcd.setCursor(5,0);
    lcd.print("KHALIL");
    lcd.setCursor(1,1);
    lcd.print("ABOUABDELMAJID");
 
      delay(2000);
lcd.clear();
lcd.setCursor(0,0);
    lcd.print("et   MARIAM");
    lcd.setCursor(5,1);
    lcd.print("CHEHMAT");
 
      delay(2500);
lcd.clear();
lcd.setCursor(3,0);
    lcd.print("Propose et");
    lcd.setCursor(3,1);
    lcd.print("encadre par");
      delay(2000);
      
lcd.clear();
//lcd.setCursor(7,0);
  //  lcd.print("Monsieur");
    lcd.setCursor(5,0);
    lcd.print("MOHAMED");
    lcd.setCursor(6,1);
    lcd.print("TABAA");
      delay(3000);
lcd.clear();
}

void loop()
{
Serial.println(analogRead(0));
delay(10);
//Serial.println(analogRead(gaz));
//delay(10);
//Serial.println(touche);

  if(analogRead(ph)>100)
  {
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
    //delay(700);    
      lcd_init();
  
   lcd.createChar(1,lune);
     lcd.setCursor(15,0);
     lcd.write(byte(1));
demarche();
  
 }
else
  {
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);

  lcd_init();
  lcd.createChar(0,soleil);
  lcd.setCursor(15,0);
  lcd.write(byte(0));

 demarche();
  }
}

void demarche()
{
if(analogRead(gaz)>850)
  {
  monServo2.write(0);

 digitalWrite(led7,0);
  digitalWrite(led5,0);
  digitalWrite(led6,0);
  digitalWrite(led8,0);
  digitalWrite(led9,0);
  digitalWrite(led10,0);
digitalWrite(led11,0);
    digitalWrite(led12,0);
  digitalWrite(led13,0);
digitalWrite(led14,0);
    digitalWrite(led15,0);
  digitalWrite(led16,0);

    lcd.clear();
      while(analogRead(gaz)>800)
      {
        delay(10);
        //Serial.println(analogRead(gaz));
//delay(10);

  digitalWrite(buzzer,HIGH);
        delay(40);
  lcd.setCursor(3,0); 
          //                        lcd.clear();
        //                          lcd.print(analogRead(gaz));
        lcd.print("Fuite de");
        lcd.setCursor(5,1);
        lcd.print("gaz!!");
        //                        lcd.print(analogRead(gaz));
        delay(500);
        lcd.clear();
        digitalWrite(buzzer,LOW);
        delay(40);
      }
  //monServo2.write(0);
  lcd.clear();
  lcd.setCursor(2,0); 
        lcd.print("Il n'y a plus");
        lcd.setCursor(4,1);
        lcd.print("de gaz");
        delay(1500);
    lcd.clear();
 }
  

if(analogRead(0)>1&&analogRead(0)<20) //bouton RIGHT
{ 
  digitalWrite(led7,y);
  digitalWrite(led5,y);
  digitalWrite(led6,y);
  delay(200);
 }

if(digitalRead(led7)==0&&digitalRead(led5)==0)
 y=1;
if(digitalRead(led7)==1&&digitalRead(led5)==1)
 y=0;


if(analogRead(0)>200&&analogRead(0)<300)//bouton UP
{ 
  digitalWrite(led8,x);
  digitalWrite(led9,x);
  digitalWrite(led10,x);
  delay(200);
 }

if(digitalRead(led8)==0)
 x=1;
if(digitalRead(led8)==1)
 x=0;


if(analogRead(0)>750&&analogRead(0)<1000)//bouton LEFT
{ 
  digitalWrite(led11,z);
    digitalWrite(led12,z);
  digitalWrite(led13,z);
  delay(200);
 }

if(digitalRead(led11)==0)
 z=1;
if(digitalRead(led11)==1)
 z=0;
 
if(analogRead(0)>500&&analogRead(0)<700)//bouton DOWN
 { 
  digitalWrite(led14,w);
    digitalWrite(led15,w);
  digitalWrite(led16,w);
  delay(200);
 }

if(digitalRead(led14)==0)
 w=1;
if(digitalRead(led15)==1)
 w=0;


/*if(analogRead(0)>230&&analogRead(0)<250)//bouton UP
 { 
    if(v==0)
    {
      monServo2.write(180);
      v=1;
    }  
    else
    {
      monServo2.write(0);
      v=0;
    }         
 }*/

  if(digitalRead(pir)==HIGH&&alrm==1)///////////////////////////////////////////////////////////
  {
    cpt=0;
    lcd.clear();
    while(strcmp(Data,code2)&&alrm==1)
    {
      lcd.setCursor(3,0);
      while(cpt!=1)
      {
        digitalWrite(buzzer,HIGH);
        lcd.print("Mouvement");
        lcd.setCursor(3,1);
        lcd.print("detecte!!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pour desactiver");
        lcd.setCursor(4,1);
        lcd.print("l'alarme");
        delay(1500);
        lcd.clear();
        cpt++;
      }  
      lcd.setCursor(0,0);
      lcd.print("Entrez le code");
      
      digitalWrite(buzzer,HIGH);
      delay(40);
      
      touche = clavier_matric.getKey();
      if (touche!=NO_KEY) // si on a appuyé sur une touche
      {
          Data[data_cpt] = touche; 
          lcd.setCursor(data_cpt,1); // pour faire bouger le curseur
          lcd.print("*"); // pour afficher la touche appuyée 
          data_cpt++; 
      }

      digitalWrite(buzzer,LOW);
      delay(40);
      
      if(data_cpt == 4) // si on a tapé le code entierement 
      {
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("Le code est ");
          
          if(!strcmp(Data, code2)) // comparer l'egalité qui une fois vrai on reçoit 0 c'est pour cela qu'il faut mettre !
           {
            digitalWrite(buzzer,LOW);
            lcd.setCursor(3, 1);
            lcd.print("correct!!");
            delay(2000);
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("L'alarme est ");
            lcd.setCursor(3, 1);
            lcd.print("desactivee ");
            delay(2000);
            lcd.clear();
            alrm=0;
           }
          else
            {
              lcd.setCursor(2, 1); 
              lcd.print("incorrect!!");
              delay(3000);
              lcd.clear();  
            }
          viderData();   
      }    
    }
  } 

 touche=clavier_matric.getKey();  

   if(touche!=NO_KEY)//////////////////////////////////////////
{
  if(touche=='#')
      {  
        lcd.clear();
        porte=0;
        lcd.setCursor(0,0);
        lcd.print("Pour ouvrir la");
        lcd.setCursor(4,1);
        lcd.print("porte");
        delay(1000);
        lcd.clear();
              
        while(strcmp(Data,code2)&&porte==0)
{
  
  lcd.setCursor(0,0);
        lcd.print("Entrez le code");
              touche = clavier_matric.getKey();

  if (touche!=NO_KEY) // si on a appuyé sur une touche
        {
          Data[data_cpt] = touche; 
          lcd.setCursor(data_cpt,1); // pour faire bouger le curseur
          lcd.print("*"); // pour afficher la touche appuyée 
          data_cpt++; 
        }
  
      if(data_cpt == 4) // si on a tapé le code entierement 
      {
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("Le code est ");
  
          if(!strcmp(Data, code2)) // comparer l'egalité qui une fois vrai on reçoit 0 c'est pour cela qu'il faut mettre !
           {
            //digitalWrite(buzzer,LOW);
            lcd.setCursor(3, 1);
            lcd.print("correct!!");
 
            for(iAngle=0; iAngle<= 180; iAngle+=10 ) //varie l’angle de 0°à 180°
              {
                monServo1.write(iAngle);
              }
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("La porte est ");
            lcd.setCursor(4, 1);
            lcd.print("ouverte");
    lcd.setCursor(15, 1);
lcd.print("5");
            delay(1000);
lcd.setCursor(15, 1);
lcd.print("4");
            delay(1000);
            lcd.setCursor(15, 1);
lcd.print("3");
            delay(1000);
lcd.setCursor(15, 1);
lcd.print("2");
            delay(1000);
lcd.setCursor(15, 1);
lcd.print("1");
            delay(1000);
lcd.setCursor(15, 1);
lcd.print("0");
            delay(1000);
            for(iAngle=180; iAngle>=0; iAngle-=10 ) //varie l’angle de 0°à 180°
              {
                monServo1.write(iAngle);
              }
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("La porte est ");
            lcd.setCursor(5, 1);
            lcd.print("fermee");
            delay(2000);
            porte=1;
            lcd.clear();
            
            if(alrm==1)
              {
               alrm=0; 
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print("Systeme d'alarme");
               lcd.setCursor(4,1);
               lcd.print("innactif");
               delay(1000);
               lcd.clear();       
              }
           }
          else
            {
              lcd.setCursor(2, 1);
              lcd.print("incorrect!!");
              delay(2000);
              lcd.clear();
            }
            viderData();   
      }
  }
}

  if(touche=='*'&&alrm==1)///////////////////////////////////////////////////
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Systeme d'alarme");
    lcd.setCursor(3,1);
    lcd.print("deja actif");
    delay(2000);
    lcd.clear();
  }  
 else
  {
      if(touche=='*'&&alrm==0)
      {
      alrm=0;
      cpt=0;
      while(strcmp(Data,code1)&&alrm==0)
      {
        while(cpt!=1)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pour activer le");
        lcd.setCursor(0,1);
        lcd.print("systeme d'alarme");
        delay(2500);
        lcd.clear();
        cpt++;
      }  
        lcd.setCursor(0,0);
        lcd.print("Entrez le code");
        touche = clavier_matric.getKey();
        if (touche!=NO_KEY) // si on a appuyé sur une touche
        {
          //Serial.print(touche);
            Data[data_cpt] = touche; 
            lcd.setCursor(data_cpt,1); // pour faire bouger le curseur
            lcd.print("*"); // pour afficher la touche appuyée 
            data_cpt++; 
        }
    
        if(data_cpt == 4) // si on a tapé le code entierement 
        {
            lcd.clear();
            lcd.setCursor(2, 0);
            lcd.print("Le code est ");
    
            if(!strcmp(Data, code2)) // comparer l'egalité qui une fois vrai on reçoit 0 c'est pour cela qu'il faut mettre !
             {
              lcd.setCursor(3, 1);
              lcd.print("correct!!");
              delay(2000);
              lcd.clear();
              alrm=1;
              lcd.setCursor(0,0);
              lcd.print("Systeme d'alarme");
              lcd.setCursor(5,1);
              lcd.print("actif");
              delay(1500);
              lcd.clear();
             }
            else
              {
                lcd.setCursor(2, 1);
                lcd.print("incorrect!!");
                delay(3000);
                lcd.clear();  
              }
            viderData();   
        }    
      }
  } 
}
}  
}




void viderData()
{
  while(data_cpt !=0)
  {    
    Data[data_cpt--] = 0; //pour vider les données enregistrées
  }
  return;
}

void lcd_init()
{
DateTime now = rtc.now();
  lcd.setCursor(0,0);
  if(now.day()<10)
    {
     lcd.print(0);
    }
  lcd.print(now.day());
  lcd.print('/');
  if(now.month()<10) 
     {
      lcd.print(0);
     }
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());  

lcd.setCursor(11,0);
//lcd.print(analogRead(gaz));
//lcd.clear();
//lcd.print(analogRead(0));
  
  lcd.setCursor(0,1);
  if(now.hour()<10)
    {
     lcd.print(0);
    }
  lcd.print(now.hour());
  lcd.print(':');
  if(now.minute()<10)
    {
     lcd.print(0);
    }
  lcd.print(now.minute());
  lcd.print(':');
  if(now.second()<10)
    {
     lcd.print(0);
   }
  lcd.print(now.second());
  lcd.setCursor(10,1);
  //sensors.requestTemperatures();  
  //lcd.print(sensors.getTempCByIndex(0),1);  
    lcd.print(dht.readTemperature(0),1);

  lcd.print((char)223);
  lcd.print('C');
}

 

 
 
