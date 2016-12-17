#include<Wire.h>
const int numReadings = 10;

const int MPU_addr=0x68;  // I2C address of the MPU-6050

int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
//  for(int thisReading = 0; thisReading < numReadings; thisReading++){
//    readings[thisReading] = 0;
//    }
//  Serial.setTimeout(3);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
//  Serial.print("AcX = "); 
  Serial.print(AcX);
  Serial.print(",");
//  Serial.print("AcY = "); 
  Serial.print(AcY);
  Serial.print(",");
//  Serial.print("AcZ = "); 
//total = total - readings[readIndex];
//readings[readIndex] = AcZ;
//total = total + readings[readIndex];
//readIndex = readIndex + 1;
//
//if(readIndex >=numReadings){
//  readIndex = 0;
//  }
//
//average = total / numReadings;
    Serial.print(AcZ);
    Serial.println(",");
//    delay(20);
}

