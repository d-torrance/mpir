#
# Regular cron jobs for the mpir package
#
0 4	* * *	root	[ -x /usr/bin/mpir_maintenance ] && /usr/bin/mpir_maintenance
