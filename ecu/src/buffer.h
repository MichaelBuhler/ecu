#ifndef CHAR_BUFFER_H
#define CHAR_BUFFER_H

typedef struct char_buffer_t {
	unsigned char head;
	unsigned char tail;
	char char_array[256];
} char_buffer_t;

void char_buffer_init (char_buffer_t*);
void char_buffer_write (char_buffer_t*, char);
void char_buffer_write (char_buffer_t*, char*);
char char_buffer_peek (char_buffer_t*);
char char_buffer_read (char_buffer_t*);

#endif