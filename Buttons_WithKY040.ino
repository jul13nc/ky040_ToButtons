const int octoRight=2;
const int octoLeft=8;
const int pin_clk = 6;  
const int pin_dt = 5;

// Initialization of the needed variables<br />
int clk_latest;  
int clk_current;
 
  
void loop()
{ 
   // Reading of the current status  
   clk_current = digitalRead(pin_clk);
    
   // Check for a Change
   if (clk_current != clk_latest)
   { 
          
        if (digitalRead(pin_dt) != clk_current) 
        {  
            // Pin_CLK has changed first
            Serial.println ("Clockwise");
            goRight();
        } 
          
        else
        {       // Else Pin_DT changed first
            Serial.println("Counterclockwise");
            goLeft();
        }

   } 
    
   // Preparation for the next run:
   // The current value will be the last value for the next run.
   clk_latest = clk_current;
    
   
      
 } 

void setup() {
  // put your setup code here, to run once:
  pinMode(octoLeft,OUTPUT);
  pinMode(octoRight,OUTPUT);
   // Initialization of the input-pins...
   pinMode (pin_clk,INPUT);
   pinMode (pin_dt,INPUT);
    
   // ...and activating of their pull up resistors
   digitalWrite(pin_clk, true);
   digitalWrite(pin_dt, true);
    
   // Initial reading of the Pin_CLK
   clk_latest = digitalRead(pin_clk);   
   Serial.begin (115200);
}

void goLeft() {
  pushButton(octoLeft);
}

void goRight() {
  pushButton(octoRight);
}

void pushButton(int button) {
  digitalWrite(button,HIGH);
  delay(40);
  digitalWrite(button,LOW);
}
