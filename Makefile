publish: 
	lftp -f ftp_script

save:
	git commit
	git push
