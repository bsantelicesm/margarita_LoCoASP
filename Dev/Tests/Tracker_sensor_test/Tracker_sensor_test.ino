// ------------------------------------------------------------------------------------------------------------------
//      __  ___                            _ __              __          ______      ___   _____ ____ 
//     /  |/  /___ __________ _____ ______(_) /_____ _      / /   ____  / ____/___  /   | / ___// __ \
//    / /|_/ / __ `/ ___/ __ `/ __ `/ ___/ / __/ __ `/_____/ /   / __ \/ /   / __ \/ /| | \__ \/ /_/ /
//   / /  / / /_/ / /  / /_/ / /_/ / /  / / /_/ /_/ /_____/ /___/ /_/ / /___/ /_/ / ___ |___/ / _, _/ 
//  /_/  /_/\__,_/_/   \__, /\__,_/_/  /_/\__/\__,_/     /_____/\____/\____/\____/_/  |_/____/_/ |_|  
//                    /____/                                                                          
// ------------------------------------------------------------------------------------------------------------------
// Second Generation Low-Cost Automatic Sun Photometer for scale-oriented measurements of Aerosol Optical Depth (AOD)
// Space and Planetary Exploration Laboratory, Faculty of Physical and Matemathical Sciences, University of Chile
// ------------------------------------------------------------------------------------------------------------------
// First generation developement by Cristobal Garrido and MCI Electronics
// Second generation developement by Benjamín Santelices, Vicente Aitken, José Ferrada and Matías Vidal
// ------------------------------------------------------------------------------------------------------------------
// Tracker_sensor_test.ino > Photometer Instrument Unit
// Firmware for Tracker Unit - Arduino Uno / ESP32

void setup() {
    delay(1500);
    Serial.begin(115200);
}

void loop() {
    read_sensors();
    delay(200);
}

void read_sensors() {
    char buff[200];
    int comb01 = 0, comb32 = 0, comb03 = 0, comb12 = 0;
    int sensor0 = 0, sensor1 = 0, sensor2 = 0, sensor3 = 0;
    int suma = 0;
    memset(&buff[0], 0, sizeof(buff));
    sensor0 = analogRead(A0);
    delay(1);
    sensor1 = analogRead(A1);
    delay(1);
    sensor2 = analogRead(A2);
    delay(1);
    sensor3 = analogRead(A3);
    delay(1);
    suma = sensor0 + sensor1 + sensor2 + sensor3;
    comb01 = sensor0 + sensor1;
    comb32 = sensor3 + sensor2;
    comb03 = sensor0 + sensor3;
    comb12 = sensor1 + sensor2;
    sprintf(buff, "Sensor 0: %d, Sensor 1: %d, Sensor 2: %d, Sensor 3: %d, Comb. 01: %d, Comb. 32: %d, Comb. 03: %d, Comb. 12: %d",
                  sensor0, sensor1, sensor2, sensor3, comb01, comb32, comb03, comb12);
    Serial.println(buff);
}
