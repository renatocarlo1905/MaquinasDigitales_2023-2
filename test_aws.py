#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb  7 13:30:09 2023

@author: carlorenato
"""

# %% importar bibliotecas
import boto3
import awswrangler as wr

# %% Crear cliente
s3 = boto3.client('s3')

# %% Enlista buckets
response = s3.list_buckets()

# %% Leer algo de una base 
df = wr.s3.read_json(path='s3://embebed-cloud-iot-firehose-stream/2022/11/15/20/axolote_iot_devices_embebed_cloud-2-2022-11-15-20-22-53-3008dfc1-257a-41a7-9889-f7e3d7f150a5.gz',
                     compression = 'gzip',
                     lines=True)



