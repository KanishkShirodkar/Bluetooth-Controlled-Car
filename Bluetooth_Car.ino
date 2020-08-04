
//L293 Connection   
  const int rightmotorfront  = 5;  
  const int rightmotorback  = 6;  
  const int leftmotorfront  = 9; 
  const int leftmotorback  = 10;  
//Useful Variables
  char state;
  int vSpeed=255;  

  // Default speed, from 0 to 255

void setup() {
    // Set pins as outputs:
    pinMode(rightmotorfront, OUTPUT);
    pinMode(rightmotorback, OUTPUT);
    pinMode(leftmotorfront, OUTPUT);
    pinMode(leftmotorback, OUTPUT);

     
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
  //Stop car when connection lost or bluetooth disconnected
//    

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
       Serial.print(state); 
    }
  
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=130;}
      else if (state == '3'){
      vSpeed=145;}
      else if (state == '4'){
      vSpeed=160;}
      else if (state == '5'){
      vSpeed=180;}
      else if (state == '6'){
      vSpeed=190;}
      else if (state == '7'){
      vSpeed=210;}
      else if (state == '8'){
      vSpeed=230;}
    else if (state == '9'){
      vSpeed=240;}
    else if (state == 'q'){
      vSpeed=255;}
     
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
      analogWrite(rightmotorfront, vSpeed);
        analogWrite(rightmotorback, 0);
        analogWrite(leftmotorfront, vSpeed);   
        analogWrite(leftmotorback, 0); 
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
      analogWrite(rightmotorfront, vSpeed); 
        analogWrite(rightmotorback, 0);  
        analogWrite(leftmotorfront, 0);
        analogWrite(leftmotorback, (vSpeed-160)); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
        analogWrite(rightmotorfront, 0);
        analogWrite(rightmotorback, (vSpeed-160)); 
        analogWrite(leftmotorfront, vSpeed);   
        analogWrite(leftmotorback, 0); 
    }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
      analogWrite(rightmotorfront, 0);  
        analogWrite(rightmotorback,vSpeed ); 
        analogWrite(leftmotorfront, 0); 
        analogWrite(leftmotorback, vSpeed); 
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') {
      analogWrite(rightmotorfront, 0);   
        analogWrite(rightmotorback, vSpeed); 
        analogWrite(leftmotorfront, (vSpeed-160));
        analogWrite(leftmotorback, 0); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') {
      analogWrite(rightmotorfront, (vSpeed-160)); 
        analogWrite(rightmotorback, 0); 
        analogWrite(leftmotorfront, 0); 
        analogWrite(leftmotorback, vSpeed); 
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn left
    else if (state == 'R') {
      analogWrite(rightmotorfront, 0); 
        analogWrite(rightmotorback, vSpeed); 
        analogWrite(leftmotorfront, vSpeed);
        analogWrite(leftmotorback, 0); 
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn right
    else if (state == 'L') {
      analogWrite(rightmotorfront, vSpeed);  
        analogWrite(rightmotorback, 0); 
        analogWrite(leftmotorfront, 0);  
        analogWrite(leftmotorback, vSpeed);     
    }
      /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(rightmotorfront, 0); 
        analogWrite(rightmotorback, 0); 
        analogWrite(leftmotorfront, 0); 
        analogWrite(leftmotorback, 0);
    }
 

 
    
}
