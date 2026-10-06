> [!IMPORTANT]
> **Hey, thanks for stopping by. This version is no longer maintained.**
>
> I owe you an explanation, because this repo went quiet without a word, and that wasn't fair to the people who used it.
>
> **What happened:** CS2AC and CS2FOW started here as open-source projects, and I loved building them in the open. But over time, people copied the code and sold it as their own without respecting the license. Cheat developers read the detection code to see exactly what gets caught. And keeping an anti-cheat alive for every CS2 update turned into a full-time job. So I moved development to closed source, where I could protect the work and keep going. I never stopped working on it.
>
> **If you still run this version:** please know it isn't updated for current CS2 builds anymore. It can break after a game update, or quietly protect less than you'd expect.
>
> **The current CS2AC and CS2FOW** are alive and getting better every week. You can try them free for 7 days at [karola3vax.com](https://karola3vax.com). And if you have questions, want help switching, or just want to say hi, come find me on [Discord](https://discord.com/invite/gaAUsKAuqQ).
>
> Thank you to everyone who starred, tested, reported bugs and believed in this project early on. It's a big part of why it still exists.

<div align="center">

<img src="docs/cs2fow-logo.png" width="760" alt="CS2FOW">

### A server-side anti-wallhack for Counter-Strike 2 community servers.

[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-5c7cfa?style=for-the-badge)](#install)
[![License](https://img.shields.io/badge/license-MIT-2ea44f?style=for-the-badge)](LICENSE)
[![Buy Me a Coffee](https://img.shields.io/badge/Buy_Me_a_Coffee-Support_Development-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=000000)](https://buymeacoffee.com/karola3vax)

**A wallhack can't show a player your server never sent.**

</div>

## What it does

A wallhack works because your server tells every player where all the enemies are, even the ones behind walls. CS2FOW stops that. When a wall or a smoke fully hides an enemy from you, your server simply doesn't send you where they are. The cheat has nothing to draw.

The moment the enemy could actually be seen, they're sent again as normal. Players don't install anything, and it can't get anyone VAC-banned: it only runs on your server. It works on community servers you run yourself, not in Premier or Valve matchmaking.

## See it in action

<table>
<tr>
<td width="50%" align="center">
<img src="docs/ancient.gif" width="100%" alt="CS2FOW hiding players behind walls on Ancient"><br>
<strong>Ancient, A site</strong>
</td>
<td width="50%" align="center">
<img src="docs/smokeandhegrenade.gif" width="100%" alt="CS2FOW hiding players behind smoke, and an HE grenade opening a gap"><br>
<strong>Smoke, opened by an HE grenade</strong>
</td>
</tr>
<tr>
<td width="50%" align="center">
<img src="docs/cache.gif" width="100%" alt="CS2FOW on Cache A site"><br>
<strong>Cache, A site</strong>
</td>
<td width="50%" align="center">
<img src="docs/dust2b.gif" width="100%" alt="CS2FOW on Dust II B site"><br>
<strong>Dust II, B site</strong>
</td>
</tr>
<tr>
<td width="50%" align="center">
<img src="docs/dust2long.gif" width="100%" alt="CS2FOW on Dust II long"><br>
<strong>Dust II, Long</strong>
</td>
<td width="50%" align="center">
<img src="docs/mirageaside.gif" width="100%" alt="CS2FOW on Mirage A site"><br>
<strong>Mirage, A site</strong>
</td>
</tr>
</table>

## What it protects

- **Walls:** enemies fully hidden behind walls aren't sent to you.
- **Smoke:** a smoke hides enemies too, and an HE grenade can briefly open a gap through it, just like in the game.
- **Their gear:** the hidden player's weapons and gloves are held back with them.
- **Fairness first:** if CS2FOW is ever unsure, it shows the player. It would rather show too much than hide someone who should be visible.

**What stays the same:** you can still wallbang a hidden enemy, footsteps and gunshots still play, and the bomb, dropped weapons, grenades and fire stay visible. Teammates, spectators and dead players always see everything. Doors and breakable objects don't block sight yet.

No tool stops every kind of cheating. CS2FOW removes what wallhacks need most: the live position of enemies you can't see.

## Install

You need a Windows or Linux CS2 dedicated server with [Metamod:Source](https://www.sourcemm.net/) 2.x installed, on a CPU with AVX support (almost every modern CPU has it).

1. Download the Windows or Linux package from the **Releases** tab.
2. Unzip it into your server's `game/csgo` folder. It starts with the `addons`, `cfg` and `tools` folders, so everything lands in the right place.
3. Start the server and load a map.
4. Type `cs2fow_status` in the server console to check it's running.

**The first time a map loads,** CS2FOW makes a quick 3D copy of its walls (a "bake"). Everyone stays visible until it's ready. Custom and Workshop maps work too.

This legacy version doesn't receive updates anymore. After a CS2 update it may switch itself off rather than risk hiding the wrong player.

## Settings you may want to change

Everything lives in `cfg/cs2fow.cfg`, and every option is explained there. After a change, type `cs2fow_reload`. Keep the last line of that file (`cs2fow_config_loaded`) where it is.

| Setting | What it does |
| --- | --- |
| `cs2fow_enable` | Turns CS2FOW on (`1`) or off (`0`). |
| `cs2fow_smoke_occlusion` | Lets smoke hide enemies too. |
| `cs2fow_he_clear_seconds` | How long an HE grenade's gap through smoke lasts. `0` turns it off. |
| `cs2fow_filter_teammates` | Also hide teammates behind walls (off by default). Free-for-all modes are handled automatically. |
| `cs2fow_visibility_hold_ms` | Keeps a player visible for about a second after they were seen, so they don't flicker. |

## Useful console commands

| Command | What it does |
| --- | --- |
| `cs2fow_status` | Shows whether everything is working, in short. |
| `cs2fow_reload` | Reloads the settings file. |
| `cs2fow_check_config` | Points out settings that need attention. |
| `cs2fow_metrics` | Shows detailed performance numbers. |

## If something's wrong

- **Status says AVX is missing:** your server's CPU (or its virtual machine) doesn't offer AVX. Ask your host to enable it.
- **The map bake fails on Linux with "permission denied":** run `chmod +x game/csgo/tools/cs2fow_baker` and `chmod +x game/csgo/tools/vrf/linux64/Source2Viewer-CLI`.
- **Status says the server program doesn't match:** CS2 has updated and this legacy version doesn't know the new game files. It stays off on purpose.

## Works well with CS2AC

<div align="center">

<a href="https://github.com/karola3vax/CS2AC">
<img src="docs/cs2ac-logo.png" width="760" alt="CS2AC">
</a>

**CS2FOW hides what you can't see. CS2AC catches cheating behavior.** Both run only on your server and work side by side.

</div>

## Support

If CS2FOW helped your server, you can support my work at [buymeacoffee.com/karola3vax](https://buymeacoffee.com/karola3vax).

## License

This legacy version is open source under the [MIT license](LICENSE). Map files it generates come from Counter-Strike 2 game data; see [DATA_NOTICE](DATA_NOTICE). Libraries it uses keep their own licenses; see [third-party notices](THIRD_PARTY_NOTICES).
