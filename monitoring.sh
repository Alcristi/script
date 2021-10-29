#!/bin/sh
echo  "#Architecture: $(uname -a)"
echo  "#CPU physical: $(grep 'physical id' /proc/cpuinfo | uniq | wc -l) " 
echo  "#vCPU: $(grep 'processor' /proc/cpuinfo | uniq | wc -l) "
FULLRAM=$(free -m | grep "Mem.:"| awk '{print $2}')
USEDRAM=$(free -m | grep "Mem.:"| awk '{print $3}')
PERCENTRAM=$(echo "scale=2;( $USEDRAM/$FULLRAM) * 100" | bc -l)
echo  "#Memory Usage: ${USEDRAM}/${FULLRAM}MB ($PERCENTRAM)%"
FULLDISK=$(df -Bg | grep /dev/ | grep -v /boot | awk '{fd += $2} END {print fd}')
USEDISK=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} END {print ud}')
PERCENTDISK=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} {fd += $2} END {printf("%d"),ud/fd*100}')
echo "#Disk Usage: ${USEDISK}/${FULLDISK}Gb (${PERCENTDISK}%)"
echo "#CPU load : $(mpstat | grep all | awk '{printf ("%d%%"),$3 + $4 + $5}')"
echo "#Last boot: $(who -b | awk '{print $4 " " $5}')"
echo "#LVM use: $(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)"
TCP=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')
MSGTCP=$(if [ ${TCP} -eq 0 ];then echo NOT ESTABLISHED;else echo ESTABLISHED;fi)
echo "#Connexions TCP: ${TCP} ${MSGTCP}"
echo "#User log: $(who |wc -l)"
echo "#Network: IP $(hostname -I) $(ifconfig | awk '/ether/{print $2}')"
echo "#Sudo: $(grep -c 'COMMAND' /var/log/sudo/logsudo) cmd"
