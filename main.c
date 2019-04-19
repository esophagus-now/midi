#include "midi.h"
#include <stdio.h>
#include <string.h>

int main() {
	MIDI *m = midi_open("cotb.mid");
	if (m != NULL) printf("Format = %d\n", m->format);
	getEvent(m, NULL);
	midi_close(m);
	puts("done");
	return 0;
}
