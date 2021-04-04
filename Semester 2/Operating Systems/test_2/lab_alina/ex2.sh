for i in /mnt/floppy/*; do
       if [ -f $i ]; then
       # if the file is there
              filename=${i#/mnt/floppy/}
              echo copying $i to /etc/$filename
              cp -p $i /etc/$filename
       fi
 done
