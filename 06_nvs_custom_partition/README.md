# NVS Custom Partition

This project is a very simples example of how to use custom partitions

## Steps

1. Copy the file partitions_singleapp.csv from components\partition_table in the IDF folder;
2. Add line: my_nvs,   data, nvs,     ,        1M,
3. Open IDF prompt and cd to this project folder, in my case was: C:\Espressif\frameworks\esp-idf-v5.2.1>cd C:\Users\Daniel\w\esp32\06_nvs_custom_partition\
4. idf.py menuconfig
5. Go to Partition Table
6. Select Custom partition table
7. If necessary, go to flash config and change size to 4 MB.


