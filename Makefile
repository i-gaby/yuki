bot: bot.c
	cc bot.c -o yuki -pthread -ldiscord -lcurl
	echo "se deus quiser funciona"

clean:
	rm -f yuki
