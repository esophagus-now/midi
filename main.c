#include "midi.h"
#include <stdio.h>
#include <string.h>

void printEvent(MIDI_ev *ev) {
	printf("Event type = %s\n", event_names[ev->type]);
	if (ev->type == NOTE_ON || ev->type == NOTE_OFF) {
		printf("\tkey = %u, vel = %u\n", +ev->data[0] & 0xFF, + ev->data[1] & 0xFF);
	}
}

int main() {
	MIDI *m = midi_open("we3kings.mid");
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
			
			MIDI_ev *ev;
			while (getEvent(m, &ev)) {
				printEvent(ev);
			}
		}
	} else {
		puts("MIDI file not read");
	}
	midi_close(m);
	return 0;
}
