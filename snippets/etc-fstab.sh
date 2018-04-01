# /etc/fstab: static file system information.
#
# Use 'blkid' to print the universally unique identifier for a
# device; this may be used with UUID= as a more robust way to name devices
# that works even if disks are added and removed. See fstab(5).
#
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
# / was on /dev/sdb1 during installation
UUID=34792723-ad14-4fe0-8a06-0ae7c19eaafd /               ext4    errors=remount-ro 0       1
UUID=68cfdf73-0b79-4dfc-ac1e-549da5cd5183 /home/tzx/disk/sda2 ext4    errors=remount-ro 0       1
UUID=753fe766-edc4-4a44-999a-7125f32f31a3 /home/tzx/disk/sda3 ext4    errors=remount-ro 0       1
