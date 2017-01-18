#!/bin/sh

READFILE="./readfile_exception.out"
#READFILE="./readfile_errno.out"

# run readfile using data1.txt, data2.txt ... data5.txt
for i in `seq 5` ; do
    # get filename
    FILENAME="data${i}.txt"
    # run readfile using filename
    echo "\n************ ${READFILE} ${FILENAME} ****************"
    ${READFILE} ${FILENAME}
    STATUS=$?
    # print exit status of readfile
    echo "************************** exit status *************************"
    if [ ${STATUS} -ne 0 ] ; then echo "FAILED" ; else echo "OK" ; fi
    # print the content of filename
    echo "*************************** ${FILENAME} **************************"
    cat ${FILENAME}
    echo "****************************************************************\n"
done

