#!/bin/bash

cp /etc/crontab /root/to_check
diff /root/past_cron /root/to_check > /dev/null 2>&1
if [ $? = 1 ]
then
	cat to_check | mail -s "diff found in crontab" root@localhost
fi
mv /root/to_check /root/past_cron
