Trabalho de Cognição Visual 2016/1
==================================

### Dependências
Para instalar as dependências da CAFFE para o Ubuntu 12.04 é preciso executar:
	
	sudo sh install_deps.sh

### Caffe
A caffe pode ser obtida com:
	
	clone https://github.com/BVLC/caffe.git

Mais instruções sobre a compilação em: http://caffe.berkeleyvision.org/installation.html#compilation

### Dataset
O dataset de placas foi obtido de:

http://benchmark.ini.rub.de/?section=gtsrb&subsection=dataset

### Testando o caffe para classificação
Para testar um exemplo do caffe com uma rede pré treinada. Primeiro é preciso instalar o yaml:

	sudo apt-get install python-yaml

Depois na pasta do caffe executar o script:

	./scripts/download_model_binary.py models/bvlc_reference_caffenet

Depois é necessário o arquivo com os labels, obtidos com o comando:

	./data/ilsvrc12/get_ilsvrc_aux.sh

Depois o comando:

	./build/examples/cpp_classification/classification.bin models/bvlc_reference_caffenet/deploy.prototxt models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel data/ilsvrc12/imagenet_mean.binaryproto data/ilsvrc12/synset_words.txt examples/images/cat.jpg

A saída será como:

	---------- Prediction for examples/images/cat.jpg ----------
	0.3134 - "n02123045 tabby, tabby cat"
	0.2380 - "n02123159 tiger cat"
	0.1235 - "n02124075 Egyptian cat"
	0.1003 - "n02119022 red fox, Vulpes vulpes"
	0.0715 - "n02127052 lynx, catamount"

### Preparando a base de dados
Antes de preparar as imagens que serão usadas, para o tal foi criado um programa (convert_data.c) que faz isso
sendo necessário apenas passar como parâmetro o caminho com o diretório das imagens e o de destino.

Após isso é preciso executar o script create_lmdb.sh:

	sh create_lmdb.sh
	
Esse script converte as imagens para uma base de dados LMDB compatível com o CAFFE. São geradas as bases de treino e validação.

Depois deve-se executar o script compute_mean.sh para computar a média das imagens.

### Treinando a rede
Executa-se o scrip treinar.sh, para treinar a rede:

	sh treinar.sh
	
Os arquivos na pasta model devem ser ajustados para se obter a resposta desejada.
