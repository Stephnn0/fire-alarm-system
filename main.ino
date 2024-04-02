float temp;
float vout;  // output temperature sensor
float vout1; // when tmp increases
int LED = 13;
int gasSensor;
int peizo = 7; // ALARM

void setup()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(peizo, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    vout = analogRead(A1);
    vout1 = (vout / 1023) * 5000;
    temp = (vout1 - 500) / 10;
    gasSensor = analogRead(A0);

    if (temp >= 80)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }

    if (gasSensor >= 1000)
    {
        digitalWrite(peizo, HIGH);
    }
    else
    {
        digitalWrite(peizo, LOW);
    }
    Serial.print("Degrees: ");
    Serial.print(" ");
    Serial.print(temp);
    Serial.print("\t");

    Serial.print("Sensor: ");
    Serial.print(" ");
    Serial.print(gasSensor);
    Serial.print("\t");
    Serial.println();

    delay(1000);
}