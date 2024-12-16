  
  #include <PS2X_lib.h>
  
  PS2X ps2x; // create PS2 Controller Class
  
  int error = 0; 
  byte type = 0;
  byte vibrate = 0;
 
  
//=== Defines Pins Numbers ====
                //Driver Motor 1 1
                #define IN1_D1 A4
                #define IN2_D1 A5
                #define IN3_D1 A2
                #define IN4_D1 A3

                //Driver Motor 2 2
                #define IN1_D2 5//5
                #define IN2_D2 6
                #define IN3_D2 7
                #define IN4_D2 8  
//======= Control speed =======
                #define MotorSpeed 9  
                int motorSpeed=255;
   
//========= Void Setup ========  
  void setup(){
   Serial.begin(57600);
   //error = ps2x.config_gamepad(22,23,24,25, true, true);
   error = ps2x.config_gamepad(13,11,10,12, false, false); //(13clock, 11command, 10attention, 12data, Pressures?, Rumble?) 
   delay (300);

            pinMode(IN1_D1,OUTPUT);
            pinMode(IN2_D1,OUTPUT);
            pinMode(IN3_D1,OUTPUT);
            pinMode(IN4_D1,OUTPUT);
            
            pinMode(IN1_D2,OUTPUT);
            pinMode(IN2_D2,OUTPUT);
            pinMode(IN3_D2,OUTPUT);
            pinMode(IN4_D2,OUTPUT);
            
            pinMode(MotorSpeed,OUTPUT);

            pinMode(IN1_D1,LOW);
            pinMode(IN2_D1,LOW);
            pinMode(IN3_D1,LOW);
            pinMode(IN4_D1,LOW);
            
            pinMode(IN1_D2,LOW);
            pinMode(IN2_D2,LOW);
            pinMode(IN3_D2,LOW);
            pinMode(IN4_D2,LOW);
            pinMode(MotorSpeed,0);
   }
  
//======================================================================================
// ====================================Main loop =======================================
  void loop(){
     
   if(error == 1)                           //skip loop if no controller found
    return; 
    
   else { //DualShock Controller
    
       ps2x.read_gamepad(false, vibrate);   // disable vibration of the controller
       
//============================= Left JoyStick ==============================
  
      int nJoyL = ps2x.Analog(PSS_LX); // read left stick
      int NJoyL = ps2x.Analog(PSS_LY); // read  left stick
      NJoyL = map(NJoyL, 128, 0, 0, 1023);
      nJoyL = map(nJoyL, 128, 0, 0, 1023);
      int nJoyR = ps2x.Analog(PSS_RX); // read left stick
      int NJoyR = ps2x.Analog(PSS_RY); // read  left stick
      NJoyR = map(NJoyR, 128, 0, 0, 1023);
      nJoyR = map(nJoyR, 128, 0, 0, 1023);
              if(ps2x.Button(PSB_L3))  {stop_backward();}
              else if(NJoyL>0){forward();Serial.println(NJoyL);}
              else if(NJoyL<0){backward();}
              else if(nJoyL<0){right();}
              else if(nJoyL>0){left();}  
//============================ Right JoyStick ============================== 
              else if(NJoyR>0){motorSpeed = 120;forward();}
              else if(NJoyR<0){motorSpeed = 120;backward();}
              else if(nJoyR<0){motorSpeed = 120;right();}
              else if(nJoyR>0){motorSpeed = 120;left();}          
//==========================================================================
      
//===========================================Button LEFT =============================================
      else if(ps2x.Button(PSB_PAD_UP))    {forward();}
      else if(ps2x.Button(PSB_PAD_DOWN))  {backward();}
      else if(ps2x.Button(PSB_PAD_RIGHT)) {right();}
      else if(ps2x.Button(PSB_PAD_LEFT))  {left();}
      
      else if(ps2x.ButtonReleased(PSB_PAD_RIGHT)){stop_all();}
      else if(ps2x.ButtonReleased(PSB_PAD_DOWN)) {stop_all();}
      else if(ps2x.ButtonReleased(PSB_PAD_LEFT)) {stop_all();}
      else if(ps2x.ButtonReleased(PSB_PAD_UP))   {stop_all();}
      
//=======================================Button Right=======================================================
      else if(ps2x.Button(PSB_GREEN)) {forward();}
      else if(ps2x.Button(PSB_PINK))  {circle();}            
      else if(ps2x.Button(PSB_RED))   {circle();} 
      else if(ps2x.Button(PSB_BLUE))  {right_L();} 
            
      //if(ps2x.ButtonReleased(PSB_GREEN)){stop_all();} 
      else if(ps2x.ButtonReleased(PSB_RED))  {stop_all();}
      else if(ps2x.ButtonReleased(PSB_PINK)) {stop_all();} 
      else if(ps2x.ButtonReleased(PSB_BLUE)) {stop_all();}              
       
            
        
         
//======================================= L1 L2 R1 R2 ===============================================
      else if(ps2x.Button(PSB_L1))  {top_left();}
      else if(ps2x.Button(PSB_R1))  {top_right();}
      else if(ps2x.Button(PSB_R2))  {bottom_right();}
      else if(ps2x.Button(PSB_L2))  {bottom_left();}
      else if(ps2x.Button(PSB_R3))  {stop_backward();}
      
       
      else if(ps2x.ButtonReleased(PSB_L1)) {stop_all();}              
      else if(ps2x.ButtonReleased(PSB_R1)) {stop_all();} 
      else if(ps2x.ButtonReleased(PSB_R2)) {stop_all();}         
      else if(ps2x.ButtonReleased(PSB_L2)) {stop_all();}      
      else if(ps2x.ButtonReleased(PSB_R3)) {stop_all();}         
      else if(ps2x.ButtonReleased(PSB_L3)) {stop_all();}
      else {stop_all();}     
     
      
//=====================================================================================================     
   delay(50);
   }    
  }
