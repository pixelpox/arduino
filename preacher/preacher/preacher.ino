#include <SD.h>
#include <SPI.h>

File myFile;

const int chipSelect = BUILTIN_SDCARD;
int led = 13;
char theGoodBook[] = "1:line \n2:line"
"\n3:line\n";
int count = 0;
int len = strlen(theGoodBook);

void loadSDCard()
{
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) 
  {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  
}

void setup()
{ 
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  digitalWrite(led, HIGH);
  delay(5000);

  loadSDCard();
  
  
}

void loop()
{
  //open the file for reading:
  myFile = SD.open("bible.txt");
  if (myFile) 
  { 
    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
      digitalWrite(led, HIGH);
      delay(500);
      char letter = myFile.read();
      Keyboard.print(letter);
      digitalWrite(led, LOW);
      delay(500);
    }
    // close the file:
    Keyboard.print("\n");
    Keyboard.print("\n");
    myFile.close();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}


