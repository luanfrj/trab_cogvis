#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	FILE *in, *out;
	char linha[64];
	int class;

	in = fopen("data_training/train.txt.old", "r");
	out = fopen("data_training/train.txt", "w");

	while(!feof(in)) {
		fscanf(in,"%s %d\n",linha,&class);
		fprintf(out,"data_training/%s %d\n",linha,class);
	}

	fclose(in);
	fclose(out);

	in = fopen("data_training/val.txt.old", "r");
	out = fopen("data_training/val.txt", "w");

	while(!feof(in)) {
		fscanf(in,"%s %d\n",linha,&class);
		fprintf(out,"data_training/%s %d\n",linha,class);
	}
	fclose(in);
	fclose(out);

	return 0;
}
