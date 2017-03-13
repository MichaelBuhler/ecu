#include "char_buffer.h"

void char_buffer_init (char_buffer_t *buffer) {
	buffer->head = 0;
	buffer->tail = 0;
	for ( unsigned short i = 0 ; i < 256 ; i++ ) {
		(buffer->char_array)[i] = 0;
	}
}

void char_buffer_write (char_buffer_t *buffer, char c) {
	(buffer->char_array)[buffer->tail] = c;
	(buffer->tail)++;
}

void char_buffer_writeln (char_buffer_t *buffer, char *c) {
	while (*c) {
		char_buffer_write(buffer, *c);
		c++;
	}
}

char char_buffer_peek (char_buffer_t *buffer) {
	return (buffer->char_array)[buffer->head];
}

char char_buffer_read (char_buffer_t *buffer) {
	if (buffer->head < buffer->tail) {
		char c = (buffer->char_array)[buffer->head];
		(buffer->char_array)[buffer->head] = 0;
		(buffer->head)++;
		return c;
	}
	return 0;
}
