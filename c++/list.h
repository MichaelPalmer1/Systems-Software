typedef struct list_s {
	struct list_s *prev;
	int data;
	struct list_s *next;
} list_t;
