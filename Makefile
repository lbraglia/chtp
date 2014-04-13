publish:
	cd src && lftp -e "open lbraglia.openedhost.com && \
	cd chtp/ && \
	mput * && \
	exit"

publish_webpage:
	lftp -e "open lbraglia.openedhost.com && \
	put www/index.php -o chtp/index.php && \
        exit"

save:
	git commit -a
	git push 