//=========================================== END LOOP ================================================

void forward(){
      analogWrite(MotorSpeed,250);
      //MOTOR 1
      digitalWrite(IN1_D1,0);
      digitalWrite(IN2_D1,1);
      //MOTRO 2
      digitalWrite(IN3_D1,0);
      digitalWrite(IN4_D1,1);
      
      //MOTOR 3
      digitalWrite(IN1_D2,0);
      digitalWrite(IN2_D2,1);
      //M0TOR 4
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,1);
}
void backward(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,1);
      digitalWrite(IN2_D1,0);
      //MOTRO 2
      digitalWrite(IN3_D1,1);
      digitalWrite(IN4_D1,0);
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 3
      digitalWrite(IN1_D2,1);
      digitalWrite(IN2_D2,0);
      //M0TOR 4
      digitalWrite(IN3_D2,1);
      digitalWrite(IN4_D2,0);
} 
void left(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,1);
      digitalWrite(IN2_D1,0);
      //MOTRO 2
      digitalWrite(IN3_D1,0);
      digitalWrite(IN4_D1,1);
      
      //MOTOR 3
      digitalWrite(IN1_D2,1);
      digitalWrite(IN2_D2,0);
      //M0TOR 4
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,1);
}   
void right(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,0);
      digitalWrite(IN2_D1,1);
      //MOTRO 2
      digitalWrite(IN3_D1,1);
      digitalWrite(IN4_D1,0);
      
      //MOTOR 3
      digitalWrite(IN1_D2,0);
      digitalWrite(IN2_D2,1);
      //M0TOR 4
      digitalWrite(IN3_D2,1);
      digitalWrite(IN4_D2,0);
}  
void circle(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,0);
      digitalWrite(IN2_D1,1);
      //MOTRO 2
      digitalWrite(IN3_D1,1);
      digitalWrite(IN4_D1,0);
      
      //MOTOR 3
      digitalWrite(IN1_D2,1);
      digitalWrite(IN2_D2,0);
      //M0TOR 4
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,1);
}        
void top_right(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,0);
      digitalWrite(IN2_D1,1);
      
      //MOTOR 3
      digitalWrite(IN1_D2,0);
      digitalWrite(IN2_D2,1);
}
void top_left(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTRO 2
      digitalWrite(IN3_D1,0);
      digitalWrite(IN4_D1,1);
      
      //M0TOR 4
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,1);
} 
void bottom_left(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 1
      digitalWrite(IN1_D1,1);
      digitalWrite(IN2_D1,0);
      
      //MOTOR 3
      digitalWrite(IN1_D2,1);
      digitalWrite(IN2_D2,0);
}
void bottom_right(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTRO 2
      digitalWrite(IN3_D1,1);
      digitalWrite(IN4_D1,0);
      
      //M0TOR 4
      digitalWrite(IN3_D2,1);
      digitalWrite(IN4_D2,0);
}  
void stop_backward(){
      analogWrite(MotorSpeed,motorSpeed);

      //MOTRO 2
      digitalWrite(IN3_D1,0);
      digitalWrite(IN4_D1,1);
      
      //MOTOR 3
      digitalWrite(IN1_D2,0);
      digitalWrite(IN2_D2,1);
      //M0TOR 4
      digitalWrite(IN3_D2,1);
      digitalWrite(IN4_D2,0);
} 
void right_L(){
      analogWrite(MotorSpeed,motorSpeed);
      //MOTOR 3
      digitalWrite(IN1_D2,1);
      digitalWrite(IN2_D2,0);
      //M0TOR 4
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,1);
}                                                                 
void stop_all(){
      analogWrite(MotorSpeed,0);
      digitalWrite(IN1_D1,0);
      digitalWrite(IN2_D1,0);
      digitalWrite(IN3_D1,0);
      digitalWrite(IN4_D1,0);
      analogWrite(MotorSpeed,0);
      digitalWrite(IN1_D2,0);
      digitalWrite(IN2_D2,0);
      digitalWrite(IN3_D2,0);
      digitalWrite(IN4_D2,0);
}
