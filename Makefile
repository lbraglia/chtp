chtp_publish_old: 
	lftp -f ftp_script

chtp_publish:
	lftp -e "open bragliozzo@bragliozzo.altervista.org && \
	cd CHTP5/ && \
	mput ??_?? ??_??.c && \
	exit"


chtp_save:
	git commit 
	git push 
