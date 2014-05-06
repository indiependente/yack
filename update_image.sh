#!/bin/bash

sudo losetup /dev/loop0 bochs/floppy.img
sudo mount /dev/loop0 /mnt
sudo cp bin/kernel /mnt/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
