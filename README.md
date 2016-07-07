Trabalho de Cognição Visual 2016/1
==================================

## Dependências
Para instalar as dependências da CAFFE para o Ubuntu 12.04 é preciso executar:
	
	sudo sh install_deps.sh

## Caffe
A caffe pode ser obtida com:
	
	clone https://github.com/BVLC/caffe.git

Mais instruções sobre a compilação em: http://caffe.berkeleyvision.org/installation.html#compilation

## Dataset
O dataset de placas foi obtido de:

http://benchmark.ini.rub.de/?section=gtsrb&subsection=dataset

# A rede utilizada
O modelo pré-treinado utiizado foi o nin-imagenet.

## Preparando a base de dados
Antes de preparar as imagens que serão usadas, para o tal foi criado um programa (convert_data.c) que faz isso
sendo necessário apenas passar como parâmetro o caminho com o diretório das imagens e o de destino.


### Treinando a rede
Executa-se o scrip treinar.sh, para treinar a rede:

	sh treinar.sh
	
Os arquivos na pasta model devem ser ajustados para se obter a resposta desejada.

## Testando a rede para classificação
Para testar um exemplo de imagem com o modelo treinado é preciso apenas seguir os passos a seguir:

Depois o comando:

	$CAFFE_HOME/build/examples/cpp_classification/classification.bin model/rec_placas_deploy.prototxt model/nin_rec_placas_iter_40000.caffemodel databases/base_mean.binaryproto classes.csv 00028.jpg

Obs: é necessário que a CAFFE_HOME aponte para o diretório onde está instalado o caffe.

A saída será como:

	---------- Prediction for 00028.jpg ----------
	0.7929 - "9 "PROIBIDO ULTRAPASSAR""
	0.2069 - "10 "PROIBIDO ULTRAPASSAGEM PARA CAMINHÕES""
	0.0001 - "16 "TRÂNSITO PROIBIDO A AUTOMÓVEIS DE MERCADORIAS""
	0.0000 - "5 "LIMITE 80 km/h""
	0.0000 - "20 "CURVA À DIREITA""


