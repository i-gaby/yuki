#include <string.h>
#include <concord/discord.h>
#include <concord/log.h>

void on_ready(struct discord *client, const struct discord_ready *event) {
	log_info("Logged in as %s!", event->user->username);
}

void on_message(struct discord *client, const struct discord_message *msg){
	if(msg->author->bot) return;

	if(strcmp(msg->content, "!ping") == 0) {
		struct discord_create_message params = { .content = "pong!" };
		discord_create_message(client, msg->channel_id, &params, NULL);
	}

	if(strcmp(msg->content, "!info") == 0) {
		struct discord_create_message params = { .content = "fui feita em C porque sim!" };
		discord_create_message(client, msg->channel_id, &params, NULL);
	}
}

int main(void) {
	struct discord *client = discord_config_init("config.json");

	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);
	discord_set_on_ready(client, &on_ready);
	discord_set_on_message_create(client, &on_message);

	discord_run(client);			// bloqueia e roda em loop
	discord_cleanup(client);
}
