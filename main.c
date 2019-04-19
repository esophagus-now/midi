#include "midi.h"
#include <stdio.h>
#include <string.h>

int main() {
	MIDI *m = midi_open("cotb.mid");
	int i = 0;
	if (m != NULL) {
		printf("Format = %d\n", m->format);
		while (1) {
			printf("================Time = %d================\n", i++);
			int tmp = step_ticks(m, 1);
			if (tmp < 0) {
				puts("An error occurred while stepping through the MIDI file");
				break;
			} else if (tmp == 0) {
				puts("File finished reading succesfully");
				break;
			}
		}
	} else {
		puts("MIDI file not read");
	}
	midi_close(m);
	return 0;
}
