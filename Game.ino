#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int btn = 8; 
int game=0;
int buttonPress = 0; 
int buttonState = 0;
int Posizyon; //karakterin pozistonu
int obsSpeed; //Süre ve mesafe
int score=0;
unsigned long lastDebounceTime = 0;
int lastButtonState=LOW;

byte PlayerRun1[8] = {
  B01110,
  B10001,
  B10001,
  B01110,
  B00101,
  B00110,
  B00100,
  B00010
};
byte PlayerRun2[8] = {
  B01110,
  B10001,
  B10001,
  B01110,
  B10100,
  B01100,
  B00100,
  B01000
};
byte Playerjump[8]={
  B01110,
  B10001,
  B10001,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010
};
byte Yuvarlak1[8] = {
  B01110,
  B11011,
  B11111,
  B00111,
  B00111,
  B11111,
  B11111,
  B01110
};
byte Yuvarlak12[8]={
  B01110,
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110
};

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,PlayerRun1);
  lcd.createChar(1,PlayerRun2);
  lcd.createChar(2,Playerjump);
  lcd.createChar(3,Yuvarlak1);
  lcd.createChar(4,Yuvarlak2);
  pinMode(btn,INPUT);
  buttonState=digitalRead(btn);
}

void loop()
{
    score=0;
    lcd.clear();
    delay(2000);
    lcd.clear();
    while(button()!=1)    
    {
      lcd.setCursor(0,0); 
      lcd.print("Welcome The Game"); 
      lcd.setCursor(0,1);                
      lcd.print(" Press To Start "); 
      delay(100);
    } 
   if(button()==1)
      game=1;
    while(game==1) 
      OyunHareketleri();
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Your Score:");
    lcd.print(score);
    lcd.setCursor(7,1);
    lcd.write(2);
    lcd.setCursor(9,1);
    lcd.write(3);
    delay(3000); 
}
 void reset()
 {
      if(Posizyon%2==0)   //Koşma efekti      
      {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.write(0);
      }
      else
      {
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.write(1);
      }
 }

 void OyunHareketleri()
 {
  obsSpeed=250;   //yuvarlak için hız ve mesafe
  Posizyon=15;   //Başlangıç konumu
  while(game==1)
  {
       reset();
       if(button()==1)      //if button is pressed.
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.write(2);            //Zıpladığındaki tipi
          YuvarlakHareketi(Posizyon);   //Yuvarlakları ekrana basar 
          delay(400);
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.write(1);           
          YuvarlakHareketi(Posizyon);          
        }
        else
        {
          if(Posizyon!=0)        //eğer herhangi bişeye değmez ise
          {
              reset();
              YuvarlakHareketi(Posizyon);
          }
          else if(Posizyon==0)   //bişeye değerse oyun biter
          {
             game=0;
             break;
          }
        }
        Posizyon--;               
        if(Posizyon<0)      //tekrardan oyunun yenilenmesi     
        {                             
          obsSpeed=obsSpeed-15;    //Yuvarlağın adama gelme hızı ve konumu
          Posizyon=15;             //Yuvarlak Başlangıc Yeri
          score++;                 
        }
       delay(obsSpeed);
    }
  }
int button() 
{
     int reading = digitalRead(btn);
     if (reading != lastButtonState) {
       lastDebounceTime = millis();  //ekranda tekrarlanma zamanı
     } 
     lastButtonState = reading;
}
void YuvarlakHareketi(int i)
{ 
          if(Posizyon%2==0 && Posizyon>-1)
          {
              lcd.setCursor(i,1);
              lcd.write(3);
          }
          else if(Posizyon%2!=0 && Posizyon>-1)
          {
              lcd.setCursor(i,1);
              lcd.write(4);
          }
}
