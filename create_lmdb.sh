#!/usr/bin/env sh

# Convert as imagens para o padrão lmdb a ser lido pelo caffe

OUTPUT=databases/
DATA=data_training/

# modificar para a pasta do caffe
TOOLS=/home/luan/cognicaovisual/caffe/build/tools

# TRAIN_DATA_ROOT=/path/to/imagenet/train/
# VAL_DATA_ROOT=/path/to/imagenet/val/

RESIZE_HEIGHT=0
RESIZE_WIDTH=0

if [ ! -d "$DATA" ]; then
  echo "Erro: DATA não é um caminho para: $DATA"
  exit 1
fi

echo "Criando a base de treino..."

GLOG_logtostderr=1 $TOOLS/convert_imageset \
    --resize_height=$RESIZE_HEIGHT \
    --resize_width=$RESIZE_WIDTH \
    --shuffle \
    $DATA \
    $DATA/train.txt \
    $OUTPUT/base_train_lmdb

echo "Criando a base de validação..."

GLOG_logtostderr=1 $TOOLS/convert_imageset \
    --resize_height=$RESIZE_HEIGHT \
    --resize_width=$RESIZE_WIDTH \
    --shuffle \
    $DATA \
    $DATA/val.txt \
    $OUTPUT/base_val_lmdb

echo "Pronto."
