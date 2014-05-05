/*This is my kernel :D*/

/*	DEFINE		*/
#define WHITE_TXT 0x07	//white on black
#define RED_TXT 0x04	//red on black

/*	PROTOTYPES	*/
void printk(char*);
void printerrk(char*);
void printscreen(char*, int);


/*	IMPLEMENTATIONS	*/
int kmain(void* mbd, unsigned int magic_no)
{
	if (magic_no != 0x2BADB002)
	{
		printerrk("ERROR: BAD BOOT");
	}
	else
	{
		printk("Hello Kernel World!");	
	}
	return 0;
}

void printscreen(char* msg, int color)
{
	char* vidmem = (char *) 0xb8000;
	while (*msg != 0)
	{
		*vidmem = *msg;
		msg++;
		vidmem++;
		*vidmem = (char *) color;
		vidmem++;
	}
}

void printk(char* msg)
{
	printscreen(msg, WHITE_TXT);
}

void printerrk(char* msg)
{
	printscreen(msg, RED_TXT);
}
