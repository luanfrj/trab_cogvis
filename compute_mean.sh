#!/usr/bin/env sh

OUTPUT=databases/
DATA=data_training/
# modificar para a pasta do caffe
TOOLS=/home/luan/cognicaovisual/caffe/build/tools

# a média é usada para o treinamento da rede
echo "Computando média"
$TOOLS/compute_image_mean $OUTPUT/base_train_lmdb \
  $OUTPUT/base_mean.binaryproto

echo "Pronto."
