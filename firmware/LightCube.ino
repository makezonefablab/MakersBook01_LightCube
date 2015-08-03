// 3d printing + arduino + triple axis accelerometer 를 이용한 Light Cube 만들기 위한 아두이노 소스입니다. 
// http://cafe.naver.com/makezone/  
// By MAKEZONE FABRICATION LAB 

//3축 가속도센서의 X,Y,Z값을 각각 아날로그 0,1,2핀에 연결합니다. 
#define A_X  0
#define A_Y  1
#define A_Z  2

int LED_1 = 1;
int LED_2 = 2;
int LED_3 = 3;
int LED_4 = 4;
int LED_5 = 5;
int LED_6 = 6;

//RGB led의 R,G,B를 아두이노의 디지털 핀 9,10,11에 연결합니다.  
int r = 9;
int g = 10;
int b = 11;

int val_x,val_y,val_z;
int dx, dy, dz;

void setup()
{
  Serial.begin(115200);
  
  pinMode(A_X,INPUT);
  pinMode(A_Y,INPUT);
  pinMode(A_Z,INPUT);

  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);

  dx = analogRead(A_X);
  dy = analogRead(A_Y);
  dz = analogRead(A_Z);
}

void loop() {
  
  // 센서에서 들어오는 값을 serial monitor로 확인 할 수 있습니다. 
  //    Serial.print(x);
  //    Serial.print("\t");
  //    Serial.print(y);
  //    Serial.print("\t");
  //    Serial.println(z);
  
  // 가속도 센서에서 들어온 default 값에서 현재의 값을 뺀 후,
  // 세자리 수로 들어오는 센서의 값을 1의 자릿수로 변환하기 위해 100으로 나누어줍니다.    
  int x = (dx - analogRead(A_X)) / 100;
  int y = (dy - analogRead(A_Y)) / 100;
  int z = (dz - analogRead(A_Z)) / 100;
    
  // 이 부분부터는 달라질 수 있습니다. 센서를 정육면체 도형에 살짝 부착시키신 후,
  // 각 면마다 들어오는 값을 확인해주세요. 
  // 만약 아래 코드와 다르다면 해당하는 면의 x,y,z값을 수정해주시면 됩니다. 

  if(x == 0 && y == 0 && z == 0) {
    on(LED_1);
  }
  else if(x == -1 && y == 0 && z == 1) {
    on(LED_2);
  }
  else if(x == 0 && y == -1 && z == 1) {
    on(LED_3);
  }
  else if(x == 1 && y == 0 && z == 1) {
    on(LED_4);
  }
  else if(x == 0 && y == 1 && z == 1) {
    on(LED_5);
  }
  else if(x == 0 && y == 0 && z == 3) {
    on(LED_6);
  }

  delay(100);   // 센서 값이 들어오는 속도를 조절합니다. 

}


void on(int num) {

  // LED의 색이 바뀌는 부분입니다. 6개의 면에 원하시는 색으로 설정해주세요. 
  // 원하시는 색을 빛으로 나타내기 위해서 각 0에서 255값이 필요합니다. 
  // 255,255,255 -> white / 0,0,0 -> black  

  if(LED_1 == num){       // White
    analogWrite(r, 255);
    analogWrite(g, 255);
    analogWrite(b, 250);
  }
  if(LED_2 == num){  
    analogWrite(r, 0);
    analogWrite(g, 250);
    analogWrite(b, 50);
  }
  if(LED_3 == num){  
    analogWrite(r, 205);
    analogWrite(g, 255);
    analogWrite(b, 0);
  }
  if(LED_4 == num){   
    analogWrite(r, 0);
    analogWrite(g, 100);
    analogWrite(b, 255);
  }
  if(LED_5 == num){  
    analogWrite(r, 255);
    analogWrite(g, 0);
    analogWrite(b, 255);
  }
  if(LED_6 == num){ 
    analogWrite(r, 255);
    analogWrite(g, 50);
    analogWrite(b, 0);
  }

}



