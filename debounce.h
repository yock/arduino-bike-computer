volatile unsigned long currentTrigger = 0;
volatile unsigned long lastTrigger = 0;
const int triggerDelay = 10;

/*
 * Gets called for each interrupt to filter out duplicate triggers.
 */
void debounce() {
  currentTrigger = millis();
  if (currentTrigger - lastTrigger > triggerDelay) {
    lastTrigger = currentTrigger;
    
  }
}
