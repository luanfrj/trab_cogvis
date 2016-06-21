#!/usr/bin/env sh

MODEL=model/
# modificar para a pasta do caffe
#TOOLS=/home/luan/cognicaovisual/caffe/build/tools

# o parametro -weights que determina que a rede usará os pesos 
# da rede pré treinada
caffe train -solver $MODEL/solver.prototxt -weights $MODEL/nin_imagenet_conv2.caffemodel -gpu 0

# Para treinar usando a GPU comente a linha de cima e descomente a próxima.
# $TOOLS/caffe train -solver $MODEL/solver.prototxt -weights $MODEL/bvlc_reference_caffenet.caffemodel -gpu 0
