#ifndef MIC_H
#define MIC_H

#include <stdbool.h>
#include <stdint.h>

typedef void (*mix_handler)(int16_t *);

/**
 * @brief Initialize the Microphone
 *
 * Initializes the Microphone
 *
 * @return 0 if successful, negative errno code if error
 */
int mic_start();
void set_mic_callback(mix_handler _callback);

void mic_off();
void mic_on();
void mic_pause();
void mic_resume();
bool mic_is_running();
void mic_set_gain(uint8_t gain_level);

/* True while the mic is in hardware AAD sleep (mic off, waiting for sound).
 * Lets other subsystems (e.g. the status LED) drop to their lowest-power state. */
bool mic_in_aad_sleep(void);
/* Tap markers (ejtazylemons fork): write a 200 ms two-tone marker over the next mic samples.
 * mic_mark takes the two phase increments (f * 2^32 / 16000); a new mark restarts the fill.
 * mic_mark_tap: 1160 Hz + 1700 Hz (single tap). mic_mark_double: 1400 Hz + 2000 Hz (double tap). */
void mic_mark(uint32_t inc1, uint32_t inc2);
void mic_mark_tap(void);
void mic_mark_double(void);
#endif
