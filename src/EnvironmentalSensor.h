class EnvironmentalSensor {
  public:
    EnvironmentalSensor(int dataPin);
    void envUpdate();
    float getHumidity();
    float getTemper();
}

