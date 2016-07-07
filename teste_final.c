#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

	char *diretorio;
	char comando[1000], filename[255], testimage[64];
	int class, real_class, total = 0, certas = 0, erradas = 0;
	double acuracia;
	FILE *classificador, *testlist, *saida;
	if (argc < 2)
	{
		printf("Use %s <test images dir>\n", argv[0]);
		return 0;
	}

	diretorio = argv[1];
	sprintf(filename,"%s/TEST.txt",diretorio);
	testlist = fopen(filename,"r");
	saida = fopen("resultado.txt","w");
	while(!feof(testlist))
	{
		fscanf(testlist,"%[^ ] %d\n",testimage,&real_class);
		//printf("imagem -> %s, classe -> %d\n",testimage,real_class);
		sprintf(comando,"$CAFFE_HOME/build/examples/cpp_classification/classification.bin model/rec_placas_deploy.prototxt model/nin_rec_placas_iter_40000.caffemodel databases/base_mean.binaryproto classes.csv %s",testimage);
		classificador = popen(comando,"r");
		fscanf(classificador,"%d %s\n",&class,filename);
		//printf("classe = %d\n",class);
		pclose(classificador);

		if (class == real_class) {
			certas++;
			//printf("certa\n");
			fprintf(saida,"%s; %d; %d; certa\n",testimage,real_class,class);
		} else {
			erradas++;
			//printf("errada\n");
			fprintf(saida,"%s; %d; %d; errado\n",testimage,real_class,class);
		}
		total++;
		acuracia = ((double) certas/ (double) total) * 100.0;
		printf("Acuracia = %5.3f Total = %6d\n",acuracia,total);
	}

	acuracia = ((double) certas/ (double) total) * 100.0;
	printf("C = %d; E = %d; T = %d; A = %.3f\n", certas,erradas,total,acuracia);
	fprintf(saida,"C = %d; E = %d; T = %d; A = %.3f\n", certas,erradas,total,acuracia);
	fclose(saida);
	fclose(testlist);
}
