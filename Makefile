publish:
	cd main && lftp -e "open lbraglia.openedhost.com && \
	cd chtp/ && \
	mput * && \
	exit"


save:
	git commit 
	git push 
