#define LF 3
#define LB 5
#define RF 6
#define RB 9

#define D1 2
#define D2 4
#define D3 7
#define D4 8
#define D5 10

#define BASE_SPEED 100

int sensor_arr[5];
int weight[5] = {-2,-1,0,1,2};
unsigned int d_ti = 0.1;
float error = 0;
float previous_error = 0;
unsigned long previous_time = 0;
float I = 0;

float Kp = 25;
float Kd = 12;
float Ki = 5;

typedef struct drive_param{
  int r_speed;
  int l_speed;
  int r_dir;
  int l_dir;
  // dir -> 1 [FRONT]
  // dir -> -1 [BACK]
} drive_param;

int mod(int a){
  if(a < 0) return -a;
  else return a;
}

void get_sensor_val(int *w){
  w[0] = digitalRead(D1);
  w[1] = digitalRead(D2);
  w[2] = digitalRead(D3);
  w[3] = digitalRead(D4);
  w[4] = digitalRead(D5);
}

drive_param pid_control(float error, float del_ti){
  drive_param m;
  static float I = 0;
  float D = (error - previous_error)/del_ti;
  I += error*del_ti;
  float control = Kp*error + Kd*D + Ki*I;
  //Serial.println(control);
  m.r_speed = BASE_SPEED - (int)control;
  m.l_speed = BASE_SPEED + (int)control;
  m.l_dir = 1;
  m.r_dir = 1;
  return m;
}

void drive_motor(drive_param a){
  int r_s = a.r_speed;
  int l_s = a.l_speed;
  //clipping
  if(r_s > 255){
    r_s = 255;
  } else if(r_s < 0){
    r_s = 0;
  }
  if(l_s > 255){
    l_s = 255;
  } else if(l_s < 0){
    l_s = 0;
  }
  
  int r_pin;
  int l_pin;
  if(a.r_dir > 0){
    r_pin = RF;
  } else {
    r_pin = RB;
  }
  if(a.l_dir > 0){
    l_pin = LF;
  } else {
    l_pin = LB;
  }
  analogWrite(r_pin,r_s);
  analogWrite(l_pin,l_s);
}

void setup() {
  //Serial.begin(9600);
  pinMode(LF,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(RF,OUTPUT);
  pinMode(RB,OUTPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);
  pinMode(D4,INPUT);
  pinMode(D5,INPUT);
}

void loop() {
  unsigned long current_time = millis();
  float del_ti = (current_time - previous_time) / 1000.0;
  previous_time = current_time;
  int weighted_sum = 0;
  int sensor_sum = 0;
  drive_param m;
  get_sensor_val(sensor_arr);
  for(int i = 0;i < 5;i++){/*
    Serial.println("....///...");
    Serial.println(sensor_arr[0]);
    Serial.println(sensor_arr[1]);
    Serial.println(sensor_arr[2]);
    Serial.println(sensor_arr[3]);
    Serial.println(sensor_arr[4]);
    Serial.println("....///...");*/
    weighted_sum += sensor_arr[i]*weight[i];
    sensor_sum += sensor_arr[i];
  }
  if(sensor_sum != 0){
    error = (float)weighted_sum/sensor_sum;
  }else{
    error = previous_error;
  }
  m = pid_control(error,del_ti);
  drive_motor(m);
  //Serial.println(error);
  //delay(1000);
}
