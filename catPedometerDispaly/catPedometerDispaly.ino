#include <JY901.h>
#include <Wire.h>

unsigned long last_read_time;
float         last_x_angle;  // These are the filtered angles
float         last_y_angle;
float         last_z_angle;
float         last_gyro_x_angle;  // Store the gyro angles to compare drift
float         last_gyro_y_angle;
float         last_gyro_z_angle;

void set_last_read_angle_data(unsigned long time, float x, float y, float z, float x_gyro, float y_gyro, float z_gyro) {
  last_read_time = time;
  last_x_angle = x;
  last_y_angle = y;
  last_z_angle = z;
  last_gyro_x_angle = x_gyro;
  last_gyro_y_angle = y_gyro;
  last_gyro_z_angle = z_gyro;
}

inline unsigned long get_last_time() {
  return last_read_time;
}
inline float get_last_x_angle() {
  return last_x_angle;
}
inline float get_last_y_angle() {
  return last_y_angle;
}
inline float get_last_z_angle() {
  return last_z_angle;
}
inline float get_last_gyro_x_angle() {
  return last_gyro_x_angle;
}
inline float get_last_gyro_y_angle() {
  return last_gyro_y_angle;
}
inline float get_last_gyro_z_angle() {
  return last_gyro_z_angle;
}

//  Use the following global variables and access functions
//  to calibrate the acceleration sensor
float    base_x_accel;
float    base_y_accel;
float    base_z_accel;

float    base_x_gyro;
float    base_y_gyro;
float    base_z_gyro;

// The sensor should be motionless on a horizontal surface
//  while calibration is happening
void calibrate_sensors() {
  int                   num_readings = 10;
  float                 x_accel = 0;
  float                 y_accel = 0;
  float                 z_accel = 0;
  float                 x_gyro = 0;
  float                 y_gyro = 0;
  float                 z_gyro = 0;

  //Serial.println("Starting Calibration");

  // Discard the first set of values read from the IMU

  // Read and average the raw values from the IMU
  for (int i = 0; i < num_readings; i++) {
    x_accel += (float)JY901.stcAcc.a[0]/32768*16;
    y_accel += (float)JY901.stcAcc.a[1]/32768*16;
    z_accel += (float)JY901.stcAcc.a[2]/32768*16;
    x_gyro += (float)JY901.stcGyro.w[0]/32768*2000;
    y_gyro += (float)JY901.stcGyro.w[1]/32768*2000;
    z_gyro += (float)JY901.stcGyro.w[2]/32768*2000;
    delay(100);
  }
  x_accel /= num_readings;
  y_accel /= num_readings;
  z_accel /= num_readings;
  x_gyro /= num_readings;
  y_gyro /= num_readings;
  z_gyro /= num_readings;

  // Store the raw calibration values globally
  base_x_accel = x_accel;
  base_y_accel = y_accel;
  base_z_accel = z_accel;
  base_x_gyro = x_gyro;
  base_y_gyro = y_gyro;
  base_z_gyro = z_gyro;
}

void setup()
{

  Serial.begin(115200);

  // Initialize the 'Wire' class for the I2C-bus.
  Wire.begin();
  
  //Initialize the angles
  calibrate_sensors();
  set_last_read_angle_data(millis(), 0, 0, 0, 0, 0, 0);
}

float x, y, z;
int count = 0, prev = 0;
int threshold = 3;

char steps[5];

void loop()
{
  //开始计步
  getGyro();
  //Serial.write(10);
}

void getGyro()
{
    double dT;
    JY901.GetAcc();
    JY901.GetGyro(); 
  
    // Get the time of reading for rotation computations
    unsigned long t_now = millis();
    // Convert gyro values to degrees/sec
    float FS_SEL = 16.4;
    float gyro_x = ((float)JY901.stcGyro.w[0]/32768*2000 - base_x_gyro) / FS_SEL;
    float gyro_y = ((float)JY901.stcGyro.w[1]/32768*2000 - base_y_gyro) / FS_SEL;
    float gyro_z = ((float)JY901.stcGyro.w[2]/32768*2000 - base_z_gyro) / FS_SEL;
  
  
    // Get raw acceleration values
    //float G_CONVERT = 16384;
    float accel_x = (float)JY901.stcAcc.a[0]/32768*16;
    float accel_y = (float)JY901.stcAcc.a[1]/32768*16;
    float accel_z = (float)JY901.stcAcc.a[2]/32768*16;
  
    // Get angle values from accelerometer
    float RADIANS_TO_DEGREES = 180 / 3.14159;
    //float accel_vector_length = sqrt(pow(accel_x,2) + pow(accel_y,2) + pow(accel_z,2));
    float accel_angle_y = atan(-1 * accel_x / sqrt(pow(accel_y, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
    float accel_angle_x = atan(accel_y / sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
  
    float accel_angle_z = atan(sqrt(pow(accel_x, 2) + pow(accel_y, 2)) / accel_z) * RADIANS_TO_DEGREES;;
    //float accel_angle_z = 0;
  
    // Compute the (filtered) gyro angles
    float dt = 0.02;
    float gyro_angle_x = gyro_x * dt + get_last_x_angle();
    float gyro_angle_y = gyro_y * dt + get_last_y_angle();
    float gyro_angle_z = gyro_z * dt + get_last_z_angle();
  
    // Compute the drifting gyro angles
    float unfiltered_gyro_angle_x = gyro_x * dt + get_last_gyro_x_angle();
    float unfiltered_gyro_angle_y = gyro_y * dt + get_last_gyro_y_angle();
    float unfiltered_gyro_angle_z = gyro_z * dt + get_last_gyro_z_angle();
  
    // Apply the complementary filter to figure out the change in angle - choice of alpha is
    // estimated now.  Alpha depends on the sampling rate...
    float alpha = 0.96;
    float angle_x = alpha * gyro_angle_x + (1.0 - alpha) * accel_angle_x;
    float angle_y = alpha * gyro_angle_y + (1.0 - alpha) * accel_angle_y;
    float angle_z = gyro_angle_z;  //Accelerometer doesn't give z-angle
  
    // Update the saved data with the latest values
    set_last_read_angle_data(t_now, angle_x, angle_y, angle_z, unfiltered_gyro_angle_x, unfiltered_gyro_angle_y, unfiltered_gyro_angle_z);
  
  
    //Finding the magnitude of acceleration from the combined data from gyroscope and accelerometer.
    int mag = sqrt(pow(x - angle_x, 2) + pow(y - angle_y, 2) + pow(z - angle_z, 2));
  
    //If the magnitude is greater than threshold and the previous magnitude is lesser than threshold value increase count.
    if (mag >= threshold && prev < threshold)
    {
      count += 1;
    }
      Serial.print("steps= ");
      Serial.println(count);
      //Serial.println(gyro_x);
  
    prev = mag;
    x = angle_x;
    y = angle_y;
    z = angle_z;

}
