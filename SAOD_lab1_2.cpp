#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <string.h>

int read_file(const char filename[], const char outputfilename[]) {
	FILE* f = 0;
	FILE* f_output = 0;

	char buf[1000] = { 0 };
	int length = 0;
	if (fopen_s(&f, filename, "r") != 0)
		return -1;
	if (fopen_s(&f_output, outputfilename, "w") != 0)
		return -1;

	while (feof(f) == 0) {
		fgets(buf, 1000, f);
		length = strlen(buf);
		if (buf[0] <= 'z' && buf[0] >= 'a')
			buf[0] -= 32;

		for (int i = 0; i < length - 1; i++) {
			if (not(buf[i] == ' ' && buf[i] == buf[i + 1])) {
				fprintf(f_output, "%c", buf[i]);
			}
			else printf_s("error ");
		}
		fprintf(f_output, "%c", buf[length - 1]);

	}

	fclose(f);
	fclose(f_output);
	return 0;
}
int main() {
	read_file("file.txt", "new_file.txt");
	return 0;
}