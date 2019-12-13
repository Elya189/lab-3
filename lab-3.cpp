#include <stdio.h>
#include <windows.h>
#include <wincon.h>

int  main()
{
	char buffer[100];
                   char fname[]="res.txt";
	DWORD actlen;
	HANDLE fhandle, hstdout;
	BOOL lock;
	COORD coords; 
	
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	coords.X=20; coords.Y=10;
	SetConsoleCursorPosition(hstdout, coords); 
	SetConsoleTextAttribute(hstdout,  FOREGROUND_BLUE); 
	do{
		fhandle = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		
		if (fhandle == INVALID_HANDLE_VALUE)
		{
			SetConsoleCursorPosition(hstdout, coords);
			printf("Cannot open file or locked by another\n");
			fflush(stdout);  
			getchar();
		}
	}
	while(fhandle == INVALID_HANDLE_VALUE); 
	
	SetConsoleCursorPosition(hstdout, coords); 
	printf("Lock is set"); 
	getchar(); 
	SetConsoleCursorPosition(hstdout, coords);
	ReadFile(fhandle, buffer, 100, &actlen, NULL);
	WriteFile(hstdout, buffer, actlen, &actlen, NULL); 
	UnlockFile(fhandle, 0, 0, 0, 0);
	CloseHandle(fhandle); 
}