void comet() {
    for (int j = 0; j < NUMPIXELS; j++) {
        for (int i = 0 ; i < NUMPIXELS; i++) {
            if (i < j) {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            } else {
                pixels.setPixelColor(i, pixels.Color(
                        LED_DNA.colors[3*i]*2,
                        LED_DNA.colors[3*i+1]*2,
                        LED_DNA.colors[3*i+2]*2));
            }
        }


        if (LED_DNA.rotate) dna_rotate_LEDs();
        delay(LED_DNA.delay_time);
        pixels.show();
    }

    for (int j = 0; j < NUMPIXELS; j++) {
        for (int i = 0 ; i < NUMPIXELS; i++) {
            if (i < j) {
                pixels.setPixelColor(i, pixels.Color(
                        LED_DNA.colors[3*i]*2,
                        LED_DNA.colors[3*i+1]*2,
                        LED_DNA.colors[3*i+2]*2));
            } else {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            }
        }


        if (LED_DNA.rotate) dna_rotate_LEDs();
        delay(LED_DNA.delay_time);
        pixels.show();
    }
}

void one_two_blink() {
    for(int i = 0; i < NUMPIXELS; i++){
        if (i%2 == 0) {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        } else {
            pixels.setPixelColor(i, pixels.Color(
                LED_DNA.colors[3*i],
                LED_DNA.colors[3*i+1],
                LED_DNA.colors[3*i+2]));
        }
    }

    if (LED_DNA.rotate == 2) dna_rotate_LEDs();

    delay(LED_DNA.delay_time);
    pixels.show();

    for(int i = 0; i < NUMPIXELS; i++){
        if (i%2 == 0) {

            pixels.setPixelColor(i, pixels.Color(
                LED_DNA.colors[3*i],
                LED_DNA.colors[3*i+1],
                LED_DNA.colors[3*i+2]));
        } else {

            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
    }

    if (LED_DNA.rotate == 2) dna_rotate_LEDs();

    delay(LED_DNA.delay_time);
    pixels.show();
}

void single_blink() {
    for (int t = 0; t < NUMPIXELS; t++) {
        for (int i = 0; i < NUMPIXELS; i++) {
            if (i == t) {
                pixels.setPixelColor(i, pixels.Color(
                        LED_DNA.colors[3*i],
                        LED_DNA.colors[3*i+1],
                        LED_DNA.colors[3*i+2]));
            } else {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            }
        }
        delay(LED_DNA.delay_time);
        pixels.show();
    }

    for (int t = 0; t < NUMPIXELS; t++) {
        for (int i = 0; i < NUMPIXELS; i++) {
            if (i == t) {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            } else {
                pixels.setPixelColor(i, pixels.Color(
                    LED_DNA.colors[3*i],
                    LED_DNA.colors[3*i+1],
                    LED_DNA.colors[3*i+2]));
            }
        }

        delay(LED_DNA.delay_time);
        pixels.show();
    }
}


void on_off_wave() {
    for (int divisor = 1; divisor < 32; divisor+=2) {
        for (int j = 0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(
                    LED_DNA.colors[3*j]/divisor,
                    LED_DNA.colors[3*j+1]/divisor,
                    LED_DNA.colors[3*j+2]/divisor));
        }

        if (LED_DNA.rotate == 2) dna_rotate_LEDs();

        delay(LED_DNA.delay_time);
        pixels.show();
    }

    for (int divisor = 32; divisor > 1; divisor-=2) {
        for (int j = 0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(
                    LED_DNA.colors[3*j]/divisor,
                    LED_DNA.colors[3*j+1]/divisor,
                    LED_DNA.colors[3*j+2]/divisor));
        }

        if (LED_DNA.rotate == 2) dna_rotate_LEDs();

        delay(LED_DNA.delay_time);
        pixels.show();
    }
}

uint8_t t_state[15] =  {7, 7, 7, 7, 4, 3, 2, 1, 0, 1, 2, 3, 4, 7, 7};
void gaussian_wave() {
    for (int i = 0; i < NUMPIXELS; i++) {

        for (int t = 0; t < 15; t++) {
            for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
                pixels.setPixelColor(pixel, pixels.Color(
                            LED_DNA.colors[3*i]>>t_state[(t + pixel) % 15],
                            LED_DNA.colors[3*i+1]>>t_state[(t + pixel) % 15],
                            LED_DNA.colors[3*i+2]>>t_state[(t + pixel) % 15]));
            }

            delay(LED_DNA.delay_time);
            pixels.show();
        }

    }
}

void none() {
    for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(
                                    LED_DNA.colors[3*i],
                                    LED_DNA.colors[3*i+1],
                                    LED_DNA.colors[3*i+2]));
    }

    delay(LED_DNA.delay_time);
    pixels.show();
}

void dna_rotate_LEDs() {
    for (int j = 0; j < 3; j++) {

        uint8_t start = LED_DNA.colors[0];
        for (int i = 0; i < 3*NUMPIXELS; i++) {
            LED_DNA.colors[i] = LED_DNA.colors[i+1];
        }
        LED_DNA.colors[3*NUMPIXELS - 1] = start;
    }
}

void pause() {
    delay(LED_DNA.pause_time);
}

void run_DNA() {
    char *c;

    for (c = LED_DNA.pattern; *c != '\0'; c++) {
        switch (*c) {
            case '1':
                comet();
                break;
            case '2':
                on_off_wave();
                break;
            case '3':
                one_two_blink();
                break;
            case '4':
                gaussian_wave();
                break;
            case '5':
                single_blink();
                break;
            case 'R':
                dna_rotate_LEDs();
                break;
            case 'P':
                pause();
                break;
            case 'D': {
                // read and create delay time until next D
                int d = 0;
                char * d_ptr;
                for (d_ptr = c + 1; *d_ptr != 'D'; d_ptr++) {
                    d = d * 10 + ((*d_ptr) - 48);
                }
                LED_DNA.delay_time = d;
                c = d_ptr;
                break;
                }
            case ' ':
                continue;
            default:
                none();
        }
    }
}

