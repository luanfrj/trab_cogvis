#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	// nomes dos arquivos
	char *dir_base, *output_dir, filename[64], *image_name_base, linha[64], input_image[128], output_image[128], comando[256];
	char val_name[64], train_name[64];
	int num_classes = 43;
	int n, line;
	
	FILE *train;
	FILE *val;

	dir_base = argv[1];
	output_dir = argv[2];
	
	sprintf(train_name,"%s/train.txt",output_dir);
	sprintf(val_name,"%s/val.txt",output_dir);

	train = fopen(train_name, "w");
	val = fopen(val_name, "w");

	if (argc < 3)
	{
		printf("Use %s <input dir> <output dir>\n", argv[0]);
		return 0;
	}
	
	printf("Copiando e redimensionando imagens.\n");
	for(int i = 0; i < num_classes; i++)
	{
		n = sprintf(filename,"%s/%05d/GT-%05d.csv",dir_base,i,i);
		FILE *f = fopen(filename, "r");
		line = 0;
		fscanf(f,"%s\n",linha);
		while (!feof(f))
		{
			if(line>0)
			{
				fscanf(f,"%s\n",linha);
				image_name_base = strtok(linha,".");
				sprintf(input_image,"%s/%05d/%s.ppm",dir_base,i,image_name_base);
				sprintf(output_image,"%s/%05d_%s.jpg",output_dir,i,image_name_base);
				sprintf(comando,"convert -resize 256x256\\! %s %s",input_image, output_image);
				system(comando);

				// 90% para treino e 10% para validação
				if ((rand() % 100) <= 90)
					fprintf(train,"%05d_%s.jpg %d\n",i,image_name_base,i);
				else
					fprintf(val,"%05d_%s.jpg %d\n",i,image_name_base,i);


			}
			line++;
		}
		fclose(f);
	}
	
	printf("Fim do processo.\n");

	fclose(train);
	fclose(val);

}
