import { world } from "mojang-minecraft";

world.events.beforeChat.subscribe((event) => {
	const player = event.sender;
	player.runCommand(
		`say Olá, ${player.name}! Você digitou: ${event.message}`
	);
});
