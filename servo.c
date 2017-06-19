#include <stdlib.h>
#include <unistd.h>
#include "mraa/pwm.h"

int main(int argc, char **argv) {
	mraa_pwm_context pwm;
  pwm = mraa_pwm_init(3);
  if (pwm == NULL) {
    return 1;
  }
  mraa_pwm_period_ms(pwm, 20);
  mraa_pwm_enable(pwm, 1);
  float value = 0.0f;
  while (1) {
    value = value + 0.01f;
    mraa_pwm_write(pwm, value);
    sleep(5);
    if (value >= 1.0f) {
      value = 0.0f;
    }
    float output = mraa_pwm_read(pwm);
    printf("PWM value is %f\n", output);
  }
	return 0;
}