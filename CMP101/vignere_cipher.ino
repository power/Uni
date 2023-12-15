/*
 * The OLED board is directly connected to the board:

  GND-GND
  
  VCC-5V
  
  SCL-SCL
  
  SDA-SDA
  

  The 7seg board is directly connected to the board:

  VCC-3V3
  
  GND-GND
  
  STD-D5
  
  CLK-D6
    
  DIO-D7
  
 */

// Including all the libraries we need
#include <Streaming.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <InvertedTM1638.h>
#include <TM1638.h>

// Define anything we need here
#define OLED_RESET -1
#define OLED_SCREEN_I2C_ADDRESS 0x3C
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define TM1638_STB D5
#define TM1638_CLK D6
#define TM1638_DIO D7

TM1638 module(TM1638_DIO, TM1638_CLK, TM1638_STB);

// Global Variables
int shift = 0; //used for 7seg
String encrypted = ""; // encrypted, original and uKey are used throughout the encryption/decryption process
String original = "";
String uKey = "";
int choice = 0; // used for menu interaction

void setup() { // setting up the OLED display and 7 seg

  //OLED setup
  display.begin(SSD1306_SWITCHCAPVCC, OLED_SCREEN_I2C_ADDRESS);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);    // 21 chars per line
  display.setTextColor(WHITE);

  pinMode(LED_BUILTIN, OUTPUT);
  
  module.clearDisplay();
  module.setupDisplay(true, 2);
  
  
  //allows for input to be taken for the Serial monitor
  Serial.begin(115200);
}


String encryption(String original, String key) { 
  display.clearDisplay();
  display.setCursor(0, 0);
  String output = "";
  String k = key;
  char temp;
  
  for (int i = 0, b = 0; i < original.length(); i++) {
    char a = original[i];
    if (a >= 'a' && a <= 'z')
    {
      a += 'A' - 'a';
    }
    else if (a < 'A' || a > 'Z')
    {
      continue;
    }
    temp = (a + k[b] - 2 * 'A') % 26 + 'A'; // add A so that it's within the range of the ASCII alphabet (65-90)
    shift += (a + k[b] - 2 * 'A') % 26 + 'A';
    // Error checking - Serial.println((c + k[j] - 2 * 'A') % 26 + 'A');
    output += temp; 
    b = (b + 1) % k.length();
  }
  Serial.print("The encrypted text is: ");
  Serial.println(output);
  Serial.print("The original text is: ");
  Serial.println(original);

  display << "Original: " << original;
  display << "\n";
  display << "Encrypted: " << output;
  display.display();
  delay(5000);
}


String decryption(String encrypted, String key) {
  display.clearDisplay();
  display.setCursor(0, 0);
  String decrypted = "";
  String k = key;
  char temp;
  for (int i = 0, b = 0; i < encrypted.length(); ++i) {
    char a = encrypted[i];
    if (a >= 'a' && a <= 'z')
      a += 'A' - 'a';
    else if (a < 'A' || a > 'Z')
      continue;
    temp = (a - k[b] + 26) % 26 + 'A';
    shift += (a - k[b] + 26) % 26 + 'A';
    decrypted += temp;//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
    b = (b + 1) % k.length();
  }

  Serial.print("The encrypted text is: ");
  Serial.println(encrypted);
  Serial.print("The original text is: ");
  Serial.println(decrypted);
  
  display << "Encrypted: " << encrypted;
  display << "\n\n";
  display << "Original: " << decrypted;
  display.display();
}

  void Blink(int numOfBlinks)
  {
  for (int i = 0; i < numOfBlinks; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH); //high voltage, light on
    delay(500); //delay's in ms, 1000 = 1 second
    digitalWrite(LED_BUILTIN, LOW);  //low voltage, lght off
    delay(500);
  }
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  // First output
  display << "What is your message that you would like to encrypt/decrypt?";
  display << "\n\nAfter selecting a message to encrypt, please input a key";
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  // User text input
  while (!Serial.available()) {};
  do {
    original = Serial.readString();
  } while (!original);
  // Show them what they inputted
  display << "The text you are using is: ";
  display << original;
  display.display();

  // Take input for key
  while (!Serial.available()) {};
  do {
    uKey = Serial.readString();
  } while (!uKey);

  // Make it uppercase or ASCII conversion gets messy
  
  uKey.toUpperCase();
  /* Couldn't quite figure out how to make this work, although we were changing the variable and the function would confirm that, it just didn't save
   *  hithere - hello = OMESS8L ;; difference between hello and hithere is 2 thus the last two letters aren't accounted for
  while (uKey.length() != original.length()) { // This should make the length of the key and the plaintext the same
    delay(1000);
      if (uKey.length() < original.length()) 
      {
          delay(1000);
          uKey += uKey;
          Serial.println(uKey);
      }
      else if (uKey.length() > original.length()) 
      {
        delay(1000);
        int lastIndex = uKey.length() - 1;
        uKey.remove(lastIndex);
        Serial.println(uKey);
      }
  }
  */

  // Show the user what they inputted
  display << "\n\nThe key you are using is: ";
  display << uKey;
  display.display();

  display.clearDisplay();
  display.setCursor(0, 0);
  display << "What would you like to do with the text?\n1. Encrypt a message\n 2. Decrypt a message ";
  display.display();
  delay(5000);

  
  choice = Serial.readString().toInt();
  if (choice == 1)
  {
      encryption(original, uKey);
  }
  else
  {
      decryption(original, uKey);
  }
  // User choice for encrypting/decrypting, might be worth making the input further up better worded

  
  module.setDisplayToDecNumber(shift, 0, false); //format: the number to be displayed, where the decimal on the 7seg should be, and should it show leading 0's 
  Blink(shift);
}
